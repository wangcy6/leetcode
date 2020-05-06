/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == NULL) {
      return root; // 结束条件
    }
    if (root == p || root == q) {
      return root;
    }
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left && right) {
      return root;
    }
    //如果都不是返回都不是，如果其中一个是返回其中一个。
    //如果2个都是，肯定不进入到这里 方向的选择一个就可以
    return left ? left : right;
  }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {

    //默认第一有序，如果不存在第一个元素，直接返回
    if (NULL == head || NULL == head->next) {
      return head;
    }
    //定义有序链表
    ListNode *end = head; //结束位置

    ListNode temp(-1);
    ListNode *start = &temp;
    start->next = head; //固定头节点

    ListNode *pre = NULL;
    ListNode *pnext = NULL;

    while (end && end->next) {
      //理想情况 升序，不需要"移动“
      if (end->next->val > end->val) {
        end = end->next;
      } else {
        //在有序链表中寻找插入位置。
        pre = start;
        while (end->next->val > pre->next->val) {
          pre = pre->next;
        }

        //节点翻转
        // pre      end   next
        //|        |     |
        //|        |     |
        // start--- 5 --  4 --- 3 --2 ---1
        pnext = end->next;
        end->next = end->next->next;

        pnext->next = pre->next;
        pre->next = pnext;
      }
    }

    return start->next;
  }
};

ListNode *insertionSortList(ListNode *head) {
  if (head == nullptr || head->next == NULL)
    return head;
  ListNode *h = insertionSortList(head->next);
  if (head->val <= h->val) { // first case
    head->next = h;
    return head;
  }
  ListNode *node = h; // second case
  while (node->next && head->val > node->next->val)
    node = node->next;
  head->next = node->next;
  node->next = head;
  return h;
}

/**
 * 147. Insertion Sort List
 * https://leetcode-cn.com/problems/insertion-sort-list/
 
    input:  6->5->1->8

    第一次：head->5->6-1-8

    第2次：head-1->5->6->8

    第3次：head-1->5->6->8(cur)
    说明：
    cur=8
    是最后一个节点时候，如何移动 
    不需要排序sort。
     cur=cur->next;// 有序数据||最后一个元素 循环结束


 */
class Solution1 {
public:
  ListNode *insertionSortList(ListNode *head) {

    //基本合法检查，还不涉及排序过程
    if (head == NULL || head->next == NULL) {
      return head;
    }

    // 01 依赖空间 
    ListNode first(0); //有序链表头开始部分，固定头节点位置，保证插入节点元素 pre节点一定存在。
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
    first.next = head; //第一默认有序  head->6->5->1->8

    ListNode *cur = head; // 有序链表头结束部分 初始化 默认第一

    ListNode *pre = NULL; //插入排序需要插入记录位置，每次都需要重新计算

    //从第一个元素开始遍历链表，假设第一个元素是有序的
    while (cur) {
      //不是有序数据
      if (cur->next && cur->next->val < cur->val) {
        //寻找插入位置  .
        pre = &first; //从有序链表head开始遍历.次数，pre 指向head节点，没有数据
        while (cur->next && pre->next &&
               cur->next->val > pre->next->val) // head->6->5->1->8
        {
          pre =
              pre->next; // pre->next
                         // 就是插入地方。pre是前面一个节点。存在插入规则，是在固定节点后面插入
        }

        //插入过程 类似节点翻转最前面位置（pre->next 就是插入地方）
        ListNode *temp = cur->next; //记录待插入元素5，head->6->5->1
        cur->next = temp->next; //移除待插入元素5 ，移动下一个元素 head->6->1

        temp->next = pre->next; //待插入元素5后面节点。 
                                //                    5  ->6->1
                                //                    head->6->1

        pre->next = temp; //待插入元素5前面节点。 head->5->6->1
        //这里不需要一定cur=cur->next，移动下一个元素 head->6->1 完成
      } else {
        cur = cur->next; // 有序数据||最后一个元素 循环结束
      }
    }

    return first.next;
  }
};

class Solution2 {
public:
  /*注意if 判断*/
  /**
   * [4,2,1,3]  cur =3的时候 while循环不退出。
   */
  ListNode *insertionSortList(ListNode *head) {

    //基本合法检查，还不涉及排序过程
    if (head == NULL || head->next == NULL) {
      return head;
    }

    // 01 依赖空间 
    ListNode first(0); //有序链表头开始部分，固定头节点位置，保证插入节点元素 pre节点一定存在。
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
                       //
    first.next = head; //第一默认有序  head->6->5->1->8

    ListNode *cur = head; // 有序链表头结束部分 初始化 默认第一

    ListNode *pre = NULL; //插入排序需要插入记录位置，每次都需要重新计算

    //从第一个元素开始遍历链表，假设第一个元素是有序的
    while (cur) {
      //
      if (cur->next && cur->next->val >= cur->val) {
        cur = cur->next; //移动下一个元素  有序数据
      } else if cur->next &&cur->next->val <cur->val)
            {
          //寻找插入位置  .
          pre =
              &first; //从有序链表head开始遍历.次数，pre 指向head节点，没有数据
          while (cur->next && pre->next &&
                 cur->next->val > pre->next->val) // head->6->5->1->8
          {
            pre =
                pre->next; // pre->next
                           // 就是插入地方。pre是前面一个节点。存在插入规则，是在固定节点后面插入
          }

          //插入过程 类似节点翻转最前面位置（pre->next 就是插入地方）
          ListNode *temp = cur->next; //记录待插入元素5，head->6->5->1
          cur->next = temp->next; //移除待插入元素5 ，移动下一个元素 head->6->1
          temp->next = pre->next; //待插入元素5后面节点。 
                                  //                    5  ->6->1
                                  //                   head->6->1

          pre->next = temp; //待插入元素5前面节点。 head->5->6->1
          //这里不需要一定cur=cur->next，移动下一个元素 head->6->1 完成
        }
      else {
        cur = cur->next; //最后一个元素
      }
    }

