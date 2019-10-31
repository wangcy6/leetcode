/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 *输入: [1,2,3]
 输出: 6个元素
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

 * 塔山之石
 * https://www.youtube.com/watch?v=8t7bIHIr9JY
 *
 https://github.com/jzysheep/LeetCode/blob/master/46.%20Permutations%20Solution1.cpp
 *https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/
 https://leetcode-cn.com/problems/permutations-ii/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liwe-2/
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> out;
    int len = nums.size();
    if (len == 0) {
      return out;
    }
    vector<bool> used(len, false); // true if nums[i] is used
    vector<int> pathStack;

    dfs(nums, out, used, pathStack, 0);
    return out;
  }
  // start is the index to path,counts number of used
  void dfs(vector<int> &nums, vector<vector<int>> &out, vector<bool> &used,
           vector<int> &pathStack, int start) {
    if (start == nums.size()) {
      out.push_back(pathStack);
      return;
    }
    // enumerate possible numbers for current position
    for (int i = 0; i < nums.size(); i++) {
      if (used[i] == false) {
        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
          continue;
        }
        used[i] = true;
        pathStack.push_back(nums[i]);
        dfs(nums, out, used, pathStack, start + 1);
        // restore for used, no need to restore path because it will be
        /// overwritten in the next iteration
        // 刚开始接触回溯算法的时候常常会忽略状态重置
        // 回溯的时候，一定要记得状态重置
        pathStack.pop_back();
        used[i] = false;
      }
    }
  }
};
// @lc code=end
