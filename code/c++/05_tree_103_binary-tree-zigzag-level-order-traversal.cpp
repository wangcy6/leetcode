/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：
[
  [3],
  [20,9],
  [15,7]
]

1 看似是层次遍历，肯定不是这个
2 . vector<vector<int>> 必须知道层次大小
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
/**
执行用时 : 8 ms, 在Binary Tree Zigzag Level Order Traversal的C++提交中击败了97.04% 的用户
内存消耗 : 14.4 MB, 在Binary Tree Zigzag Level Order Traversal的C++提交中击败了5.16% 的用户
**/
class Solution2 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
	{
		vector<vector<int>>data;
		dfsTree(root,data,0);
		for(int i=1;i<data.size();i+=2)
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
	   if(level>=data.size())
	   {
		   vector<int> temp;
		   data.push_back(temp);
	   }
	   
		 data[level].push_back(root->val);  
	   
	   dfsTree(root->left,data,level+1); //level++   1
	   dfsTree(root->right,data,level+1);//level++   2 做加了一次 不是同层次了  
	}
};