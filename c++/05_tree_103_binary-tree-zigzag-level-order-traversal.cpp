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
    /**
	 time:o(n) 4ms
	 space:o(n)
	 
	**/
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
	{
        //vector 频繁动态扩容，会影响性能，最好初始化时候就指定
		int h=height(root);
		vector<vector<int>>data(h);
		dfsTree(root,data,0);
		for(int i=1;i<h;i+=2)
		{
          std::reverse(data[i].begin(),data[i].end()); //遍历完毕，只反转一次
		}
		return  data;
		
    }
	void dfsTree(TreeNode* root,vector<vector<int>>& data,int level)
	{
       if(NULL==root) {
		   return ;
	   }
       data[level].push_back(root->val);
	   dfsTree(root->left,data,level+1); //level++   1
	   dfsTree(root->right,data,level+1);//level++   2 做加了一次 不是同层次了  
	}
	int height(TreeNode *root)
	{
		if (NULL == root)
		{
		  return 0;	
		}
		return 1+max(height(root->left),height(root->right));
	}
};