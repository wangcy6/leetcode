// weekly-contest-127.go
package main

import (
	"fmt"
)

func clumsy(N int) int {
	sum := 0
	cur := N   //data
	index := 0 //operator
	for i := N - 1; i >= 1; i-- {
		if index == 0 {
			cur *= i
		}
		if index == 1 {
			cur /= i
		}
		if index == 2 {
			cur += i
			sum += cur
			cur = 0 // 保证 10*9/8是一个整数
		}
		if index == 3 {
			cur -= i //根据逻辑替换，不需要理解表达式的含义！！！

		}
		index = (index + 1) % 4
	}

	sum += cur
	return sum
}

/**
1008. 先序遍历构造二叉树
题目：
给你一个 二叉搜索树（binary search tree）的先序遍历结果
请还原 这个二叉搜索树

例子：
input:
输入：[8,5,1,7,10,12]
输出：[8,5,10,1,7,null,12]

分析：
1 第一元素就是8就是root 节点
2 5,1,7 就是左节点 10 12 就是右节点
        8(begin)
      /       \
	 /         \
	[5,17]     [10.12]
    [beign+1,mid-1] [mid,end]

3 继续递归 左右子树

4 [4,3]  这样就是返回 null


**/
func bstFromPreorder(preorder []int) *TreeNode {
	return bst_preorder(preorder, 0, len(preorder)-1)
}

func bst_preorder(preorder []int, begin int, end int) *TreeNode {

	if begin > end {
		return nil
	} //end

	//one
	if begin == end {
		root := &TreeNode{preorder[begin], nil, nil}
		return root
	}

	//
	mid := begin + 1
	for ; mid <= end && preorder[mid] < preorder[begin]; mid++ {

	}

	root.Left = bst_preorder(preorder, begin+1, mid-1)
	root.Right = bst_preorder(preorder, mid, end)

	return root
}

func main() {
	fmt.Println(clumsy(10))
}
