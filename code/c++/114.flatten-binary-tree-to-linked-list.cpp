

/**
 * 
 优化：一次二叉树遍历 和一次二叉树的合并操作可以优化成一次遍历操作。

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
 观察 
 1. 单链表是二叉树的先序遍历输出结果 
 
 2. 构造链表子问题：只有3个节点的二叉树特点  
  a 单链表第一个节点是：root保持不变
  b 单链表第二个节点：root.righ-> root的left 
  c 单链表第三个节点：先在的root.righ.right->是root的right

3. 每个节点都是一颗二叉树特点
  a 单链表第一个节点是:root保持不变
  b 单链表第二个子树:root.righ-> root左子树
  c 单链表第三个子树:root左子树整个左子树先序遍历最后一个元素.right--> root整个右子树。 4--->5    

说明：
     因此直觉上用队列（层次遍历）是不合适的。只能交换单个节点，后续将无法操作
     根据观察必须遍历整个做子树，在遍历整个右子树，
     因此采用栈作为数据结构存储完成先序遍历非递归操作。


**/
class Solution {
public:
   /**
    * 执行用时 :16 ms 非递归
    * Time complexity : O(n)
    *  Space complexity : O(n)
    */
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return ;
        }

        stack<TreeNode*>  result;
        result.push(root);

        while (!result.empty()){
            TreeNode* cur=result.top();
            result.pop();

            if (cur->right)
            {
              result.push(cur->right);//先顺非递归遍历
            }

            if (cur->left)
            {
              result.push(cur->left);//先顺非递归遍历
            }
            //递归子问题
            if (!result.empty()) 
            {
               cur->right=result.top();
            }

            cur->left=NULL;
        }

    }


     /**
    *  
    * Time complexity : O(n) 执行用时 :12 ms
    *  Space complexity : O(n)
    *  步骤 把一棵树变成单链表  flatten(left)
    *  1 首先把一棵树树的左子树全部变成单链表 flatten(root-left)
    *  2 首先把一棵树树的右子树全部变成单链表 flatten(root-rirht)
    *  3 递归子问题：合并2个链表合并一个单链 
    *   注意： 下一个元素是什么
    *   
    */
    void flatten(TreeNode* root) {
        if (root == NULL) return ;
        
        flatten(root->left);
        flatten(root->right);
        
        //递归子问题
        TreeNode *tmp = root->right;
        root->right = root->left;  //1 root保持不变
        root->left = NULL;

        while (root->right)
        {
            root = root->right;  //2 root原来left最最right元素  
        };
        
        root->right = tmp; //3   root-right->flatten(root-left)->>flatten(root-right)
    }
};