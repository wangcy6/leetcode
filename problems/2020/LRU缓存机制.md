

### 一、描述



146. LRU缓存机制



运用你所掌握的数据结构，设计和实现一个 LRU (最近最少使用) 缓存机制。

它应该支持以下操作： 获取数据 get 和 写入数据 put 。



- 获取数据 get(key) - 如果关键字 (key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。



- 写入数据 put(key, value) - 如果关键字已经存在，则变更其数据值；

​      如果关键字不存在，则插入该组「关键字/值」。

- 当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，

从而为新的数据值留出空间。



进阶:



你是否可以在 O(1) 时间复杂度内完成这两种操作？



思考 60秒 。。。



思考 60秒 。。

 



### 二、思路

#### 最迷惑地方

1. o(1) 删除一个已知节点，采用单链表还是双链表？

- 假如删除节点最开始位置，可以o(1)删除，但是插入只能从结束位置插入【单】
- 假如删除节点是结束位置，单链表删除后，是无法获取前面一个节点的【双】
- 如果删除节点位置是中间节点，需要获取前面一个节点位置。【双】

>虽然单链表节省4字节，但是操作不方便，因此需要双链表

2. 最久未使用的数据放在双链开始位置还是结束位置，好像都可以？

- 习惯上插入一个节点放到在head位置插入【new】
- 如果被放过移动head位置
- 快速查找一个元素 需要哈希表

- 双向链表+哈希表

  

3. 难道这要就可以了，还有其他要说的吗？

- http://jm.taobao.org/2011/01/18/689/
- LinkedHashMap vs ConcurrentHashMap

#### 熟悉的子问题



#### 步骤描述




### 三、代码

https://github.com/alibaba/tb_tddl/blob/master/tddl-common/src/main/java/com/taobao/tddl/common/util/ConcurrentLRUHashMap.java



~~~java
import java.io.Serializable;
import java.util.AbstractMap;
import java.util.Set;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.locks.ReentrantLock;

import com.taobao.tddl.common.exception.lru.LRUHashMapException;



/**
 * 并发最近最少使用HashMap 注意：要添加一个，一定要会删除一个，所以，总的容量是不会改变的。
 * 
 * @author xudanhui.pt Jan 19, 2011,2:59:42 PM
 */
public class ConcurrentLRUHashMap<K, V> extends AbstractMap<K, V> implements
		Serializable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1089799193141551978L;

	static final int DEFAULT_INITIAL_CAPACITY = 16;

	static final float DEFAULT_LOAD_FACTOR = 0.75f;

	static final int DEFAULT_CONCURRENCY_LEVEL = 16;

	static final int MAXIMUM_CAPACITY = 1 << 30;

	static final int MAX_SEGMENTS = 1 << 16;

	final int segmentMask;

	final int segmentShift;

	final Segment<K, V>[] segments;

	static final int RETRIES_BEFORE_LOCK = 2;

	private static int hash(int h) {
		// Spread bits to regularize both segment and index locations,
		// using variant of single-word Wang/Jenkins hash.
		h += (h << 15) ^ 0xffffcd7d;
		h ^= (h >>> 10);
		h += (h << 3);
		h ^= (h >>> 6);
		h += (h << 2) + (h << 14);
		return h ^ (h >>> 16);
	}

	final Segment<K, V> segmentFor(int hash) {
		return segments[(hash >>> segmentShift) & segmentMask];
	}

	public ConcurrentLRUHashMap(int initialCapacity, float loadFactor,
			int concurrencyLevel) {

		if (!(loadFactor > 0) || initialCapacity < 0 || concurrencyLevel <= 0)
			throw new IllegalArgumentException();

		if (concurrencyLevel > MAX_SEGMENTS)
			concurrencyLevel = MAX_SEGMENTS;

		// Find power-of-two sizes best matching arguments
		int sshift = 0;
		int ssize = 1;
		while (ssize < concurrencyLevel) {
			++sshift;
			ssize <<= 1;
		}
		segmentShift = 32 - sshift;
		segmentMask = ssize - 1;
		this.segments = Segment.newArray(ssize);

		if (initialCapacity > MAXIMUM_CAPACITY)
			initialCapacity = MAXIMUM_CAPACITY;
		int c = initialCapacity / ssize;
		if (c * ssize < initialCapacity)
			++c;
		int cap = 1;
		while (cap < c)
			cap <<= 1;
		for (int i = 0; i < this.segments.length; ++i)
			this.segments[i] = new Segment<K, V>(cap, loadFactor);
	}

	/**
	 * Hash锁分离段
	 * 
	 * @author xudanhui.pt Jan 19, 2011,3:08:09 PM
	 * @param <K>
	 * @param <V>
	 */
	static final class Segment<K, V> extends ReentrantLock implements
			Serializable {
		private static final long serialVersionUID = 1L;
		/**
		 * 阈值
		 */
		transient int threshold;
		/**
		 * 计数
		 */
		transient volatile int count;
		/**
		 * 修改标记
		 */
		transient int modCount;
		/**
		 * hash表
		 */
		transient volatile HashEntry<K, V>[] table;
		/**
		 * 段内头节点，哨兵节点。
		 */
		transient final HashEntry<K, V> header;

		Segment(int initialCapacity, float lf) {
			// 创建hash表
			table = HashEntry.<K, V> newArray(initialCapacity);
			// 计算阈值
			threshold = (int) (initialCapacity * lf);
			// 段内计数初值为0
			count = 0;
			// 构建双向链表的头节点
			header = new HashEntry(null, -1, null, null, null, null,
					new AtomicBoolean(false));
			header.linknext = header;
			header.linkpref = header;
		}

		@SuppressWarnings("unchecked")
		static final <K, V> Segment<K, V>[] newArray(int i) {
			return new Segment[i];
		}

		// 取得hash表中第一个值
		HashEntry<K, V> getFirst(int hash) {
			HashEntry<K, V>[] tab = table;
			return tab[hash & (tab.length - 1)];
		}

		// 在有锁的情况下读值
		V readValueUnderLock(HashEntry<K, V> e) {
			lock();
			try {
				return e.value;
			} finally {
				unlock();
			}
		}

		// 把节点移动到双向链表的头部
		void moveNodeToHeader(HashEntry<K, V> e) {
			lock();
			try {

				// TODO 这里需要修改一下空操作的验证
				if (!e.dead.get()) {

					// 从退化连表中断开连接
					e.linkpref.linknext = e.linknext;
					e.linknext.linkpref = e.linkpref;

					// 添加到退化链表头部
					header.linknext.linkpref = e;
					e.linknext = header.linknext;
					e.linkpref = header;
					header.linknext = e;
				}
			} finally {
				unlock();
			}

		}

		// get操作
		V get(Object key, int hash) {
			HashEntry<K, V> e = getFirst(hash);
			// 遍历查找
			while (e != null) {
				if (e.hash == hash && key.equals(e.key)) {
					V v = e.value;
					// 把节点移动到头部。
					moveNodeToHeader(e);
					if (v != null)
						return v;
					// 在锁的情况读，必定能读到。
					// tab[index] = new HashEntry<K,V>(key, hash, first, value)，
					// value赋值和tab[index]赋值可能会重新排序，重新排序之后，可能会读空值
					// 读到空值的话，在有锁的情况在再读一遍，一定能读！
					return readValueUnderLock(e); // recheck
				}
				e = e.next;
			}
			return null;
		}

		// 删除老节点
		private void removeOldNode() throws LRUHashMapException {
			lock();
			try {
				int c = count;
				// 执行删除操作。
				HashEntry<K, V> node = header.linkpref;
				if (node == null) {
					throw new LRUHashMapException("segment中的退化链表崩溃！");
				}
				if (node == header) {
					throw new LRUHashMapException("segment中退化链表已经为空！");
				}
				// 已经标记为死亡，理论上来说，不会有这样的情况。
				if (node.dead.get()) {
					throw new LRUHashMapException("node非正常死亡");
				}
				remove(node.key, node.hash, node.value);//删除节点
			} finally {
				unlock();
			}
		}

		// 插入操作
		V put(K key, int hash, V value, boolean onlyIfAbsent)
				throws LRUHashMapException {
			lock();
			try {
				int c = count;
				// 如果当前节点数量已经大于等于阈值
				if (c >= threshold) {
					removeOldNode();// 删不掉就会抛出错误，抛出错误就完了！
					c=count;
				}

				// 执行put操作！
				HashEntry<K, V>[] tab = table;
				int index = hash & (tab.length - 1);
				HashEntry<K, V> first = tab[index];
				HashEntry<K, V> e = first;
				while (e != null && (e.hash != hash || !key.equals(e.key)))
					e = e.next;
				V oldValue;

				if (e != null) {
					oldValue = e.value;
					if (!onlyIfAbsent) {
						e.value = value;
						moveNodeToHeader(e);// 移动到头部
					}
				} else {
					oldValue = null;

					++modCount;
					HashEntry<K, V> newNode = new HashEntry<K, V>(key, hash,
							first, value, header.linknext, header,
							new AtomicBoolean(false));

					header.linknext.linkpref = newNode;
					header.linknext = newNode;
					tab[index] = newNode;
					c++;
					count = c;
				}

			} finally {
				unlock();
			}
			return null;
		}

		// 删除程序
		V remove(Object key, int hash, Object value) {
			lock();
			try {
				int c = count - 1;
				HashEntry<K, V>[] tab = table;
				int index = hash & (tab.length - 1);
				HashEntry<K, V> first = tab[index];
				HashEntry<K, V> e = first;
				while (e != null && (e.hash != hash || !key.equals(e.key)))
					e = e.next;

				V oldValue = null;
				if (e != null) {
					// 把节点从Hash链表中脱离出来
					e.dead.set(true);
					// 把尾部节点从链表中删除！
					e.linkpref.linknext = e.linknext;
					e.linknext.linkpref = e.linkpref;

					// 把节点从hash槽中删除
					V v = e.value;
					if (value == null || value.equals(v)) {
						oldValue = v;
						++modCount;
						HashEntry<K, V> newFirst = e.next;
						// 循环删除
						for (HashEntry<K, V> p = first; p != e; p = p.next) {
							HashEntry<K, V> newNode = new HashEntry<K, V>(
									p.key, p.hash, newFirst, p.value,
									p.linknext, p.linkpref, new AtomicBoolean(
											false));
							// 调整链表
							p.linknext.linkpref = newNode;
							p.linkpref.linknext = newNode;
							p.dead.set(true);// 标记死亡，这个很重要！
							// 赋值
							newFirst = newNode;
						}
						tab[index] = newFirst;
						count = c; // write-volatile
					}
				}
				return oldValue;
			} finally {
				unlock();
			}
		}

	}

	/**
	 * Hash槽内链表的节点
	 * 
	 * @author xudanhui.pt Jan 19, 2011,3:04:07 PM
	 * @param <K>
	 * @param <V>
	 */
	static class HashEntry<K, V> {
		/**
		 * 键
		 */
		final K key;
		/**
		 * hash值
		 */
		final int hash;
		/**
		 * 值
		 */
		volatile V value;
		/**
		 * hash链指针
		 */
		final HashEntry<K, V> next;
		/**
		 * 双向链表的下一个节点
		 */
		HashEntry<K, V> linknext;
		/**
		 * 双向链表的下一个节点
		 */
		HashEntry<K, V> linkpref;
		/**
		 * 死亡标记
		 */
		AtomicBoolean dead;

		HashEntry(K key, int hash, HashEntry<K, V> next, V value,
				HashEntry<K, V> linknext, HashEntry<K, V> linkpref,
				AtomicBoolean dead) {
			this.key = key;
			this.hash = hash;
			this.next = next;
			this.value = value;
			this.linknext = linknext;
			this.linkpref = linkpref;
			this.dead = dead;
		}

		static final <K, V> HashEntry<K, V>[] newArray(int i) {
			return new HashEntry[i];
		}
	}

	public V putIfAbsent(K key, V value) {
		if (value == null)
			throw new NullPointerException();
		int hash = hash(key.hashCode());
		try {
			return segmentFor(hash).put(key, hash, value, true);
		} catch (LRUHashMapException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return value;
	}

	@Override
	public V put(K key, V value) {
		if (value == null)
			throw new NullPointerException();
		int hash = hash(key.hashCode());
		try {
			return segmentFor(hash).put(key, hash, value, false);
		} catch (LRUHashMapException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return value;
	}

	@Override
	public V get(Object key) {
		int hash = hash(key.hashCode());
		return segmentFor(hash).get(key, hash);
	}

	@Override
	public int size() {
		final Segment<K, V>[] segments = this.segments;
		long sum = 0;
		long check = 0;
		int[] mc = new int[segments.length];
		// Try a few times to get accurate count. On failure due to
		// continuous async changes in table, resort to locking.
		for (int k = 0; k < RETRIES_BEFORE_LOCK; ++k) {
			check = 0;
			sum = 0;
			int mcsum = 0;
			for (int i = 0; i < segments.length; ++i) {
				sum += segments[i].count;
				mcsum += mc[i] = segments[i].modCount;
			}
			if (mcsum != 0) {
				for (int i = 0; i < segments.length; ++i) {
					check += segments[i].count;
					if (mc[i] != segments[i].modCount) {
						check = -1; // force retry
						break;
					}
				}
			}
			if (check == sum)
				break;
		}
		if (check != sum) { // Resort to locking all segments
			sum = 0;
			for (int i = 0; i < segments.length; ++i)
				segments[i].lock();
			for (int i = 0; i < segments.length; ++i)
				sum += segments[i].count;
			for (int i = 0; i < segments.length; ++i)
				segments[i].unlock();
		}
		if (sum > Integer.MAX_VALUE)
			return Integer.MAX_VALUE;
		else
			return (int) sum;
	}

	public V remove(Object key) {
		int hash = hash(key.hashCode());
		return segmentFor(hash).remove(key, hash, null);
	}

	public boolean remove(Object key, Object value) {
		int hash = hash(key.hashCode());
		if (value == null)
			return false;
		return segmentFor(hash).remove(key, hash, value) != null;
	}

	@Override
	public Set<java.util.Map.Entry<K, V>> entrySet() {
		// TODO Auto-generated method stub
		return null;
	}
}
~~~





> 分享最实用的经验 ， 希望每一位来访的朋友都能有所收获！ 
>
> 如果有疑问请联系我，一起探讨，进步。

![qrcode__860.jpg](https://pic.leetcode-cn.com/74a42e000e5545422ce7e2d76e3998ef9b3a288139b03773ebb87cae128443fa-qrcode__860.jpg)

