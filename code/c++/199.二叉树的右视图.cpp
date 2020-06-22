/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (63.73%)
 * Likes:    260
 * Dislikes: 0
 * Total Accepted:    50.3K
 * Total Submissions: 78.9K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 * 
 * 示例:
 * 
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1, 3, 4]
 * 解释:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
 * 
 * 
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
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        dfs(root, 0, res); //高度从0开始的
        return res;
    }

    void dfs(TreeNode *root, int level, vector<int> &res)
    {
        if (root == NULL)
            return; //循环结果

        if (level == res.size())
        {
            //二叉树高度从0开始
            //假如当前是i层
            //右视图节点插入一个，res大小发送变化=i+1，同层次无法在插入
            //需要等到level增加一层（i+1） 才能等于 res大小。
            res.push_back(root->val);
        }
        dfs(root->right, level + 1, res);
        dfs(root->left, level + 1, res);
    }
};
// @lc code=end
