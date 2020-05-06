/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (38.89%)
 * Likes:    207
 * Dislikes: 0
 * Total Accepted:    35.5K
 * Total Submissions: 91K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 *
 * 示例 1:
 *
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 *
 *
 * 示例 2:
 *
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 *
 */

// @lc code=start
// comp 使用引用第三方库的类，无法进程函数重载
bool comp1(const vector<int> &v1, const vector<int> *v2) {
  return v1[0] <
         v2[0]; // 根据开始位置排序最小在前面，根据结束位置合并最大的在在后面
}
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> result;
    int len = intervals.size();
    if (len == 0)
      return result;

    auto cmp = [](const vector<int> &a, const vector<int> &b) {
      return a[0] < b[0];
    };
    sort(intervals.begin(), intervals.end(), cmp);

    result.push_back(intervals[0]);

    for (int i = 1; i < len; i++) {
      int pre = result[result.size() - 1][1];
      if (intervals[i][0] > pre) {
        result.push_back(intervals[i]);
      } else {
        //合并
        result[result.size() - 1][1] =
            max(pre, intervals[i][1]); //  reference operator[] (size_type n);
      }
    }
    return result;
  }
};
// @lc code=end
