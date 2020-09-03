/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (71.83%)
 * Likes:    552
 * Dislikes: 0
 * Total Accepted:    64K
 * Total Submissions: 89.2K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：4
 * 输出：[
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
 * https://leetcode-cn.com/problems/n-queens/solution/gen-ju-di-46-ti-quan-pai-lie-de-hui-su-suan-fa-si-/
 * 
 */

// @lc code=start
class Solution {
public:
    /***
    * 1.  一个解法就是一个路径，多个解法就是多个路径。
    * 2.  一个路径如何保存？  string 代表一行，一共n行 ，vector<string> 存储。最后vector<vector<string>>多个路径
    * 3. 如何递归回溯。如果条件不满足，就回溯，如果条件满足也回溯，就是暴力遍历全部情况。
    * 4. 类比 高度N的N叉树 ，遍历过程中找到符合条件的路径
    * 
   **/
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> path(n, string(n, '.'));
        dfs(0, n, path, res);
        return res;
    }

    void dfs(int row, int level, vector<string>& path, vector<vector<string>>& res)
    {
        //退出条件1，只要走到叶子节点，路径都是符合条件的路径

        if (row == level) {
            res.push_back(path);
        }

        //循环过程2 ：每个节点n个记录，最大高度n

        for (int i = 0; i < level; i++) {

            if (isValid(path, row, i) == false) {
                continue;
                //01 递归层次造成 stack 溢出
                //02  如果不满足，根本走不到最后一行
            }
            //业务判断2
            path[row][i] = 'Q'; // 当前行放置皇后
            dfs(row + 1, level, path, res);
            //01 假如i 是最后一层，i+1=n 递归结束 必然返回
            //02 如果这一层条件都不满足，就需要回溯，根本走不到最后一层
            path[row][i] = '.'; // 当前不放置皇后。
        }
    }
    bool isValid(vector<string>& queens, int row, int col)
    {
        for (int i = 0; i < row; ++i) {
            if (queens[i][col] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (queens[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < queens.size(); --i, ++j) {
            if (queens[i][j] == 'Q')
                return false;
        }
        return true;
    }
};
// @lc code=end
