/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (57.74%)
 * Likes:    163
 * Dislikes: 0
 * Total Accepted:    27.5K
 * Total Submissions: 47.7K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 *
 * candidates 中的每个数字在每个组合中只能使用一次。
 *
 * 说明：
 *
 *
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 *
 *
 * 示例 1:
 *
 * 输入: candidates = [10,1,2,7,6,1,5]  , target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 *
 *
 * 示例 2:
 *
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 */

// @lc code=start

/**  第二版本 
 * 1 测试用例 candidates = [2,5,2,1,2], target = 5, 
 * 2 要点 
 *  每个数字在每个组合中只能使用一次--->每次从剩余元素选择一个 
 *  <1,2> <2,1> 算一个集合，排序，后不允许从0开始，而是下一个start位置开始
 *   <1,3> <1,3> 算一个集合，重复元素，删除后面的一个，
 */
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {

    vector<vector<int>> out;
    vector<int> path;
    int sum = 0; // 下一个元素 sum=sum+candidates[i]
    int begin =
        0; // [0,begin-1] 代表已经被使用， begin 代表 正在使用，[begin+1,end] 
           // 有被占用 
           //每个数字在每个组合中只能使用一次。
    std::sort(candidates.begin(), candidates.end(), less<int>());
    dfs(candidates, target, sum, begin, path, out);
    return out;
  }

  void dfs(vector<int> &candidates, int &target, int sum, int start,
           vector<int> &path, vector<vector<int>> &out) {
    if (sum == target) {
      out.push_back(path); // 使数字和为 target 返回
      return;
    }
    if (sum > target || start >= candidates.size()) {
      return; //使数字和大于 target 舍去 
    }
    //使数字和小于 target 继续

    //每个数字在每个组合中只能使用一次
    int temp = 0;
    for (int i = start; i < candidates.size(); i++) {
      temp = sum + candidates[i];
      if (temp > target) {
        break;
      }
      // if (i > 0 && candidates[i] == candidates[i - 1])
      //这个根本不对。why why why？没有任何区别呀 相等的排除
      // i > 0 排除第一个节点，从语法不core考虑的
      // i>start 排除第i个节点，i代表正常计算
      // 1 2 2 =5
      // ，第三个元素和第二个元素相等，但是正常计算，第i个元素参与计算。
      //目的排除 该元素已经全部递归完毕.(如果正常计算不算)
      // used[i-1] = false  && candidates[i] == candidates[i - 1] 全排列
      // 1[true] 2[true] 2[true]
      if (i > start && candidates[i] == candidates[i - 1]) {
        continue;
      }
      path.push_back(candidates[i]);
      // i+1 当前元素累计完毕
      dfs(candidates, target, temp, i + 1, path, out);
      path.pop_back();
    }
  }
};

/**  第一版本 错误
 * 测试用例 
 * candidates = [2,5,2,1,2], target = 5, 
 * 当 集合 1，2开始时候如何选择
 *
 */
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {

    vector<vector<int>> out;
    vector<int> path;
    int sum = 0;
    int begin = 0;
    std::sort(candidates.begin(), candidates.end(), less<int>());
    dfs(candidates, target, sum, begin, path, out);
    return out;
  }

  void dfs(vector<int> &candidates, int &target, int sum, int start,
           vector<int> &path, vector<vector<int>> &out) {
    if (sum == target) {
      out.push_back(path);
      return;
    }
    if (sum > target || start >= candidates.size()) {
      return;
    }
    //每个数字在每个组合中只能使用一次
    for (int i = 0; i < candidates.size(); i++) {
      path.push_back(candidates[i]);
      dfs(candidates, target, sum + candidates[i], i, path, out);
      path.pop_back();
    }
  }
};
// @lc code=end
