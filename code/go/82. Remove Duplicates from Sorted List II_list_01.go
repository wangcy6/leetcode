package main

/**
1
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3

2 说出的问题
 删除所有含有重复数字的节点---最后一个重复元素怎么删除， 需要一个变量记录上个元素变量

 **/
func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	key := head.Val
	var temp *ListNode

	if head.Val == head.Next.Val {
		for head != nil && key == head.Val {

			//代码错行 公共变量 都可以修改
			/**
			temp = head
			temp.Next = nil
			//delete temp
			head = head.Next**/
			temp = head
			head = head.Next

			//delete
			temp.Next = nil
			//delete temp

		}
		return deleteDuplicates(head) //链表的新节点需要继续寻找

	} else {
		head.Next = deleteDuplicates(head.Next) //head 就是链表的新节点
		return head
	}
}
