/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (42.82%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    25.3K
 * Total Submissions: 59.2K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
 * 
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
 * 
 * 示例1:
 * 
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 * 
 * 示例 4:
 * 
 * 输入: pattern = "abba", str = "dog dog dog dog"
 * 输出: false
 * 
 * 说明:
 * 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 * 
 */
// https://www.youtube.com/watch?v=lIBLNODNX0U
// https://www.youtube.com/watch?v=M2fKMP47slQ
// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
    }

    bool wordPattern1(string pattern, string str)
    {
        istringstream strcin(str);
        string s;
        vector<string> vs;
        while (strcin >> s)
            vs.push_back(s);
        if (pattern.size() != vs.size())
            return false;
        map<string, char> s2c;
        map<char, string> c2s;
        for (int i = 0; i < vs.size(); ++i)
        {
            if (s2c[vs[i]] == 0 && c2s[pattern[i]] == "")
            {
                s2c[vs[i]] = pattern[i];
                c2s[pattern[i]] = vs[i];
                continue;
            }
            if (s2c[vs[i]] != pattern[i])
                return false;
        }
        return true;
    }
};
// @lc code=end
