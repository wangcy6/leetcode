
/**
617. 合并二叉树
https://leetcode-cn.com/problems/merge-two-binary-trees/

方法1 递归
递归子问题是:2个点的合并（不是2个节点的交换）
1 利用入栈时候， 从上到下传入2个节点 来构造一个新的tree 。
2 递归构造新树左右子树。
说明 用原来的左节点来构造左节点
3 利用出栈时候，返回的时候 新的tree。
 说明：新的tree也可能是另外一个tree的子树
 
time:o(n)
space:o(n)
**/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        
     if(NULL ==t1)
     {
         return t2;
     }
     if(NULL == t2 )
     {
         return t1;
     }
     //都存在
     t1->val+=t2->val;

     t1->left=mergeTrees(t1->left,t2->left);
     t1->right=mergeTrees(t1->right,t2->right);
     //delete t2;
     return t1;
    }
};