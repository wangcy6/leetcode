#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  /**
   * [3,5,1,6,2,9,8,null,null,7,4]
    [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]

    ## 周期
    25分钟+25分钟 

    ## 复杂度

      执行用时 : 16 ms, 在Leaf-Similar Trees的C++提交中击败了11.11% 的用户
      内存消耗 : 14.1 MB, 在Leaf-Similar Trees的C++提交中击败了0.00% 的用户
   **/
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {

    vector<TreeNode *> a;
    vector<TreeNode *> b;
    dfs(root1, a);
    dfs(root2, b);
    int n = a.size();
    int m = b.size();
    // a b进行比较大小
    if (n != m) {
      return false;
    }

    for (int i = 0; i < n; i++) {
      // a[i].val是不正确的 
          if((a[i]->val !=b[i]->val )
          {
        return false;
          }
    }
    return true;
  }

  void dfs(TreeNode *root, vector<TreeNode *> &result) {
    if (NULL == root) {
      return;
    }
    if (NULL == root->left && NULL == root->right) {
      result.push_back(root);
    }
    dfs(root->left, result);
    dfs(root->right, result);
  }
};

int main() { return 0; }
