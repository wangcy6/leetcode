/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    
    string reverseWords(string s) {
     
     //check in
     if (s.zie() ==0) 
     {
         return s;
     }

     //定义2个指针 
     //一个单词开始位置，一个指向单词结束位置下一个位置
     //前闭后开[Let's )
     
     auto beignIndex =s.begin();
     auto endIndex =s.end();
     //Let's take LeetCode contest
     while (endIndex <s.end())
     {
          
        if (*endIndex == ' ')
        {
          if (beignIndex !=endIndex)
          {
                reverse(beignIndex,endIndex);
          }
         
          beignIndex=endIndex+1;//
        }
        //如果不是空格 endIndex++
        //如果是空格 endIndex++
         endIndex++;
     }
     
      return s;
    }
};
// @lc code=end

