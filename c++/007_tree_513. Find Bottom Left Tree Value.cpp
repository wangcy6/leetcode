
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
    int findBottomLeftValue(TreeNode* root)
    {
        int depth=0;
        int result=0;
        findBottomLeftValue(root,depth,1,result);
        return result;
    }
    
    void findBottomLeftValue(TreeNode* root,int& depth,int level,int& result){
        //递归结束条件 
	   if (NULL ==root)
        {
            return ;
        }
        
		//左子树访问完毕，在访问root节点
        findBottomLeftValue(root->left,depth,level+1,result);         
         		 
		//非叶子节点，肯定不是最后一层的元素，
		//同层的节点元素，最左面第一个元素最左的节点
        if (level>depth && root->left ==NULL)
        {
            depth=level;
            result=root->val;
        }
        findBottomLeftValue(root->right,depth,level+1,result);
    }
    
    
};


/**
* 错误代码
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root)
    {
        int result=0;
        int total=1;
        findBottomLeftValue(root,total,1,result);
        return result;
    }
    
    void findBottomLeftValue(TreeNode* root,int& total,int level,int& result){
        if (NULL ==root)
        {
            return ;
        }
         //[1,2,3,4,null,5,6,null,null,7]
         if(total ==level)
         {
            result =root->val;       
         }
        
        total++;
        findBottomLeftValue(root->left,total,level+1,result);
        findBottomLeftValue(root->right,total,level+1,result);
    }
    
    
};