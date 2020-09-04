/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (64.94%)
 * Likes:    340
 * Dislikes: 0
 * Total Accepted:    65.3K
 * Total Submissions: 99.3K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
 * 
 * string 如何拼接g
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
思路：

实现：
1. c++操作字符串比较弱，回忆基本字符串操 
  类比vector的操作，但是操作很不方面。引用传递改为值传递。

  

 
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> result;
        string path;
        dfs(root, path, result);
        return result;
    }
    void dfs(TreeNode* root, string path, vector<string>& res)
    {
        if (root == NULL)
            return;
        path.append(to_string(root->val));
        path.append("->");
        if (root->left == NULL && root->right == NULL) {
            path.erase(path.length() - 2);
            res.push_back(path);
        }
        dfs(root->left, path, res);
        dfs(root->right, path, res);
    }
    void dfs1(TreeNode* root, string& path, vector<string>& result)
    {
        // 递归结束条件1
        if (nullptr == root) {
            return;
        }
        //path.push_back(to_string(root->val)); 语法错误
        path.append(to_string(root->val));
        path.append("->");

        //递归结束条件2：
        if (nullptr == root->left && nullptr == root->right) {
            path.erase(path.length() - 2);
            result.push_back(path);
        }

        dfs(root->left, path, result);
        dfs(root->right, path, result);

        path.erase(path.length() - 3); //std::out_of_range
    }
};
// @lc code=end
