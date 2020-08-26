/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (54.32%)
 * Likes:    860
 * Dislikes: 0
 * Total Accepted:    157.9K
 * Total Submissions: 287.3K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start
class Solution {
public:
    /***
     * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合
     * 每个字符都3个选择,一共7个字符
     *  ---> 构造一颗高度为7的3叉树，然后求叶子节点路径
     *  同类：排列组合问题，集合问题
     * 这一不同地方：
     * 其他题目输入数组，这里是字符串 一样。
     * 其他题目每次固定选择，这里需要hash 
     **/
    vector<string> letterCombinations(string digits)
    {
        vector<string> result; //输出结果
        string path; //递归回溯遍历保持路径

        //可以任意选择答案输出的顺序 不需要记录顺序， ab ba是同一个情况

        unordered_map<char, string> hash; //记录每个数字，对应的字母
        //下标可以直接访问
        hash['2'] = "abc";
        hash['3'] = "def";
        hash['4'] = "ghi";
        hash['5'] = "jkl";
        hash['6'] = "mno";
        hash['7'] = "pqrs";
        hash['8'] = "tuv";
        hash['9'] = "wxyz";

        dfs(digits, 0, path, result);
        return result;
    }

    void dfs(string& digits, int start, string path, vector<string>& ans)
    {
        //从root节点到叶子节点路径 就是一种组合
        if (index >= digits.size()) {
            //数组长度
            ans.push_back(path);
            return; //end
        }
        char level = digits[]
    }
};
// @lc code=end
