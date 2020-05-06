/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
     balanced-binary-tree
 */
class Solution {
public:
  bool isBalanced(TreeNode *root) { return depthTree(root) != -1; }

  int depthTree(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }

    int left = depthTree(root->left);
    if (left == -1) {
      return -1;
    }
    int right = depthTree(root->right);
    if (right == -1) {
      return -1;
    }

    if (abs(left - right) > 1) {
      return -1;
    }
    return max(left, right) + 1;
  }
};