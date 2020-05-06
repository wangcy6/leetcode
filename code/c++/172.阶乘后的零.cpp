/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 *
 * https://leetcode-cn.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (39.90%)
 * Likes:    231
 * Dislikes: 0
 * Total Accepted:    29.7K
 * Total Submissions: 74.4K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，返回 n! 结果尾数中零的数量。
 * 
 * 示例 1:
 * 
 * 输入: 3
 * 输出: 0
 * 解释: 3! =3*2*1= 6, 尾数中没有零。
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: 1
 * 解释: 5! = 120, 尾数中有 1 个零.
 * 5 * 4 * 3 * 2 * 1 = 120
 * 120%10=0  120/10=12 有一个  因子 5^1,2^3
 *  示例 3:
 *
 * 输入:6
 * 输出:1
 * 解释: 6!=6*5*4*3*2*1=720  因子 5^1,2^3
 * 
 * 输入:10
 * 输出:2
 * 解释 10!=10*9*8*7*6*5*4*3*2*1=3628800 因子 5^2,2^8
 * 
 * 输入:15
 * 输出:2
 * 解释 15!=1307674368000
 * 输入:25
 * 
 * 输出:6
 * 25=25*24-20-15 ---10 ---5 ----1  5^6
 * 说明: 你算法的时间复杂度应为 O(log n) 。
 * 
 */

// @lc code=start
class Solution {
public:

     int trailingZeroes(int n) {
      int count =0;

      while(n >0 )
      {
        n/=5;
        count+=n;
      }
      return count;
    
     }

    //用笨方法求出阶乘然后再算 0 的个数会超出时间限制
    int trailingZeroes1(int n) {

     long long total =1;
     for(int i=n;i>0;i--)
     {
       total=i*total;
     }
     
     int count =0;

     while(total%10 ==0)
     {
        total/=10;
        count++;
     }
     return count;

    }
};
// @lc code=end

