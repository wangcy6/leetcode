package main

import (
	"bytes"
	"fmt"
)

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func LeftLeaves(root *TreeNode, pre *TreeNode) int {

	if root == nil {
		return 0
	}
	if (root.Left == nil && root.Right == nil) && pre.Left == root {
		return root.Val
	}

	return LeftLeaves(root.Left, root) + LeftLeaves(root.Right, root)

}
func PirntTree(root *TreeNode) {
	if root == nil {
		return
	}
	fmt.Println(root.Val)
	PirntTree(root.Left)

	PirntTree(root.Right)

}

/**
        3
    1      4
       2     2
**/
func InitTreeByInput() (root *TreeNode) {
	rootNode := TreeNode{Val: 3}
	l1 := TreeNode{Val: 1}
	r1 := TreeNode{Val: 4}
	r2 := TreeNode{Val: 2}
	r3 := TreeNode{Val: 2}
	r4 := TreeNode{Val: 2}
	rootNode.Left = &l1
	rootNode.Right = &r1
	r1.Left = &r2
	r1.Right = &r3
	r3.Left = nil
	r3.Right = &r4
	return &rootNode
}

//https://leetcode-cn.com/problems/delete-node-in-a-bst/description/

func test() {
	var array []int
	fmt.Println(len(array)) //0
	//array[0] = 1            // index out of range
	//array = append(array, 1)
	array = make([]int, 1)            //明确知道 大小
	fmt.Println(len(array), array[1]) //0
}

/**
func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}**/
func min(a int, b int) int {
	if a > b {
		return b
	}
	return a
}

type Bitmap struct {
	words  []uint64
	length int
}

func New() *Bitmap {
	return &Bitmap{}
}
func (bitmap *Bitmap) Has(num int) bool {
	word, bit := num/64, uint(num%64)
	return word < len(bitmap.words) && (bitmap.words[word]&(1<<bit)) != 0
}

func (bitmap *Bitmap) Add(num int) {
	word, bit := num/64, uint(num%64)
	for word >= len(bitmap.words) {
		bitmap.words = append(bitmap.words, 0)
	}
	// 判断num是否已经存在bitmap中
	if bitmap.words[word]&(1<<bit) == 0 {
		bitmap.words[word] |= 1 << bit
		bitmap.length++
	}
}

func (bitmap *Bitmap) Len() int {
	return bitmap.length
}

func (bitmap *Bitmap) String() string {
	var buf bytes.Buffer
	buf.WriteByte('{')
	for i, v := range bitmap.words {
		if v == 0 {
			continue
		}
		for j := uint(0); j < 64; j++ {
			if v&(1<<j) != 0 {
				if buf.Len() > len("{") {
					buf.WriteByte(' ')
				}
				fmt.Fprintf(&buf, "%d", 64*uint(i)+j)
			}
		}
	}
	buf.WriteByte('}')
	fmt.Fprintf(&buf, "\nLength: %d", bitmap.length)
	return buf.String()
}

//https://zhuanlan.zhihu.com/p/37285799
