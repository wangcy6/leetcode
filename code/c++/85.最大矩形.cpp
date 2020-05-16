/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 *
 * https://leetcode-cn.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (45.93%)
 * Likes:    409
 * Dislikes: 0
 * Total Accepted:    26.8K
 * Total Submissions: 58.4K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * 输出: 6
 * 
 * 我看到了，但是想不出来如何描述。
 * http://www.p-chao.com/2017-05-12/leetcode_085-maximal-rectangle-%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/
 */

// @lc code=start
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int r = matrix.size();
        if (r == 0)
            return 0;
        int c = matrix[0].size();

        // dp[i][j] := max len of all 1s ends with col j at row i.
        vector<vector<int>> dp(r, vector<int>(c));

        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                dp[i][j] = (matrix[i][j] == '1') ? (j == 0 ? 1 : dp[i][j - 1] + 1) : 0;

        int ans = 0;

        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
            {
                int len = INT_MAX;
                for (int k = i; k < r; k++)
                {
                    len = min(len, dp[k][j]);
                    if (len == 0)
                        break;
                    ans = max(len * (k - i + 1), ans);
                }
            }

        return ans;
    }
};
// @lc code=end
