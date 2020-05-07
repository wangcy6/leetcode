/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (41.65%)
 * Likes:    137
 * Dislikes: 0
 * Total Accepted:    69.6K
 * Total Submissions: 166.2K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 思路：
 * 根据定义实现
 * //全部变成小写
 * //空格不比较 
 */

// @lc code=start
class Solution
{
public:

  bool isPalindrome(string s)
  {    
      int len =s.size();
      if (len <= 1)
      {
         return true;
      } 

      for (int i=0, j =len-1; i < j; i++,j--)
      {
          while (i < j && !isalnum(s[i])
          {
             i++;
          }

          while (i < j && !isalnum(s[j])
          {
             j++;
          }

          if (tolower(s[i]) != tolower(s[j])
          {
              return false;
          }
          
      }
      
       return  true;

  }
    bool isPalindrome1(string s)
    {
        // 双指针
        if (s.size() <= 1)
            return true;
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            while (i < j && !isalnum(s[i])) // 排除所有非字母或数字的字符
                i++;
            while (i < j && !isalnum(s[j]))
                j--;
            if (tolower(s[i++]) != tolower(s[j--])) //统一转换成小写字母再比较
                return false;
        }
        return true;
    }
};
    // @lc code=end
