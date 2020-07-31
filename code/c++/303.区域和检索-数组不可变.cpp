/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 *
 * https://leetcode-cn.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (61.83%)
 * Likes:    163
 * Dislikes: 0
 * Total Accepted:    41.8K
 * Total Submissions: 67.5K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n' +
  '[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * 给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
 * 
 * 示例：
 * 
 * 给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 说明:
 * 
 * 
 * 你可以假设数组不可变。
 * 会多次调用 sumRange 方法。
 * 
 * 
 */

// @lc code=start
class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        dp = nums;
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] += dp[i - 1];
        }
    }

    int sumRange(int i, int j)
    {
        return i == 0 ? dp[j] : dp[j] - dp[i - 1];
    }

private:
    vector<int> dp;
};

// class NumArray
// {
// private:
//     int *sum;

// public:
//     NumArray(vector<int> &nums)
//     {
//         //sum[i] 为 nums[0 : i-1]的和
//         sum = new int[nums.size() + 1];
//         sum[0] = 0;
//         for (int i = 1; i <= nums.size(); i++)
//             sum[i] = sum[i - 1] + nums[i - 1];
//     }
//     ~NumArray()
//     {
//         delete[] sum;
//     }
//     int sumRange(int i, int j)
//     {
//         return sum[j + 1] - sum[i];
//     }
// };

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end
