/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的K对数字
 *
 * https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (42.68%)
 * Likes:    92
 * Dislikes: 0
 * Total Accepted:    8.2K
 * Total Submissions: 19.2K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 * 给定两个以升序排列的整形数组 nums1 和 nums2, 以及一个整数 k。
 * 
 * 定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2。
 * 
 * 找到和最小的 k 对数字 (u1,v1), (u2,v2) ... (uk,vk)。
 * 
 * 示例 1:
 * 
 * 输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * 输出: [1,2],[1,4],[1,6]
 * 解释: 返回序列中的前 3 对数：
 * ⁠    [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 * 输出: [1,1],[1,1]
 * 解释: 返回序列中的前 2 对数：
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 * 
 * 
 * 示例 3:
 * 
 * 输入: nums1 = [1,2], nums2 = [3], k = 3 
 * 输出: [1,3],[2,3]
 * 解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]
 * 
 *  阅读 https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/solution/pyhont3yi-xing-jie-fa-dao-gao-xiao-jie-fa-by-ml-zi/
 *  耗时：30分钟 
 *  结果：没看懂好像可以不全部遍历 
 * 
 * 阅读：https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/solution/cha-zhao-he-zui-xiao-de-kdui-shu-zi-by-lenn123/
 * 耗时：60分钟
 * 结果：https://leetcode-cn.com/problems/merge-k-sorted-lists/
 * 我们可以利用堆，在不枚举出全部数对的情况下解决该问题，从而提高效率
 * 
 *  我们将原问题转换成在n1个升序队列中，查找最小的前K对数字
 * 
 *  为了解决该问题，我们可以参考leetcode 23 合并K个有序链表的方法。
 *  我们统计n1个升序队列的队首元素中的最小值，将其加入结果队列，
 *  并将指向该队首的指针向后移，直到我们找齐前K对数字
   
   阅读：https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84551/simple-Java-O(KlogK)-solution-with-explanation
   耗时：30分钟
   结果：竖着看也是升序。

   测试：45分钟 cmp函数如何写，然后比较大小 的一个元素和第二个元素比较结果
    3 9 13 比较。
 * // Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution
{
public:
    //找到和最小的 k 对数字
    //Solution1 找到全部组合n*m,然后排序。
    //Solution2 利用堆，在不枚举出全部数对的情况下
    //原问题转换成在n1个升序队列中，查找最小的前K对数字
    //Time  O(KlogN)
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int rows = nums1.size();
        int cols = nums2.size();
        vector<vector<int>> topK; //输出结果
        if (rows == 0 || cols == 0)
            return topK;

        // auto cmp = [&nums1, &nums2](pair<int, int> &a, pair<int, int> &b) {
        //     return (nums1[a.first] + nums2[b.second]) > (nums1[a.first] + nums2[b.second]);
        // }; //(3,(0,0)) （9,(1,0)）  构造小顶堆

        auto cmp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b) { return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]; };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> priorityQueue(cmp);

        //假设nums1每个元素和 有序数组nums1相加后，产生n个有序数组.
        //{3,5.7}
        //{9.11.13}
        //{13,15,17}
        //然后组成n×m升序矩阵。

        //插入n个有序数组中的一个元素
        for (int i = 0; i < rows; i++)
        {
            priorityQueue.emplace(i, 0);
        }

        //找到和最小的 k 对数字 
        while (k > 0 && !priorityQueue.empty())
        {
            k--; //每次比较获取最小的一个元素，类比合并2个有序链表。
            pair<int, int> temp = priorityQueue.top();
            priorityQueue.pop(); //获取一个记录
            cout << nums1[temp.first] << ":" << nums2[temp.second] << endl;
            if (temp.second + 1 < cols)
            {
                cout << nums1[temp.first] << " insert " << nums2[temp.second + 1] << endl;
                priorityQueue.emplace(temp.first, temp.second + 1); //列+1
            }

            vector<int> item;
            item.push_back(nums1[temp.first]);
            item.push_back(nums2[temp.second]);

            topK.push_back(item);
        }

        return topK;
    }
};
// @lc code=end

// class Solution {
//     public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
//         int n1 = nums1.length, n2 = nums2.length;

