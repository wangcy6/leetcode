import "math"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isBalanced(root *TreeNode) bool {

	return isBalancedTree(root) != -1
}
func isBalancedTree(root *TreeNode) int {
	if root == nil {
		return 0 // end
	}
	left := isBalancedTree(root.Left)
	right := isBalancedTree(root.Right)
	//左右子树是平衡二叉树
	if left == -1 || right == -1 {
		return -1
	}
	//左右子树深度不能超过1
	if math.Abs(float64(left)-float64(right)) > 1 {
		return -1
	}

	depth := 1 + math.Max(float64(left), float64(right))
	return int(depth)
}