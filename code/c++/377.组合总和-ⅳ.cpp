/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 *
 * https://leetcode-cn.com/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (41.79%)
 * Likes:    153
 * Dislikes: 0
 * Total Accepted:    12.1K
 * Total Submissions: 28.8K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * 给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。
 * 
 * 示例:
 * 
 * 
 * nums = [1, 2, 3]
 * target = 4
 * 
 * 所有可能的组合为：
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 
 * 请注意，顺序不同的序列被视作不同的组合。
 * 
 * 因此输出为 7。
 * 
 * 
 * 进阶：
 * 如果给定的数组中含有负数会怎么样？
 * 问题会产生什么变化？
 * 我们需要在题目中添加什么限制来允许负数的出现？
 * 
 * 致谢：
 * 特别感谢 @pbrother 添加此问题并创建所有测试用例。
 *  
 * 1 个数字可以出现多次  这个直接被拦路了
 * 2. 

 */

//@lc code=start
class Solution
{
private:
    unordered_map<int, int> map;

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        if (target < 0 || nums.empty())
            return 0;

        if (target == 0)
        {
            return 1;
        }

        if (map.count(target))
        {
            return map[target];
        }
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (target >= nums[i])
            {
                cout << "-------------" << count << endl;
                count += combinationSum4(nums, target - nums[i]);
            }
        }

        map[target] = count;
        cout << target << ":" << count << endl;
        return count;
    }
};
//@lc code=start
// 0 ms
// 7.9 MB
class Solution3
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, -1);
        //vector<int> dp(nums.size() + 1, -1);
        dp[0] = 1;
        return dfs(nums, target, dp);
    }

    int dfs(vector<int> &nums, int target, vector<int> &dp)
    {
        if (dp[target] != -1)
        {
            return dp[target];
        }

        int count = 0;
        for (auto temp : nums)
        {

            //根据题目例子集合中元素可以重复使用。
            if (target >= temp)
            {
                count += dfs(nums, target - temp, dp);
            }
        }
        dp[target] = count;
        return count;
    }
};
// @lc code=start
//Time Limit Exceeded
//排列组合问题
//[4,2,1] 32 n越大超时可能性越大
//
class Solution2
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        if (target < 0)
            return 0; // 和为给定目集合不成立  target=4-3-2

        if (target == 0)
            return 1;

        int count = 0;
        for (auto temp : nums)
        {

            //根据题目例子集合中元素可以重复使用。
            if (target >= temp)
            {
                count += combinationSum4(nums, target - temp);
            }
        }

        return count;
    }
};

// @lc code=start
//Time Limit Exceeded
//[4,2,1] 32 n越大超时可能性越大
class Solution1
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        if (target < 0)
            return 0; // 和为给定目集合不成立  target=4-3-2

        if (target == 0)
            return 1;

        int count = 0;
        for (auto temp : nums)
        {
            //根据题目例子集合中元素可以重复使用。
            count += combinationSum4(nums, target - temp);
        }

        return count;
    }
};
// @lc code=end
