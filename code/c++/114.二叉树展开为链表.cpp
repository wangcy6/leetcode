/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (65.90%)
 * Likes:    208
 * Dislikes: 0
 * Total Accepted:    18.6K
 * Total Submissions: 28.2K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为链表。
 *
 * 例如，给定二叉树
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 *3   4   6
 *
 * 将其展开为：
 *
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
/**
 * 理解
 * 1 输入二叉树root开始节点，最后输出的也是链表root的开始节点
 * 2. 递归子逻辑是什么，从上到下还是从下到上？？？
 *     必须root为一层处理，根本可能处理全部left子树。
 *    从上到下转换到递归子问题 。
 * 2. 采用递归逻辑 先： 中 ，后（对啦）
 * 3. 递归子问题：
 * ⁠ 2  
 * ⁠/ \  
 *3   4
 * 4. 返回值是什么?null 
 *
 */
/**
 * 算法描述
 * 根据例子，你已经发现
 * 1 如果将一个二叉树root转换成一个链表。
 *   （三部曲）
 *  a 只需要将已经转换好的root.left 最后一个元素，指向 已经转换好的root.right 开始节点
 *  b 然后整个左子树 存放到原来右子树位置 c root.left =Null
 * 2. 如何root节点知道 获取root.left一个二叉树先序遍历最后一个元素.
 * 3. 转换最小子问题
 *  如果是叶子节点，那就是它了，
 *   如果非叶子节点，优先返回右子树的最后一个位置
 *  也可能是左子树返回值 最后一个位置
 *    1
 *   /  \
 *  2    3    1  2 3
 *
 * time: o(n)
 */
class Solution {
public:
  void flatten(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    dfs(root);
  }

  TreeNode *dfs(TreeNode *pRoot) {
    if (NULL == pRoot) {
      return pRoot; //最基本情况1 
    }

    TreeNode *pLeft = dfs(pRoot->left);   //返回先序遍历最后一个元素
    TreeNode *pRight = dfs(pRoot->right); //返回先序遍历最后一个元素
    if (pLeft != NULL) {
      pLeft->right = pRoot->right; // 1
      pRoot->right = pRoot->left;
      pRoot->left = NULL;
    }
    //最基本情况2
    if (pRight != NULL)
      return pRight;
    if (pLeft != NULL)
      return pLeft; //最基本情况3
    return pRoot;   //最基本情况4
  }
};
// @lc code=end
