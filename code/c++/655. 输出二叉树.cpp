// 655. Print Binary Tree
class Solution {
public:
  vector<vector<string>> printTree(TreeNode *root) {
    int rows = get_height(root);
    int cols = pow(2, m) - 1; // cols is all nodes of tree
    cout << "rows:" << rows << " cols:" << cols << endl;
    vector<vector<string>> res(rows, vector<string>(cols, ""));
    dfs(root, res, 0, 0, n - 1);
    return res;
  }

  void dfs(TreeNode *root, vector<vector<string>> &res, int row, int start,
           int end) {
    if (!root || (start > end))
      return;
    int mid = (start + end) >> 1;
    res[row][mid] = to_string(root->val);
    dfs(root->left, res, row + 1, start, mid);
    dfs(root->right, res, row + 1, mid + 1, end);
  }

  int get_height(TreeNode *root) {
    if (!root)
      return 0;
    return std::max(get_height(root->left), get_height(root->right)) + 1;
  }
};