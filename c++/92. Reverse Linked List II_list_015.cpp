
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
       //合法的输入
	   if(head ==NULL ||head->next ==NULL ||m >=n )
	   {
		   return head;
	   }
	   //反转链表范围
       ListNode dump;
       dump.next=head;
	   ListNode* start=&dump; 
	   ListNode* end=NULL;
	   //翻转的过程
	   ListNode* cur=NULL;
	   ListNode* temp=NULL;
	   
	   //02 移动m-1个距离,start 翻转链表的head
	   for(int i=0;i<m-1 && start;i++)
	   {
		   start=start->next;
	   }

	   end=start->next;//start 保持不变， end保持不变
       cur=end->next;//插入的节点
       for(int i=m;i<n&&cur;i++)
       {
             temp=cur->next;
             end->next=temp;//b->d
             cur->next=start->next;//c-b
             start->next=cur;//a-c
             cur=temp;
       }
        /** 省去temp
       for(int i=m;i<n&&cur;i++)
       {             end=cur->next;

             cur=end->next;
             end->next= cur->next->next;//
             
             cur->next=start->next;
             start->next=cur;
       }
         **/
	    return dump.next;
    }
};










