/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 *
 * https://leetcode-cn.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (41.86%)
 * Likes:    120
 * Dislikes: 0
 * Total Accepted:    9.6K
 * Total Submissions: 22.7K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * 给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，
 * 而“大西洋”处于大陆的右边界和下边界。
 * 
 * 规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。
 * 
 * 请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输出坐标的顺序不重要
 * m 和 n 都小于150
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * 
 * 给定下面的 5x5 矩阵:
 * 
 * ⁠ 太平洋 ~   ~   ~   ~   ~ 
 * ⁠      ~  1   2   2   3  (5) *
 * ⁠      ~  3   2   3  (4) (4) *
 * ⁠      ~  2   4  (5)  3   1  *
 * ⁠      ~ (6) (7)  1   4   5  *
 * ⁠      ~ (5)  1   1   2   4  *
 * ⁠         *   *   *   *   * 大西洋
 * 
 * 返回:
 * 
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        vector<vector<int>> out;
        int row = matrix.size();
        if (0 == row)
            return out;
        int col = matrix[0].size();
        if (0 == col)
            return out;

        // 能流动到“太平洋"的陆地
        vector<vector<bool>> dp1(row, vector<bool>(col, false));
        // 能流动到“大西洋"的陆地
        vector<vector<bool>> dp2(row, vector<bool>(col, false));

        //从第一个行/最后一行出发寻找连同节点，,不变的x坐标
        for (int j = 0; j < col; j++)
        {
            dfs(0, j, INT_MIN, matrix, dp1);
            dfs(row - 1, j, INT_MIN, matrix, dp2);
        }
        //从第一个列/最后一列出发寻找连同节点,不变的y坐标
        for (int i = 0; i < row; i++)
        {
            dfs(i, 0, INT_MIN, matrix, dp1);
            dfs(i, col - 1, INT_MIN, matrix, dp2);
        }

        vector<int> temp(2);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                //请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。
                if (dp1[i][j] == true && dp2[i][j] == true)
                {
                    temp[0] = i;
                    temp[1] = j;
                    out.push_back(temp);
                }
            }
        }
        return out;
    }

    void dfs(int row, int col, int height, vector<vector<int>> &matrix, vector<vector<bool>> &visited)
    {
        if (row < 0 || row >= matrix.size() ||
            col < 0 || col >= matrix[0].size())
        {
            return; //农村包围城市，农村就边界
        }

        if (visited[row][col] == true)
        {
            return; //已经dfs遍历过
        }
        if (height > matrix[row][col])
        {
            return; //不是升序，此路不通
        }

        visited[row][col] = true; //能走到这里说明 当前层次遍历完毕

        //每个点扩散四周，每个点被四周扩散时候，只要满足一个就可以连通，减少扩散层次。
        dfs(row + 1, col, matrix[row][col], matrix, visited);
        dfs(row - 1, col, matrix[row][col], matrix, visited);
        dfs(row, col + 1, matrix[row][col], matrix, visited);
        dfs(row, col - 1, matrix[row][col], matrix, visited);
    }
};
// @lc code=end
