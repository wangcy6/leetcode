/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    
    
    //这个思路不正确，这是分配最多的情况。
    int candy1(vector<int>& ratings) 
    {
      
      sort(ratings.begin(),ratings.end());
      
      int sum =0;
      for (int i = 1; i <= ratings.size(); i++)
      {
           sum+=i;
      }

      return sum;
      

    }
    int candy(vector<int>& ratings) {
      
      int sum =0;
      int len =ratings.size();

      vector<int> dp(len,1);

      for (int i=1;i<len;i++)
      {
         if(ratings[i] >ratings[i-1])
         {
            dp[i] =max(dp[i],dp[i-1]+1);
         }
      }

      for (int i=len-2;i>=0;i--)
      {
         if(ratings[i] >ratings[i+1])
         {
            dp[i] =max(dp[i],dp[i+1]+1);
         }
      }
       
      for(int i=0;i<len;i++)
      {
          sum+=dp[i];
      } 
       return sum;
    }
};
// @lc code=end