    return first.next;
  }
};

//上面代码有个问题 都是基于存在不存在，实际情况是基于cur next 存在不存在。

/**
 * https://www.lintcode.com/problem/insertion-sort-list/
 *
 *  **/

class Solution3 {
public:
  /**
   * @param head: The first node of linked list.
   * @return: The head of linked list.
   */
  ListNode *insertionSortList(ListNode *head) {
    //插入排序
    if (head == NULL || head->next == NULL) {
      //少于一个节点不需要排序
      return head;
    }
    // 01 构造带头节点的单链表，默认第一个节点有序

    ListNode start(
        0); //保持头节点不变是为了插入方面，也可以不要，每次寻找pre节点时候 判断一下是否null
            //
            //
            //
            //
            //
            //
            //
            //
            //
            //
            //
            //
            //
            //
            //
            //
            //
            //
            //
            //
            //
            //
    start.next = head;

    ListNode *end = head; //有序链表结束位置，end也是遍历的迭代器  
    ListNode *pre = NULL;  //辅助变量  
    ListNode *temp = NULL; //辅助变量  
    /** 初始状态
     *   input：7--6--5--4--3 -2 -1 
     *
     *  start.next---7--6--5--4--3 -2 -1
     *      |        |  |
     *      |        |  temp
     *      |        end
     *      Pre
     */

    //遍历剩余 未排序的
    while (end) {
      temp = end->next;

      if (end->next == NULL || temp->val > end->val) {
        end = end->next;
        /** 最后一个元素
         *   input：7--6--5--4--3 -2 -1 
         *
         *  start.next---1-2--3--4--5 -6 -7----NUll
         *                                |       |
         *                                |       temp
         *                                end(end没有改变过一次，end=null 结束循环)
         * 
         *
         *
         *
         *
         *
         *
         *
         *
         *
         *
         *
         *
         *
         *
         *
         *
         *
         *
         *
         *
         *
         *
         */
      } else

      /** 第一次排序
       *   input：7--6--5--4--3 -2 -1 
       *
       *   before：
       *   start.next---7--6--5--4--3 -2 -1
       *      |        |  |
       *      |        |  temp
       *      |        end
       *      Pre
       *
       * after：
       * start.next---6----7---5--4--3 -2 -1
       *      |       |    |
       *      |       |    |
       *      |       temp end
       *      Pre
       *
       */
      {
        pre = &start;
        while (pre->next && pre->next->val < temp->val) {
          pre = pre->next; // pre插入位置前一个元素  pre->7
        }
        //插入元素 pre -6-7-5

        end->next = temp->next; // 7---5

        temp->next = pre->next; // 6---7
        pre->next = temp;       // start-6-7-5
      }
    }
    return start.next;
  }
};

//无注释版 
// pre      end   temp
//|        |     |
//|        |     |
// start--- 5 --  4 --- 3 --2 ---1
class Solution4 {
public:
  ListNode *insertionSortList(ListNode *head) {
    if (NULL == head || NULL == head->next) {
      return head;
    }

    ListNode dump(0);
    dump.next = head;
    //初始化
    ListNode *start = &dump;

    ListNode *end = head;

    ListNode *pre = NULL;
    ListNode *temp = NULL;

    while (end && end->next) {
      if (end->next->val >= end->val) {
        end = end->next; //升序
      } else {

        pre = start;
        while (end->next->val > pre->next->val) {
          pre = pre->next;
        }

        temp = end->next;
        end->next = end->next->next;

        temp->next = pre->next;
        pre->next = temp;
      }
    } //最后一个节点时候，前面已经比较完毕了

    return start->next;
  }
};

class Solution5 {
public:
  /**https://leetcode-cn.com/problems/insertion-sort-list/
   *  1 一般的tree和list遍历都是当前节点操作当前节点数值，结构比较清晰，
   *  这里假设第一个节点有序，通过当前节点操作下一个节点，在while时候判断是否最有一个节点可以了。
   *
   **/
  ListNode *insertionSortList(ListNode *head) {

    //默认第一有序，如果不存在第一个元素，直接返回
    if (NULL == head || NULL == head->next) {
      return head;
    }
    //小错误1 把 ||写成了 && 这属于理解错误，只要有一个成立，就成立 基本认知不行呀，如果nll 程序就core了
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //

    //定义有序链表
    ListNode *end = head; //第一节点 默认有序

    ListNode temp(-1);
    ListNode *start = &temp;
    start->next = head; //区分 第一个节点后面含义
    //小错误2 忘记 temp.next 初始化了 这个关键呀，如果没有这个 pre->next->val core了
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    ListNode *pre = NULL;
    ListNode *pnext = NULL;

    while (end && end->next) {
      //理想情况 升序，不需要"移动“
      if (end->next->val > end->val) {
        end = end->next;
      } else {
        //在有序链表start中寻找待插入元素end->next 插入的位置 pre。
        pre = start;

        while (end->next->val > pre->next->val) {
          pre = pre->next;
        }

        //节点翻转
        // pre      end   next
        //|        |     |
        //|        |     |
        // start--- 5 --  4 --- 3 --2 ---1
        pnext = end->next;
        end->next = end->next->next; // 5-3

        pnext->next = pre->next; // 4-5-3
        pre->next = pnext;       // start->4-5-3
      }
    }

    return start->next;
  }
};
