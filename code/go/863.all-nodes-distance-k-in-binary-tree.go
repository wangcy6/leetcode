// 863.all-nodes-distance-k-in-binary-tree.go
package main

/**
 * 863-all-nodes-distance-k-in-binary-tree
算法
深度优先遍历所有节点。
定义方法 dfs(node)，这个函数会返回 node 到 target 的距离。在 dfs(node) 中处理下面四种情况：

如果 node == target，把子树中距离 target 节点距离为 K 的所有节点加入答案。

如果 target 在 node 左子树中，假设 target 距离 node 的距离为 L+1，找出右子树中距离 target 节点 K - L - 1 距离的所有节点加入答案。

如果 target 在 node 右子树中，跟在左子树中一样的处理方法。

如果 target 不在节点的子树中，不用处理。

*/
func distanceK(root *TreeNode, target *TreeNode, K int) []int {

	data := make([]int, 0) //data is null ptr
	dfsDistanceK(root, target, K, &data)
	return data
}

// Returns the distance from root to target.
// Returns -1 if target does not in the tree.
func dfsDistanceK(root *TreeNode, target *TreeNode, k int, data *[]int) int {
	if nil == root {
		return -1
	}
	if target == root {
		getKNode(root, k, data) //child
		return 0
	}

	left := dfsDistanceK(root.Left, target, k, data)
	right := dfsDistanceK(root.Right, target, k, data)
	// Target in the left subtree
	if left >= 0 {
		if left == k-1 {
			*data = append(*data, root.Val) //parent
		}
		getKNode(root.Right, k-left-2, data) //right
		return left + 1
	}

	// Target in the right subtree
	if right >= 0 {
		if right == k-1 {
			*data = append(*data, root.Val) //parent
		}
		getKNode(root.Left, k-right-2, data) //right
		return right + 1
	}

	return -1
}

// Collect nodes that are k steps from root
func getKNode(root *TreeNode, k int, data *[]int) {
	if root == nil || k < 0 {
		return
	}
	if k == 0 {
		*data = append(*data, root.Val)
	}
	getKNode(root.Left, k-1, data)
	getKNode(root.Right, k-1, data)

}
