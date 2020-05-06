package main

import (
	"fmt"
	"strconv"
	"strings"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 生成树结构
func CreateTestData(data string) *TreeNode {
	if data == "[]" {
		return nil
	}
	data = string([]rune(data)[1 : len(data)-1])
	res := strings.Split(data, ",")
	length := len(res)
	treeNode := make([]*TreeNode, length)
	for i := 0; i < length; i++ {
		if res[i] != "nil" {
			val, err := strconv.Atoi(res[i])
			if err != nil {
				panic(err)
			}
			treeNode[i] = &TreeNode{val, nil, nil}
		}
	}
	for i := 0; i < length; i++ {
		if treeNode[i] != nil {
			leftIndex := i*2 + 1
			if leftIndex < length && treeNode[leftIndex] != nil {
				treeNode[i].Left = treeNode[leftIndex]
			}
			rightIndex := leftIndex + 1
			if rightIndex < length && treeNode[leftIndex] != nil {
				treeNode[i].Right = treeNode[rightIndex]
			}
		}
	}
	return treeNode[0]
}

const spce = "      "

// 打印树
func Print(root *TreeNode) {
	treeNodePrint(root, 0)
}

func treeNodePrint(node *TreeNode, deep int) {
	if node == nil {
		printSpace(deep)
		fmt.Println("#")
		return
	}
	treeNodePrint(node.Right, deep+1)
	printSpace(deep)
	printNode(node.Val)
	treeNodePrint(node.Left, deep+1)
}

func printSpace(count int) {
	for i := 0; i < count; i++ {
		fmt.Printf(spce)
	}
}

func printNode(val int) {

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

// 打印树
func PrintArray(array []int) {
	for i := 0; i < len(array); i++ {
		fmt.Print(array[i])
	}
	fmt.Println(" ")
}
func PrintArray2(array [][]int) {
	for i := 0; i < len(array); i++ {
		for j := 0; j < len(array[i]); j++ {
			fmt.Print(array[i][j])
		}
		fmt.Println(" ")

	}
	fmt.Println(" ")
}
