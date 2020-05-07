/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (28.00%)
 * Likes:    369
 * Dislikes: 0
 * Total Accepted:    59.1K
 * Total Submissions: 208.9K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 
 * 假设一个二叉搜索树具有如下特征：
 * 
 * 
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
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
 * 思路：中序遍历 是升序
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
       
      if ( root ==NULL)
      {
          return true;
      }
       
      TreeNode* preNode = NULL;

      stack<TreeNode*> path;

       
      while(root !=NULL || !path.empty())
      {
          while (root !=NULL )
          {
              path.push(root);
              root = root->left;
          }
          
          if(!path.empty() )
          {
           
             root = path.top();
             path.pop();

             if (preNode ==NULL)
             {
                //第一个节点 不需要比较
             }else
             {
                 if (preNode->val >= root->val)
                 {
                     return false;
                 }
                 
             }
             
             
             //变化
             preNode =root;
             root =root->right;

          }
         
      }

      return true;  
        
    }
};
// @lc code=end

