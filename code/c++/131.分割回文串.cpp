/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (68.42%)
 * Likes:    341
 * Dislikes: 0
 * Total Accepted:    40.6K
 * Total Submissions: 59.3K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 * 
 * 返回 s 所有可能的分割方案。
 * 
 * 示例:
 * 
 * 输入: "aab"
 * 输出:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    /**
     * 递归结束条件
     * 1. 如果能走到叶子节点，路径上节点全部多少回文字符串
     * 2. 如果路径上子串 不是回文，结束
     * 
     * 递归约束条件：
     *  1. 不是回文就结束
     * 
     * 递归过程
     * 1. 固定开始位置，然后寻找全部子串
     * 2. 回溯
     **/
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, 0, path, res);
        return res;
    }

    void dfs(string s, int start, vector<string>& path, vector<vector<string>>& res)
    {
        // 递归结束条件:能走到最后 说明都符合条件 类比叶子节点
        if (start >= s.size()) {
            res.push_back(path);
            return;
        }

        //递归处理
        string node;
        for (int i = start; i < s.size(); i++) {
            node = s.substr(start, i - start + 1); //分割字符串
            //判断是否为回文
            if (false == isPalindrome(node)) {
                //return;
                continue; //下一个子串 需要继续处理。
            }
            path.push_back(node);
            // dfs(s, start + 1, path, res);
            dfs(s, i + 1, path, res); //i+1 表示剩余字符
            path.pop_back();
        }
    }
    //判断是否为回文
    bool isPalindrome(string& s)
    {
        int len = s.size();
        for (int j = 0; j < len; j++) {
            if (s[j] != s[len - 1 - j]) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
