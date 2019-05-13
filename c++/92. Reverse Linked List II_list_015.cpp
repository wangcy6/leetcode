
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
       //合法的输入
	   if(head ==NULL ||head->next ==NULL ||m >=n )
	   {
		   return head;
	   }
	   //反转链表范围
	   ListNode* start=head; 
	   ListNode* end=NULL;
	   //翻转的过程
	   ListNode* cur=NULL;
	   ListNode* next=NULL;
	   
	   //02 移动m-1个距离
	   for(int i=0;i<m-1 && start;i++)
	   {
		   start=start->next;
	   }
	   
	   
    }
};

























class Solution {
public:
   ListNode* reverseBetween(ListNode* head, int m, int n) 
   {
       ListNode *dummy = new ListNode(0), 
	   ListNode *pre = dummy, 
	   ListNode *cur=NULL;
	   
       dummy -> next = head;
       for (int i = 0; i < m - 1; i++) {
           pre = pre -> next;
       }
       cur = pre -> next;
       for (int i = 0; i < n - m; i++) {
           ListNode* temp = pre -> next;
           pre -> next = cur -> next;
           cur -> next = cur -> next -> next;
           pre -> next -> next = temp;
       }
       return dummy -> next;
   }
};
/**
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
**/
public ListNode reverseBetween(ListNode head, int m, int n) {
    if(head == null) return null;
    ListNode dummy = new ListNode(0); // create a dummy node to mark the head of this list
    dummy.next = head;
    ListNode pre = dummy; // make a pointer pre as a marker for the node before reversing
    for(int i = 0; i<m-1; i++) pre = pre.next;
    
    ListNode start = pre.next; // a pointer to the beginning of a sub-list that will be reversed
    ListNode then = start.next; // a pointer to a node that will be reversed
    
    // 1 - 2 -3 - 4 - 5 ; m=2; n =4 ---> pre = 1, start = 2, then = 3
    // dummy-> 1 -> 2 -> 3 -> 4 -> 5
    
    for(int i=0; i<n-m; i++)
    {
        start.next = then.next;
        
		then.next = pre.next;
        pre.next = then;
		
        then = start.next;
    }
    
    // first reversing : dummy->1 - 3 - 2 - 4 - 5; pre = 1, start = 2, then = 4
    // second reversing: dummy->1 - 4 - 3 - 2 - 5; pre = 1, start = 2, then = 5 (finish)
    
    return dummy.next;
    
}