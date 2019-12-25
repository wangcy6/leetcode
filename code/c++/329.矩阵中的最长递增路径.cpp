/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 *
 * https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (38.92%)
 * Likes:    88
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 16.9K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * 给定一个整数矩阵，找出最长递增路径的长度。
 *
 * 对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。
 * 
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * 示例 1:
 *
 * 输入: nums = 
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ]
 * 输出: 4 
 * 解释: 最长递增路径为 [1, 2, 6, 9]。
 *
 * 示例 2:
 *
 * 输入: nums = 
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ]
 * 输出: 4 
 * 解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
 *
 *
 *
 * 题目理解：
 * 约束条件：递增路径
 * 步骤：回溯递归
 *
 *
 */

// @lc code=start
class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int row = matrix.size();
    if (0 == row)
      return 0;
    int col = matrix[0].size();

    vector<vector<int>> dp(row, vector(col, 0)); //记录从每个点开始最长的路径
    int path = 1;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        //任意坐标开始都有可能
        if (dp[i][j] != 0) {
          int temp = dfs(matrix, dp, i, j, INT_MIN);
          path = max(temp, path);
        }
      }
    }

    return path;
  }
  // row ，cols 开始坐标位置
  int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int row,
          int col, int pre) {
    if (row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size()) {
      return 0; // 最简单的case
    }
    if (pre > = matrix[row][col]) {
      return 0; //不是递增了，肯定是0
    }

    if (dp[row][col] > 0) {
      return do[row][col]; //避免重复计算
    }

    int left = dfs(matrix, dp, row, cols - 1, matrix[row][col]);
    int right = dfs(matrix, dp, row, cols + 1, matrix[row][col]);
    int up = dfs(matrix, dp, row - 1, cols, matrix[row][col]);
    int down = dfs(matrix, dp, row + 1, cols, matrix[row][col]);

    dp[row][col] = max(max(left, right), max(up, down)) + 1; //变化地方
    return dp[row][col];
  }
};
// @lc code=end
