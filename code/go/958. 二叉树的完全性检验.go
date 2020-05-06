package main

/**958. Check Completeness of a Binary Tree
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isCompleteTree(root *TreeNode) bool {
	if root == nil {
		return true
	}
	total := getNodes(root)

	return isCompleteTreeByIndex(root, 1, total)

}

func getNodes(root *TreeNode) int {

	if root == nil {
		return 0
	}

	return 1 + getNodes(root.Left) + getNodes(root.Right)
}

func isCompleteTreeByIndex(root *TreeNode, index int, total int) bool {
	if nil == root {
		return true
	}

	if index > total {
		return false
	}

	return isCompleteTreeByIndex(root.Left, 2*index, total) && isCompleteTreeByIndex(root.Right, 2*index+1, total)
}
