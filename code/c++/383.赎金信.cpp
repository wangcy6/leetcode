/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 *
 * https://leetcode-cn.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (53.58%)
 * Likes:    106
 * Dislikes: 0
 * Total Accepted:    26.1K
 * Total Submissions: 48.3K
 * Testcase Example:  '"a"\n"b"'
 *
 * 给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines
 * 里面的字符构成。如果可以构成，返回 true ；否则返回 false。
 * 
 * (题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)
 * 
 * 
 * 
 * 注意：
 * 
 * 你可以假设两个字符串均只含有小写字母。
 * 
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 * 
 *  遍历字符串个数,然后判断相等 。
 *  因为题目给出
 *  字母个数相等，不代表顺序yiyang ab ba
 */
class Solution1
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int hash[26] = {0};
        for (char c : magazine)
            hash[c - 'a'] += 1;
        for (char c : ransomNote)
            if ((hash[c - 'a'] -= 1) < 0)
                return false;
        return true;
    }
};
// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // unorder_map<char, int> hash; 不采用该结构

        vector<int> hash(128, 0);
        for (char i : magazine)
        {
            hash[i] += 1;
        }

        for (char i : ransomNote)
        {
            if ((hash[i] -= 1) < 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
