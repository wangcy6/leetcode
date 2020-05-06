/*
 * @lc app=leetcode.cn id=111 lang=golang
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (40.63%)
 * Likes:    185
 * Dislikes: 0
 * Total Accepted:    42.5K
 * Total Submissions: 104.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func minDepth(root *TreeNode) int {
    
}
// @lc code=end
/**
思路是什么？
1 中序遍历，从上到下传递个数
2.如果遇到叶子节点，判断是否最小。
3.结果保存 保存在参数中 

测试
输入:
[3,9,20,null,null,15,7]
输出
-157911776
预期结果
2

**/
class Solution {
	public:
		int minDepth(TreeNode* root) {
			if (root ==NULL)
			{
				return 0;//忘记特殊情况判断，不然每次返回最大值
			}
			//int result = 0; //默认最小值，结果min 永远最小值
			int result =INT_MAX; 
			dfs(root,1,result);
			return result;
		}
		void dfs(TreeNode* root,int depth,int& result)
		{
		   if ( NULL == root)
		   {
			   return ;
		   }
		  // cout<< root->val <<" "<< depth <<endl;
		   if (root->left ==NULL && root->right ==NULL)
		   {
			  result =min(result,depth);
			  cout<< root->val <<" "<< result <<endl;
              return ;
		   }
		   dfs(root->left,depth+1,result);
		   dfs(root->right,depth+1,result);
		}
	};