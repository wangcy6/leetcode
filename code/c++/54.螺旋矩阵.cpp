/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (37.35%)
 * Likes:    233
 * Dislikes: 0
 * Total Accepted:    28.6K
 * Total Submissions: 76.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），
 * 请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 *
 *
 * 示例 1:
 *
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 *
 *
 * 示例 2:
 *
 * 输入:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 */
/**
第一次：
  回溯步骤
  1. 请问给你任意一点如何开始移动，条件约束是什么： 
     --->顺时针螺 right down, left up ，这个理解错误的，(0,0) 和(0,3)不一样。
  2. 历史计算过程 可以重复利用吗？
      --->
测试

输入
查看差别
[ [1,2,3,4],
 [6,7,8,9],
 [10,11,12,13],
 [20,21,22,23]
]
输出
[1,2,3,4,9,13,23,22,21,20,10,11,12,8,7,6]
期望答案
[1,2,3,4,9,13,23,22,21,20,10,6,7,8,12,11]

**/
// @lc code=start
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {}
};
// @lc code=end
