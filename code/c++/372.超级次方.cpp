/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 *
 * https://leetcode-cn.com/problems/super-pow/description/
 *
 * algorithms
 * Medium (41.41%)
 * Likes:    72
 * Dislikes: 0
 * Total Accepted:    5.4K
 * Total Submissions: 12.8K
 * Testcase Example:  '2\n[3]'
 *
 * 你的任务是计算 a^b 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。
 * 
 * 示例 1:
 * 
 * 输入: a = 2, b = [3]
 * 输出: 8
 * 
 * 
 * 示例 2:
 * 
 * 输入: a = 2, b = [1,0]
 * 输出: 1024
 * 
 */

// @lc code=start
class Solution
{
public:
    /* 
      第一次思考： 
      首先你可以马上想到，求a^b，(1)计算B大小，(2)然后power

      第二次思考：b 是一个非常大的正整数且会以数组形式给出. 需要拆分B大小
      b=123=1*100+2*20+3*1
      a^b=a^3*a^0

       

    */
    int superPow(int a, vector<int> &b)
    {
    }
};
// @lc code=end
