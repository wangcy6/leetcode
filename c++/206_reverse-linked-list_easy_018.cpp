class Solution {
public:
    /**
	Reverse a singly linked list.

	Example:

	
	Input: 1->2->3->4->5->NULL
	Output: 5->4->3->2->1->NULL
	
	演示 第一节点 如何变成最后一个节点的
	      end cur
		   |  |  
		   |  |
	start->1->2->3->4->5->NULL (初始化)
	
	     
         (3) (2) (1)  发送了3个变化
	start: 2 ->1->3->4->5->NULL  (反转1次后仍然是完整链表)  
	          |  |
		      |  |
			 end cur
	
	（3）（2）     （1）
	start: 3 ->2 ->1->4->5->NULL  (反转2次后仍然是完整链表)  
	               |  |
		           |  |
			       end cur
	
	
		              
	
	理解偏差
	1 结合反转2考虑一下，这是一个链表，不是去构造另外一反转前的链表和反转后的链表，主要上学记住了构造新的链表。理解偏差1
	2 理解偏差2 虽然知道反转第一个节点，变成最后一个阶段，但是根本理解有什么用
	  开始之后1--2
	  最后一个1--NUll
	  循环做好准备 
	3 有没有造成死循环 1 --NULL 产生方式。理解有点模糊 ，还是判断cur是否为null
	
	4.理解偏差3 
	 默认第一个节点是返回第一节点也是最后一个节点，这里无法区分 1->next 含义是开始还end的操作
	 1->next 是怎么变化的
	  
	 复杂度分析

	时间复杂度：O(n)
	空间复杂度：O(1)
		 
	**/
    ListNode* reverseList(ListNode* head) {
	 
	 ListNode start(-1);
	 start.next=head;//保证 start 一定存在，才可以执行start.next
	 
	 ListNode* end=head;//默认第一个节点是翻转链表最后一个节点
	 
	 ListNode* cur=NULL;
	 while(end &&end->next)
	 {
		 cur=end->next;
		 end->next=cur->next;//(1) 1--4
		 cur->next=start.next;//(2) 3-2-1
		 start.next=cur;//(3) // 3-2-1-5
		 
	 }
	 
	 return start.next;
	 
    }
	//递归方法请参考别人实现 https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-by-leetcode/
};