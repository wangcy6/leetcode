/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 *
 * https://leetcode-cn.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (55.30%)
 * Likes:    173
 * Dislikes: 0
 * Total Accepted:    31.4K
 * Total Submissions: 56.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 计算给定二叉树的所有左叶子之和。
 *
 * 示例：
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 *
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
 *
 * o
 */
class Solution {
public:
    //8ms
    int sumOfLeftLeaves(TreeNode* root)
    {
        //case1 [1] 1 只有一个节点 不是左叶子，返回0
        return dfs(root, false);
    }
    int dfs(TreeNode* root, bool flag)
    {
        if (NULL == root) {
            return 0; // 递归退出条件
        }
        //给我一个叶子节点根本不清楚自己是left还是right
        if (NULL == root->left && NULL == root->right && flag == true) {

            return root->val; // 递归退出条件
        }
        //只有root节点知道
        return dfs(root->left, true) + dfs(root->right, false);
    }
};

func sumOfLeftLeaves(root* TreeNode) int {

    return dfs(root, false)
}

func dfs(root* TreeNode, left bool) int
{
    //不是判断叶子节点，这里判断root ==nil 干什么，case [1],[nil]
    if nil
        == root
        {
            return 0
        }

    if nil
        == root.Left&& nil == root.Right && true == left
        {
            return root.Val
        }
    //切记 每个节点全部遍历,通过root节点是无法判断整个tree情况
    return dfs(root.Left, true) + dfs(root.Right, false)
}
// @lc code=end
