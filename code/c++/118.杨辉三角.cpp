/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (64.98%)
 * Likes:    215
 * Dislikes: 0
 * Total Accepted:    51.4K
 * Total Submissions: 79.1K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * https://leetcode.com/problems/pascals-triangle/discuss/38302/Maybe-is-the-shortest-code-in-c%2B%2B
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> res(numRows,vector(numRows,0));//n*n

        if( numRows <= 0)
        {
           return res;
        }

        for (int i = 0; i < numRows; i++)
        {
             // 每一行开始和结束都是1 
             res[i].resize(i+1);
             res[i][0] =res[i][i] =1;


            //从第三行开始，第二列开始。
            //从上一行最大数结束
            for( int j =1; i >=2 && j<i;j++)
            {
                res[i][j]= res[i-1][j]+res[i-1][j-1];
            }
        }
        
        return res;

    }
};
// @lc code=end

