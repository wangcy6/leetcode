/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (34.76%)
 * Likes:    3846
 * Dislikes: 0
 * Total Accepted:    535K
 * Total Submissions: 1.5M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 *  https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/hua-dong-chuang-kou-by-powcai/
 * 
 *  阅读：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/hua-jie-suan-fa-3-wu-zhong-fu-zi-fu-de-zui-chang-z/
 *  耗时： 20
 *  输出：没看懂
 * 
 *  阅读：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-cshi-xian-/
 * 
 * 
 */

// @lc code=start

class Solution
{
public:
    //看到这个题目 输入: "bbbbb" ，我马上想到map 统计每个字符个数，
    //这里让统计key 可能是任意字符长度子串 "pwwkew" 该怎么办
    //说明key 如果是string 性能可能下降。必须字符作为key。
    // 8 ms
    //测试: aa->1
    int lengthOfLongestSubstring(string s)
    {
        int result = 0;
        vector<int> data(128, -1);
        //ASCII码表里字符总共有128个,用每个字符作为key,永远不可能越界。
        //如果重复出现。舍去后面字符重新计算。
        int start = 0;

        for (int i = 0; i < s.size(); i++)
        {
            char temp = s[i];
            //位置关系 [0 ...start ...i)
            if (data[temp] >= start)
            {
                //如果有重复部分，移动掉前缀重复,重新开始计算。
                //移动窗口开始位置。
                start = data[temp] + 1;
            }
            data[temp] = i;
            //如果不重复,理想情况,移动窗口结束位置。
            result = max(result, i - start + 1);
        }

        return result;
    }
};

class Solution1
{
public:
    //看到这个题目不重复，我马上想到map 统计每个字符个数，
    //这里让统计key 可能是任意字符长度该怎么办
    //说明key任意字符性能可能下降 https://blog.csdn.net/G1036583997/article/details/51910598
    //24 ms
    int lengthOfLongestSubstring(string s)
    {
        int result = 0;
        unordered_map<char, int> data;
        int start = 0;

        for (int i = 0; i < s.size(); i++)
        {
            char temp = s[i];
            if (data.count(temp) > 0 && data[temp] >= start)
            {
                start = data[temp] + 1;
            }
            data[temp] = i;
            //如果不重复,理想情况
            result = max(result, i - start + 1);
        }

        return result;
    }
};
// @lc code=end

