/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode-cn.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (60.61%)
 * Likes:    402
 * Dislikes: 0
 * Total Accepted:    67K
 * Total Submissions: 110.4K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

 * 示例 1:
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [1], k = 1
 * 输出: [1]
 *
 * 提示：
 * 
 * 
 * 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
 * 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
 * 你可以按任意顺序返回答案。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> count;
        for (auto i : nums)
        {
            count[i]++;
        }

        int len = count.size();
        //根据频率排序，不是根据key排序
        //自定义比较函数
        priority_queue<pair<int, int>>, vector<pair<int, int>, greater<pair<int, int>>> pq;
    }
    //给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
    vector<int> topKFrequent1(vector<int> &nums, int k)
    {
        unordered_map<int, int> record; //(元素，频率)
        //遍历数组，录入频率
        for (int i = 0; i < nums.size(); i++)
        {
            record[nums[i]]++;
        }
        int n = record.size();

        //扫描record。维护当前出现频率最多的k个元素
        //最小堆。如果当前元素的频率大于优先队列中最小频率元素的频率，则替换
        //优先队列中，按频率排序，所以数据对是(频率，元素)形式
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto iter = record.begin(); iter != record.end(); iter++)
        {
            if (k == pq.size())
            { //队列已满
                if (iter->second > pq.top().first)
                {
                    pq.pop();
                    pq.push(make_pair(iter->second, iter->first));
                }
            }
            else
            {
                pq.push(make_pair(iter->second, iter->first));
            }
        }

        vector<int> result;
        while (!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        //更正
        reverse(result.begin(), result.end());

        return result;
    }
};
// @lc code=end
