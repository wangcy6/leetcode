/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (66.40%)
 * Likes:    304
 * Dislikes: 0
 * Total Accepted:    82.7K
 * Total Submissions: 123.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
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
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> result; //result 大小有tree的高度决定
        //因为高度不确定，因此遍历一层插入一个
        dfs(root, 0, result);
        reverse(result.begin(), result.end());
        return result;
    }

    void dfs(TreeNode* root, int level, vector<vector<int>>& result)
    {
        if (nullptr == root) {
            return;
        }

        if (result.size() == level) {
            result.push_back(vector<int>());
            //out_of_range
        }

        //02 保存当前元素。
        result[level].push_back(root->val);
        // reference binding to null pointer of type
        //'std::vector<int, std::allocator<int> >
        //push_back 会自动扩容，[] 不会。
        // if the requested position is out of range by throwing an out_of_range exception
        dfs(root->left, level + 1, result);
        dfs(root->right, level + 1, result);
    }
};

/***
 *  map 不存在就插入，千万别混淆了 vector直接报错，这个代码安全方面考虑周到
 * if f k does not match the key of any element in the container, 
 * the function inserts a new element with that key and returns a reference to its mapped value.
 * 
  std::map<char,std::string> mymap;
  mymap['a']="an element";
  mymap['b']="another element";
  mymap['c']=mymap['b'];
 * **/
// @lc code=end
