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

    
//https://www.nowcoder.com/questionTerminal/72015680c32b449899e81f1470836097
int dp(int n)
{
    if( n ==1) return 1;
    if (n ==2 ) return 2;
    
    return dp(n-1)+dp(n-2);
}
//递归改成非递归
//  dp(n-1)+dp(n-2)这个不知道如何改写了。
int eatCandy(int n)
{  
   if( n < 3)
   {
      return n ==2?2:1;
   }
   vector<int> dp(n+1,0); 

   dp[1] =1;
   dp[2] =2;

   for( int i=3;i<=n;i++)
   {
     dp[i] =dp[i-1]+dp[i-2];
   }

   return dp[n];


}

};
// @lc code=end

