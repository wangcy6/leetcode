/**
https://leetcode-cn.com/problems/reverse-linked-list-ii
执行用时 : 8 ms, 在Reverse Linked List II的C++提交中击败了96.84% 的用户
内存消耗 : 8.8 MB, 在Reverse Linked List II的C++提交中击败了42.84% 的用户
**/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        //输入数据都是合法的，不担心
        if(NULL ==head ||NULL ==head->next || m>=n)
        {
            return head;
        }
        
        //m=1时候，m非1时候虽然都是inert。区别head之前还是head之后，
        //标准reids等采用head之后。 一般我也是这样做的，head之前做法上学的。head会频繁的变化。
        //依赖头节点。stl还是其他设计都是一个头节点，方面操作 第一个节点不存入任何信息。
        //链表插入，故意构造一个存在head节点。 解决m数据不确定的情况。
        
        //head 指向第一数据记录，如果翻转的head位置不断发生变化不固定。
        //增加一个带头节点的单链表 减少复杂性操作
        //一般(redis,stl)链表插入都是head之后插入。head指向头节点
        
        ListNode dump(0); //固定的head节点。
        dump.next=head; //加入m=0的话,保持pStart存咋，固定不变。
        
        ListNode*pStart=&dump;
        ListNode*pEnd=head;
        ListNode*pCur=head;

        
        //移动m位置
        for(int i=1;pEnd&&i<m;i++)
        {
            pStart=pStart->next;
            pEnd=pEnd->next;
        }
        // 此时 i=m pStart(m-1)  pEnd(m)
        //排除了m=1时候，不进入循环的情况。 pStart为null
        
        
        //翻转 m到n
        
        for(int i=m;pCur&&i<n;i++)
        {
            pCur=pEnd->next;//需要翻转的节点 / A-B-C-D
            pEnd->next=pEnd->next->next;//循环的下一个节点  A-B-D
            
            pCur->next=pStart->next;// C-B-D
            pStart->next=pCur;//A-C-B-D
        }
        
        return dump.next;
        
    
    }
};


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

/*无注释版
    start end
      |  |      
输入: 1->2->3->4->5->NULL, m = 2, n = 4


输出: 1->4->3->2->5->NULL
     |         | 
     start     end
链表移动不是位置，链表位置是固定不变，修改是内部指针
执行用时 : 4 ms, 在Reverse Linked List II的C++提交中击败了99.11% 的用户
*/
class Solution3 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      if(NULL ==head ||NULL ==head->next ||m>=n)
      {
          return head;
      }
      //寻找地m-1 m个位置
      ListNode* end=head;
      ListNode* start=NULL;
      ListNode dump(-1);
      dump.next=head;
      start=&dump;
      

      for(int i=1;i<m;i++)
      {
       start=end;
       end=end->next;
      }//m=1时候 start没有移动

      ListNode* temp=NULL;
     for(int i=m;i<n;i++)
     {
        temp=end->next;
        end->next=end->next->next;
    
       temp->next=start->next;//
       start->next=temp;
     }

     return dump.next;

    }
};







