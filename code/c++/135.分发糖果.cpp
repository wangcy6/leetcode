/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 *
 * https://leetcode-cn.com/problems/candy/description/
 *
 * algorithms
 * Hard (40.57%)
 * Likes:    142
 * Dislikes: 0
 * Total Accepted:    12.2K
 * Total Submissions: 29.9K
 * Testcase Example:  '[1,0,2]'
 *
 * 老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
 * 
 * 你需要按照以下要求，帮助老师给这些孩子分发糖果：
 * 
 * 
 * 每个孩子至少分配到 1 个糖果。
 * 相邻的孩子中，评分高的孩子必须获得更多的糖果。
 * 
 * 
 * 那么这样下来，老师至少需要准备多少颗糖果呢？
 * 
 * 示例 1:
 * 
 * 输入: [1,0,2]
 * 输出: 5
 * 解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,2,2]
 * 输出: 4
 * 解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
 * ⁠    第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
 * 

 */

// @lc code=start
class Solution {
public:

    int candy(vector<int>& ratings) {
      
      int sum = ratings.size()-1;
      int last =-1;
      for(int i=0;i<ratings.size();i++)
      {
         if(ratings[i] >last)
         {
           sum++;
         }
      }

      return sum;

    }

    
    
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

