/** 
 * https://leetcode-cn.com/problems/palindromic-substrings/
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
  具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串

State
state[i][j] is true if substring s[i, j] is palindromic

Aim State
decide all possible state[i][j] and count the element that is true

State Transition
state[i][j] is true if s[i] == s[j] and state[i+1][j-1] is true (j - i >= 2)
state[i][j] is true if s[i] == s[j] (j - i == 1)
state[i][j] is true (j - i == 0)
i is decreasing, dist = j - i is increasing
*/
class Solution {
public:
    int countSubstrings(string s) {
      int n=s.size();
      int dp[n][n]={0};//空间复杂度 o(n2) dp[i][j]的含义是s[i..j]是否回文
      int result=0;
      //时间复杂度o(n2)
      for(int end=0;end<n;end++)
      {
         for(int start=0;start<=end;start++)
         {
            if(start ==end)
            {
               dp[start][end]=1;//只有一个字符 
               result++;
            }
            //判断字符[start end] 如何确子串[start+1, end-1] 已经计算过呢。????这个地方不对
            if(s[start]==s[end]&&(end-start<=1||dp[start+1]==dp[end-1]))
            {
                dp[start][end]=1;
                result++;
            }

         }
      }
      return result;
    }
};