class Solution {
public:
	/**
		Input: 1->2->3->4->5->NULL, k = 2
		Output: 4->5->1->2->3->NULL
		Explanation:
		rotate 1 steps to the right: 5->1->2->3->4->NULL
		rotate 2 steps to the right: 4->5->1->2->3->NULL
	
	 1 找到4节点位置
	 
	 2 然后将5节点位置连接到head上
	 
	**/
    ListNode* rotateRight(ListNode* head, int k)
	{
        if (head == NULL || head->next == NULL || k == 0)
			return head;

		ListNode* node = head;
		int size = 1;

		while (node->next != NULL) {
			size++;
			node = node->next;
		}

		//loop the list
		node->next = head;

		//handle the case of k>size
		k = k % size;

		//find the node to break the loop at
		while (--size >= k) {
			node = node->next;
		}

		ListNode* first = node->next;
		node->next = NULL;

		return first;
    }
};
/** 错误答案
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head ==NULL ||head->next==NULL ||k ==0)
        {
            return head;
        }
        ListNode* pCur=head;
        ListNode* phead=head;
        ListNode* temp=NULL;
        int n=k-1;
        
        while(pCur && pCur->next && n-->0 )
        {   
            temp=pCur;
            pCur=pCur->next;
            phead=pCur;
        }
        
        while(pCur && pCur->next)
        {   
            temp=phead;
            pCur=pCur->next;
            
            phead==phead->next;
        }
        
        temp->next=NULL;
         pCur->next=head;
        
         return phead;
        
    }
};
**/