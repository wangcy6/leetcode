
/** 148
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 https://leetcode.com/problems/sort-list/
 输入: 4->2->1->3
 输出: 1->2->3->4
 */
class Solution {
public:

    //直接插入排序，链表翻转的升级版
    ListNode* sortList_insert(ListNode* head) 
    {
          if ( head == NULL) return head;
          //有序链表第一节点默认为head
          ListNode* start=NULL;
          ListNode* end=head;

          ListNode dump(-1);//课本上都用
          dump.next=head;
          start=&dump; //head->next代表含义 和stat->next代表含义不一样

          ListNode* cur=NULL;
          ListNode* temp=NULL;
          
          while (end && end->next)
          {
              if (end->next->val > end->val)
              {
                  end=end->next;//升序
                  continue;
              }
              //寻找位置
             temp=end->next;
             end->next =end->next->next;//顺序链表最有一个节点位置不变，变化是next
          
            for (cur=start;cur->next->val<temp->val;cur=cur->next)
            {
               
            }

            //插入
            temp->next=cur->next; //任务交接你
            cur->next=temp;//我只管你 

          }

          return dump.next;

    }

     ListNode *sortList_merge(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        //快慢指针得到中间点
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        //将链表拆成两半
        fast = slow->next;
        slow->next = NULL;

        //左右两半分别排序
        ListNode* p1 = sortList(head);
        ListNode* p2 = sortList(fast);

        //合并
        return merge(p1, p2);
    }

    ListNode *merge(ListNode* l1, ListNode* l2) {
        if(!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        } else if (!l1 && !l2) {
            return NULL;
        }

        ListNode dummy(0);
        ListNode* p = &dummy;

        while(l1 && l2) {
            if(l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }

            p = p->next;
        }

        if(l1) {
            p->next = l1;
        } else if(l2){
            p->next = l2;
        }

        return dummy.next;
    }
};