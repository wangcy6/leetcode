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
 *  https://leetcode-cn.com/problems/surrounded-regions/solution/dao-yu-wen-ti-zhi-bei-wei-rao-de-qu-yu-cicada-by-a/
 * 
 * https://leetcode-cn.com/problems/surrounded-regions/solution/bei-wei-rao-de-qu-yu-by-leetcode-solution/
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board)
    {

        int rows = board.size();
        if (0 == rows)
            return;
        int cols = board[0].size();
        // dfs遍历 遍历边界节点的连通性 标记为#
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                //直接无法找到找到所有被 'X' 围绕的区域,从外围'O'开始
                if ((i == 0 || j == 0 || i == rows - 1 || j == cols - 1) && board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }
        //第二次遍历
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j)
    {

        // * X X X X
        // * X O O X
        // * X X O X
        // * X X O X
        //递归结束条件
        // if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 'X') {
        //# --> <--- #
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 'X' || board[i][j] == '#') {
            return;
        }
        //业务逻辑
        board[i][j] = '#'; //被包围的 和没有被包围的区分
        //递归逻辑
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
};
// @lc code=end