//         PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> (nums1[o1[0]]+nums2[o1[1]]) - (nums1[o2[0]]+nums2[o2[1]]));
//         List<List<Integer>> result = new ArrayList<>();

//         if (n1 == 0 || n2 == 0 || k == 0) return result;
//         for (int i = 0; i < n1; i++) pq.offer(new int[]{i, 0});

//         while(pq.size() > 0 && k > 0) {
//         	int[] pair = pq.poll();
//         	if (pair[1] + 1 < n2) pq.offer(new int[]{pair[0], pair[1]+1});
//         	List<Integer> temp = new ArrayList<>();
//         	temp.add(nums1[pair[0]]);
//         	temp.add(nums2[pair[1]]);
//         	result.add(temp);
//                 k--;
//         }

//         return result;
//     }
// }

// type Pair struct {
//     IdxInNums1 int
//     IdxInNums2 int
//     Val        int
// }

// type PairHeap []Pair

// func (ph PairHeap) Len() int {
//     return len(ph)
// }

// func (ph PairHeap) Less(i, j int) bool {
//     return ph[i].Val < ph[j].Val
// }

// func (ph PairHeap) Swap(i, j int) {
//     ph[i], ph[j] = ph[j], ph[i]
// }

// func (ph *PairHeap) Push(x interface{}) {
//     *ph = append(*ph, x.(Pair))
// }

// func (ph *PairHeap) Pop() interface{} {
//     root := (*ph)[len(*ph)-1]
//     *ph = (*ph)[:len(*ph)-1]
//     return root
// }

// //find-k-pairs-with-smallest-sums
// func kSmallestPairs(nums1 []int, nums2 []int, k int) [][]int {

//     //程序合法性检查
//     if len(nums1) == 0 || len(nums2) == 0 {
//         return nil
//     }
//     // Init heap
//     ph := new(PairHeap)
//     heap.Init(ph)
//     for i := 0; i < len(nums2); i++ {
//         heap.Push(ph, Pair{0, i, nums1[0]+nums2[i]})
//     }
//     // Generate ohther pairs and get first k smallest paris
//     res := make([][]int, 0)
//     if k > len(nums1)*len(nums2) {
//         k = len(nums1) * len(nums2)
//     }
//     for i := 0; i < k; i++ {
//         pair := heap.Pop(ph).(Pair)
//         res = append(res, []int{nums1[pair.IdxInNums1], nums2[pair.IdxInNums2]})
//         if pair.IdxInNums1 < len(nums1)-1 {
//             heap.Push(ph, Pair{pair.IdxInNums1+1, pair.IdxInNums2, nums1[pair.IdxInNums1+1]+nums2[pair.IdxInNums2]})
//         }
//     }
//     return res
// }

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {

        vector<vector<int>> output;

        int rows = nums1.size();
        int cols = nums2.size();
        if (0 == rows || 0 == cols)
        {
            vector<vector<int>> output;
            return output;
        }
        //pair<int,int>存储的是坐标
        //nums1 nums2 分别拿出一个元素累加组成n*m 升序矩阵
        //{3,5.7}
        //{9.11.13}
        //{13,15,17}

        auto cmp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b) {
            //构造小顶堆,比较(u,v) 的和 5（0,2）
            return (nums1[a.first] + nums2[a.second]) > (nums1[b.first] + nums2[b.second]);
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        // std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);

        //row组成n个有序队列(列也可以) ，第一个元素
        //想想合并2个有序数组，必须拿出第一元素
        for (int row = 0; row < rows; row++)
        {
            pq.emplace(row, 0);
            // emplace(C++11) constructs element in-place and sorts the underlying container
            //pq.push(make_pair(row,0))
        }

        //依次输出和为最小的k对元素
        while (k > 0 && !pq.empty())
        {
            k--;
            //获取第i小记录
            pair<int, int> temp = pq.top();
            pq.pop();

            //当前有序数组移动下一个元素
            if (temp.second + 1 < cols)
            {
                pq.emplace(temp.first, temp.second + 1);
            }

            vector<int> paris = {nums1[temp.first], nums2[temp.second]};
            output.push_back(paris);
        }

        return output;
    }
};