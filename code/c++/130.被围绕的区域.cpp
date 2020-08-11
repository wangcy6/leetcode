/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode-cn.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (40.49%)
 * Likes:    295
 * Dislikes: 0
 * Total Accepted:    51.6K
 * Total Submissions: 124.6K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 
 * 示例:
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * 运行你的函数后，矩阵变为：
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * 解释:
 * 
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 * 
 * 我的思路是： 从边界开始处理 ，如果处理了标记ok
 * 
 * 迷惑思考
 * 1. 0 的三面 我知道，第四面我不知道 0 还是 0 这个怎么判断 这个连通性怎么确定
 * 2. 对于每一个边界上的 O，我们以它为起点，标记所有与它直接或间接相连的字母 O
 * 
 *  按照标准dfs遍历，通过 0,扩展四周 ，如果 x 返回false 如果 0 0 这形成相互依赖，程序死循环了，无法判断是否围绕了。
 *  可能有一个做法能解决这个问题，但是我现在根本想不起来。我从周围连通性判断
 * 熟悉子问题：
 * 1. 给我一个二维数组，我只会i j 从 0开始遍历
 * 2. 从边界开始向内部扩散的
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
    }
};
// @lc code=end
class Solution {
public:
    int n, m;

    void dfs(vector<vector<char>>& board, int x, int y)
    {
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }

    void solve(vector<vector<char>>& board)
    {
        n = board.size();
        if (n == 0) {
            return;
        }
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for (int i = 1; i < m - 1; i++) {
            dfs(board, 0, i);
            dfs(board, n - 1, i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};