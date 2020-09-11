/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 *
 * https://leetcode-cn.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (71.65%)
 * Likes:    164
 * Dislikes: 0
 * Total Accepted:    33.5K
 * Total Submissions: 46K
 * Testcase Example:  '3\n7'
 *
 * 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
 * 
 * 说明：
 * 
 * 
 * 所有数字都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 * 
 * 
 * 示例 2:
 * 
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * stack-overflow on address 0x7ffe5f4e0ff8 
 */

// @lc code=start
class Solution {
public:
    /*
     *   tree最多分支：9
     *   tree的高度：约束累计和为n path
     *   遍历：递归回溯，只要求计算k个。元素
     *   
     * 
     */
    vector<vector<int>> combinationSum3(int k, int n)
    {

        vector<vector<int>> result; //返回结果
        vector<int> path; //保存整个路径
        int start = 1; //访问标记
        dfs(n, start, k, path, result);

        return result;
    }
    void dfs(int sum, int start, int k, vector<int>& path, vector<vector<int>>& result)
    {

        //虽然不要求获取全部，但是依然全部遍历
        if (sum == 0 && k == path.size()) {
            result.push_back(path);
            return;
        }

        // if (k == 0) {
        //     return; 、、 题目理解错误，是组合元素为k个，不是k个组合
        // }

        //递归
        for (int i = start; i < 10; i++) {
            //找出所有相加之和为 n 的 k 个数的组合
            path.push_back(i);
            //dfs(sum - i, i, k, path, result); //每次递归从i开始，死循环呀stack-overflow stack-overflow
            dfs(sum - i, i + 1, k, path, result);
            path.pop_back();
        }
    }
};
// @lc code=end
