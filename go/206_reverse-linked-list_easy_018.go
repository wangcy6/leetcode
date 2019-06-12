/**
                     head head.next
初四化： 1-->2-->3-->4-->5

                (head)     
第一次：1-->2-->3 ---4
                 5-->4--NUll
				 
第二次：1-->2-->3

         5-->4-3-NULL
		
last次：5-->4-3-2->1NULL
**/
func reverseList(head *ListNode) *ListNode {
    if head ==nil ||head.Next==nil {
	  return head //最后一个节点返回，head==nil为防止输入的为nill
	}
	
	first:=reverseList(head.Next)
	
	head.Next.Next=head //第k个节点放到第k+1后面
	head.Next=nil
	
	return first
}