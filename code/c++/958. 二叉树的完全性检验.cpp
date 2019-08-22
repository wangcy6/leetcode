/**
 * 958. Check Completeness of a Binary Tree
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * time:O(N)
 */
class Solution {
public:
  bool isCompleteTree(TreeNode *root) {
    if (NULL == root)
      return true;
    int nodes = nubmerOfNodes(root);
    return dfs(root, 1, nodes);
  }

  bool dfs(TreeNode *root, int level, int &total) {
    if (NULL == root)
      return true;
    if (level > total)
      return false;
    //完全二叉树的性质
    bool isComp = dfs(root->left, 2 * level, total) &&
                  dfs(root->right, 2 * level + 1, total);
    return isComp;
  }
  //
  int nubmerOfNodes(TreeNode *root) {
    if (NULL == root)
      return 0;
    return 1 + nubmerOfNodes(root->left) + nubmerOfNodes(root->right);
  }
};
