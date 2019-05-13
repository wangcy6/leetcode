

#### [797. 所有可能的路径](https://leetcode-cn.com/problems/all-paths-from-source-to-target/)

#### 1. 描述：

给一个有 `n` 个结点的有向无环图，找到所有从 `0` 到 `n-1` 的路径并输出（不要求按顺序）

二维数组的第 i 个数组中的单元都表示有向图中 i 号结点所能到达的下一些结点（译者注：有向图是有方向的，即规定了a→b你就不能从b→a）空就是没有下一个结点了。

```
示例:
输入: [[1,2], [3], [3], []] 
输出: [[0,1,3],[0,2,3]] 
解释: 图是这样的:
0--->1
|    |
v    v
2--->3
这有两条路: 0 -> 1 -> 3 和 0 -> 2 -> 3.
```

**提示:**

- 结点的数字会在范围 `[2, 15]` 内。
- 你可以把路径以任意顺序输出，但在路径内的结点的顺序必须保证

#### 2.分析

期望：请找出其中最小的元素

- 第一次尝试: 直接遍历

  描述： 

  > 最小值和每个元素比较一遍， 

  ​             比较次数 o(n) 

​        执行用时: 28 ms, 在Find Minimum in Rotated Sorted Array的C++提交中击败了2.89% 的用户

- 第二次尝试：减少比较次数


对一个数组进行折半拆分(至少3个元素)

> 如果是升序，第一就是最小值



>  两两比较：

   [世界杯](https://baike.baidu.com/item/%E4%B8%96%E7%95%8C%E6%9D%AF/114085)一共进行64场，

   其中分[小组赛](https://baike.baidu.com/item/%E5%B0%8F%E7%BB%84%E8%B5%9B/5112557)48场，1/8决赛8场，1/4决赛4场，半决赛两场，决三、四名比赛一场，冠亚军决赛一场.

  比较  需要o(n-1) 没有减少呀！



执行用时: 4 ms, 在Find Minimum in Rotated Sorted Array的C++提交中击败了98.16% 的用户

​    ![http://zxi.mytechroad.com/blog/wp-content/uploads/2017/09/153-ep38-1.png](http://zxi.mytechroad.com/blog/wp-content/uploads/2017/09/153-ep38-1.png)![http://zxi.mytechroad.com/blog/wp-content/uploads/2017/09/153-ep38-1.png](http://zxi.mytechroad.com/blog/wp-content/uploads/2017/09/153-ep38-2.png)

#### 3. c++

```c++

/**
	Time  complexity:T(n) = O(1) + T(n/2) = O(logn)
	Space complexity:o(1)
	查找逻辑跟索引位置切分的，根数据大小没关系，数据全部相等，也没有关系
	**/
    int find_min(vector<int>&nums,int start,int end){
        
        if((end-start)<=1) 
        {
          return min(nums[start],nums[end]);    
        }
        
        if (nums[end]>nums[start]){
            return nums[start];
        }
        
        int mid=(start+end)/2;
        
        int left=find_min(nums,start,mid);
        int right=find_min(nums,mid+1,end);
        
        return min(left,right);
        
    }
	int findMin(vector<int>& nums) {
        
        return find_min(nums,0,nums.size()-1);
    }
```

#### 4. go

```go
/** 第一题 find-minimum-in-rotated-sorted-array
https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/
153. 寻找旋转排序数组中的最小值
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
请找出其中最小的元素。

期望:请找出其中最小的元素
拦路虎：
1. 如果是完全升序  第一数字就是 ，
   旋转数值是升序（相邻的元素都是递增）， 根本不知道抄那个方向移动？炸锅了。
   肯定没有那么容易赛。
2. 我想通过观察特点 怪点(2边元素都大于它)就是最小元素这个没问题，，需要至少4个元素判断 很容易越界。 i++。i--都比较复杂了
   还是回到问题1，
比较点【相邻元素】【边界元素】【变化点】都有缺陷
过程描述
随便寻找一个数字i,判断nums[i]是否为最小值
1 如果nums[i]>nums[end]，说明nums[i]不是最小元素 ，最小元素在后面 ---> i+1
2.如哦nums[i]<nums[end],nums[end]不是最小元素，后面元素比当前元素i还大，这是升序 最小元素在前面  <---- i-1
  但是最后一个元素情况下 nums[end]可能是最小元素 i（这个)
3 如果 nums[i]==nums[end] 相等的话就舍去一个呀（这个遗漏了）
4 折半查找直到循环结束，范围缩小到最后一个元素 （这个不是一般能想到的，讨巧了，时候才知道，不是通用的方法 if 判断 watch结果是否越界）

测试：
1 int{1, 2, 3, 4, 5, 6} 如果升序不需要排序 上面规则不在查找了 ok
2 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}  ok
3.{3, 3, 1, 3} 完全错误的是
缺点：
1. 通过数字的大小有关系,
 跟数字的内容有关系，需要很复杂的逻辑判断。 有点不是很好
 find-minimum-in-rotated-sorted-array-ii case3的时候我代码完全不对了
2. 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 性能o(n)




case1 寻找不到怎么办
别人的答案：
https://www.youtube.com/watch?v=P4r7mF1Jd50&t=3s
http://zxi.mytechroad.com/blog/divide-and-conquer/leetcode-153-find-minimum-in-rotated-sorted-array/
！！！！！！！！！
折半查找没有问题，但是元素比较出现了问题，无论怎么比较都不对，比较元素这个思路是错误的


**/
func findMin(nums []int) int {
	begin := 0
	end := len(nums) - 1
	mid := 0
	if nums[end] > nums[begin] {
		//fmt.Println("sort array", nums[begin])
		return nums[begin]
	}
	for begin < end {
		mid = (begin + end) / 2
		if nums[end] < nums[mid] {
			begin = mid + 1 //排除nums[mid]不是最小元素,最小元素在后面
		} else if nums[end] > nums[mid] {
			end = mid
		} else {
			end--
		}

		//fmt.Println(begin, end, mid)
	}
	return nums[begin]

}
```

