#include <stdio.h> 
using namespace std;

class Solution {
public:
    /**
    1步骤
    
     目标： 找到达到楼层顶部的最低花费
            旁白：假如当cost[i] 位置，继续爬一个阶梯或者爬两个阶梯 消耗能量是一样的。求选择跳跃1个还是跳跃2个

     方式： 每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯
             
            旁白：cost：达到楼层顶部 有2个方式 从cost[n-1], cost[n-2] 
      
      初四化： 在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯
                
       旁白：  cost[0]， cost[1] 默认值 不消耗任何能量
    
        
 
    2.测试
    输入: cost = [10, 15, 20]
    输出: 15
     
     输入: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
    输出: 6

    3 复杂度
        o(n)
        执行用时: 16 ms, 在Min Cost Climbing Stairs的C++提交中击败了13.76% 的用户
        内存消耗: 7.3 MB, 在Min Cost Climbing Stairs的C++提交中击败了0.00% 的用户
    **/

    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int> dp(cost.size()+1,-1);
        return minCostClimbingStairs(cost,dp,cost.size());
    }

      int minCostClimbingStairs(vector<int>& cost,vector<int>& dp,int n) {
          
        if(n<=1)
        {
          return 0; //如果顶楼是0和层 不需要消耗任能量 
        }  
        if (n ==2)
        {
            return min(cost[0],cost[1]);
        }

        if(dp[n]!=-1)
        {
          return dp[n];
        }

        int one=minCostClimbingStairs(cost,dp,n-1)+cost[n-1];//走过阶梯n 需要消耗能量
        int two =minCostClimbingStairs(cost,dp,n-2)+cost[n-2]; //走过阶梯n 需要消耗能量

        dp[n]=min(one,two); //走到阶梯n+1， 需要消耗能量最小能能量 
        
        return dp[n];
    }

 // 走到阶梯n+1， 需要消耗能量最小能能量  
 //执行用时: 24 ms, 在Min Cost Climbing Stairs的C++提交中击败了6.36% 的用户
//内存消耗: 6.9 MB, 在Min Cost Climbing Stairs的C++提交中击败了0.00% 的用户
 int minCostClimbingStairs2(vector<int>& cost) 
 {
      int n=cost.size();
      vector<int> dp(n,-1); //走过阶梯n 需要消耗能量

      dp[0]=cost[0];
      dp[1]=cost[1];
      for (int i=2;i<cost.size();i++)
      {
         if(dp[i-1]<dp[i-2])
         {
           dp[i]=dp[i-1]+cost[i];
         }else
         {
             dp[i]=dp[i-2]+cost[i];
         }
      }
      //走到阶梯n+1， 需要消耗能量最小能能量 
      return min(dp[n-1],dp[n-2]);

 }
};

int main( int argc, char *argv[] ) 
{
    
    return 0;
}