package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
func min(a int, b int) int {
	if a > b {
		return b
	}
	return a
}

type ListNode struct {
	Val  int
	Next *ListNode
}
