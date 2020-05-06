/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
 
public:
    int uniquePaths(int m, int n) 
    {
       vector<vector<int>> dp(m,vector(n,0));
       return uniquePaths(m,n,dp);
    }

    int uniquePaths(int m, int n,vector<vector<int>> &dp) {
       if (m ==0 || n ==0 )
       {
           return 0;
       } 

       if (m ==1 || n ==1 )
       {
           return 1;
       }
       if (dp[m-1][n-1] !=0)
       {
           return dp[m-1][n-1];
       }
       int left = uniquePaths(m-1,n);
       int up =uniquePaths(m,n-1);
       dp[m-1][n-1] =left+up;
       return dp[m-1][n-1];
    }
};
// @lc code=end

