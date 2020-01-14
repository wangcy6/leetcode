/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (42.03%)
 * Likes:    390
 * Dislikes: 0
 * Total Accepted:    101.9K
 * Total Submissions: 241.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 思路
 * 1 从最后一个位置开始遍历
 * 2. 计算结果 a(%10),b(/10) 
 * 3 .结果存放到另外一个数字内，如果
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      
      int len =digits.size();
      vector<int> out;
      int sum =0;
      
      for(int i=len-1;i>=0;i--)
      {    
          if(i ==len-1)
          {
               sum +=(digits[i]+1); 
          }else
          {
               sum +=digits[i];
          }
          
        
           out.push_back(sum%10);
           sum/=10;
      }

      if( sum ==1)
      {
          out.push_back(1);
      }

      reverse(out.begin(),out.end());

      return out;

    }
};
// @lc code=end

