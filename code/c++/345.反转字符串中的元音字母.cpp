/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (50.07%)
 * Likes:    105
 * Dislikes: 0
 * Total Accepted:    42.1K
 * Total Submissions: 83.6K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 示例 1:
 * 
 * 输入: "hello"
 * 输出: "holle"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "leetcode"
 * 输出: "leotcede"
 * 
 * 说明:
 * 元音字母不包含字母"y"。
 * 
 */

// @lc code=start
class Solution1
{
public:
    string reverseVowels(string s)
    {

        int sLength = s.length();
        int leftIndex = 0, rightIndex = sLength - 1;

        while (1)
        {
            //左边搜索下一个元音字母
            while (leftIndex < sLength && !isVowel(s[leftIndex]))
            {
                leftIndex++;
            }
            //右边搜索下一个元音字母的位置
            while (rightIndex > 0 && !isVowel(s[rightIndex]))
            {
                rightIndex--;
            }

            //进行交换
            if (leftIndex < rightIndex)
            {
                swap(s[leftIndex], s[rightIndex]);
            }
            else
            {
                break;
            }

            leftIndex++;
            rightIndex--;
        }
        return s;
    }

    inline bool isVowel(char currentChar)
    {
        return currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u' || currentChar == 'A' || currentChar == 'E' || currentChar == 'I' || currentChar == 'O' || currentChar == 'U';
    }
};

class Solution
{
public:
    string reverseVowels(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (!isornot(s[i]))
            {
                i++;
                continue;
            }
            if (!isornot(s[j]))
            {
                j--;
                continue;
            }
            swap(s[i++], s[j--]);
        }
        return s;
    }
    bool isornot(char c)
    {
        return (c == 'a' || c == 'A' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'e' || c == 'E');
    }
};

// @lc code=end
