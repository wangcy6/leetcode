// 655. 输出二叉树
package main

import (
	"math"
	"strconv"
)

/** 655. Print Binary Tree
Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]

*/
func printTree(root *TreeNode) [][]string {

	rows := getHeight(root)
	cols := math.Pow(2, rows) - 1 // all nodes of tree

	var res [][]string //nil point
	for i := 0; i < int(rows); i++ {
		res = append(res, make([]string, int(cols)))
	}

	dfsPrintTree(root, 0, 0, int(cols)-1, res)

	return res

}

func dfsPrintTree(root *TreeNode, level int, start int, end int, res [][]string) {
	if root == nil || start > end {
		return
	}

	//print root
	mid := (start + end) / 2
	res[level][mid] = strconv.Itoa(root.Val)

	//print left subTree
	dfsPrintTree(root.Left, level+1, start, mid-1, res)
	//print right subTree
	dfsPrintTree(root.Right, level+1, mid+1, end, res)

}

//height of tree
func getHeight(root *TreeNode) float64 {
	if root == nil {
		return 0
	}
	left := getHeight(root.Left)
	rgiht := getHeight(root.Right)
	return math.Max(left, rgiht) + 1
}

/**
func main() {
	tree := CreateTestData("[1,2,3,4]")
	Print(tree)
	fmt.Println("Hello World!")
}**/
