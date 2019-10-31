/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    int len = nums.size();
    vector<vector<int>> out;
    if (len == 0)
      return out;
    vector<bool> used(len, false);
    vector<int> path; // stack存放到vector比较麻烦，用vector替换

    std::sort(nums.begin(), nums.end());
    dfs(0, nums, used, path, out);

    return out;
  }

  void dfs(int level, vector<int> &nums, vector<bool> &used, vector<int> &path,
           vector<vector<int>> &out) {
    //从root到叶子节点路径 结束条件
    // get the path of array
    if (level == nums.size()) {
      out.push_back(path);
    }

    for (int i = 0; i < nums.size(); i++) {
      //从剩余可选项中。
      if (false == used[i]) {
        // used[i - 1] == false 表示前面一个节点计算完成
        //不然 1（true） 1（true） 2（第一次计算要完成）
        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
          continue;
        }
        used[i] = true;
        //入栈push
        path.push_back(nums[i]);
        dfs(level + 1, nums, used, path, out);
        //出栈pop
        used[i] = false;
        path.pop_back();
      }
    }
  }
};
// @lc code=end
