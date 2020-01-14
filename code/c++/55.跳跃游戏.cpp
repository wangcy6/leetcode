/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 * 
 * time:o(n)
 *  https://github.com/wangcy6/leetcode/issues/13
 * 缺点：
 * 下面做法虽然通过了，但是没有回溯和动态规划角度出发
 *  采取讨巧方式，如果题目规则发生变化。下题目根本
 *  不行，没有体会这个题目真实考察内容是什么。
 *  https://leetcode-cn.com/problems/jump-game/solution/tiao-yue-you-xi-by-leetcode/
 * 
 *  https://leetcode-cn.com/problems/jump-game/solution/dong-tai-gui-hua-yu-tan-xin-suan-fa-jie-jue-ci-wen/
  */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
       int maxSum=0;
       int temp;
    
       for (int i=0;i<nums.size()-1;i++)
       {
          temp=i+nums[i];
          maxSum=max(temp,maxSum);
          if (maxSum <=i)
          {
            return false;   
          }
          
       } 
       return true;
    }
    /** 递归回溯
        时间复杂度：O(2^n), 空间复杂度：O(n)
        可想而知，运行将超时
     *  执行结果：超出时间限制
     * [25000,24999,24998,24997,24996,24995,24994,24993,24992,24991,24990,24989,24988,24987,24986,24985,24984,24983,24982,24981,24980,24979,24978,24977,24976,24975,24974,24973,24972,24971,24970,24969,24968,24967,24966,24965,24964,24963,24962,24961,24960,24959,24958,24957,24956,24955,24954,24953,24952,24951,24950,24949,24948,24947,24946,24945,24944,24943,24942,24941,24940,24939,24938,24937,24936,24935,24934,24933,24932,24931,24930,24929,24928,24927,24926,24925,24924,24923,24922,24921,24920,24919,24918,24917,24916,24915,24914,24913,24912,24911,24910,24909,24908,24907,24906,24905,24904,24903,24902,24901,24900,24899,24898,24897,24896,24895,24894,24893,24892,24891,24890,24889,24888,24887,24886,24885,24884,24883,24882,24881,24880,24879,24878,24877,24876,24875,24874,24873,24872,24871,24870,24869,24868,24867,24866,24865,24864,24863,24862,24861,24860,24859,24858,24857,24856,24855,24854,24853,24852,24851,24850,24849,24848,24847,24846,24845,24844,24843,24842,24841,24840,24839,24838,24837,24836,24835,248
      * [2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6]
     **/
    bool canJump1(vector<int>& nums) {
      return  dfs_canJump(0,nums);  //从第一个位置开始不同尝试
    }
    bool dfs_canJump(int index,vector<int>& nums)
    {
       if ( index ==nums.size()-1)
       {
          return true;
       }
        //回溯
       for (int i=1; i<nums.size() && i<=nums[index];i++)
       {
         if (dfs_canJump(index+i,nums))
         {
             return true;
         }
       }

       return false;
       
    }
    /** 递归回溯
     时间复杂度：O(2^n), 
    空间复杂度：O(n)
    当遇到一个位置点的其中一种跳法成功到达终点，
    就说明此种跳法可行,记录arr[position] = true
    若当前一种跳法不可行，却又并不影响下一种跳法,记录arr[position] = false
    因此对访问过的位置节点的各种跳法，作出记录，避免重复计算
    执行用时 :2548 ms

    */
    bool canJump2(vector<int>& nums) {
      vector<int> dp(nums.size(),0);//0 默认 1ok 2false 
      return  dfs_canJump(0,nums,dp);  //从第一个位置开始不同尝试
    }
    bool dfs_canJump(int start,vector<int>& nums,vector<int>& dp)
    {
       if ( start ==nums.size()-1)
       {
          return true;
       }
       if(dp[start] !=0)
       {
         return dp[start] ==1?true:false;
       }
        //回溯
        int end=min((nums.size()-1),(start+nums[start]))
       for (int i=index+1; i<=end;i++)
       {
         if (dfs_canJump(i,nums,dp))
         {   
             dp[index] =1;
             return true;
         }
       }
       dp[index] =2;
       return false;
       
    }
    //dp 执行用时 :12 ms,内存消耗 :9.8 MB
    bool canJump3(vector<int>& nums) {
      vector<bool> dp(nums.size(),false);//标记当前位置是否可以通过
      dp[0] =true;
      int step=nums.size();
      for(int i=1;i<step;i++)
      {  
        //逆序效率更高
        for(int j=i-1;j>=0;j--)
        {
          if (dp[j] == true && (j+nums[j]) >=i)
          {
              dp[i] =true;
              break;
          }
        }
      }

      return dp[nums-1];
    }
    
};
// @lc code=end

