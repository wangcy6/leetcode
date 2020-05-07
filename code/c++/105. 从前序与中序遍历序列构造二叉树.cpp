/**
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //数据合法性检验
        if (preorder.size() != inorder.size()) return NULL;
        
        //递归构造一颗树
        return helper(preorder, 0,preorder.size()-1, \
                      inorder,0,inorder.size()-1);
        
    }
    
    TreeNode* helper(vector<int>& preorder,int pStart,int pEnd,vector<int>& inorder,int iStart,int iEnd)
    {   //cout<< pEnd << " "<< pStart  <<  " " <<iEnd << iStart<<endl;
     
        if (pEnd < pStart || iEnd < iStart)
        {
            return NULL;
        }
        TreeNode* root =new TreeNode(preorder[pStart]);
        //根据preorder[pStart]拆分左右子树，并且计算范围
        int mid=iStart ; 
        
        // while (inorder[iStart] != root->val)  //iStart  位置不能发生变化，变化的mid
        while (inorder[mid] != root->val)
        {
            mid++;
        }
        
        int left = mid-iStart;
        //对各自范围构造一棵树
        root->left = helper(preorder,pStart+1,pStart+left,inorder,iStart,mid-1);
       
        root->right = helper(preorder,pStart+left+1,pEnd,inorder,mid+1,iEnd);
        
        return root;
        
    }
    
};