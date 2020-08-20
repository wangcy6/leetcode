/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 *
 * https://leetcode-cn.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (62.27%)
 * Likes:    335
 * Dislikes: 0
 * Total Accepted:    48.6K
 * Total Submissions: 75.8K
 * Testcase Example:  '"abc"'
 *
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 * 
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 * 
 * 
 * 示例 2：
 * 
 * 输入："aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输入的字符串长度不会超过 1000 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s)
    {
        int count = 0; //返回结果
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false)); // s[i,j] 是否回文

        //2层循环判断每个字符是否回文
        //外层：从小到大
        //end 保持不变，start不断变化
        //[i....j]
        for (int j = 0; j < n; j++) {
            //在计算j时候 j-1已结判断完成
            for (int i = 0; i <= j; i++) {
                if (i == j) {
                    dp[i][j] = true;
                    count++;
                } else if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1] == true)) {
                    // aa  aaaa

                    dp[i][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end
