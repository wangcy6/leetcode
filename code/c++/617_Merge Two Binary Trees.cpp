
/**
617. 合并二叉树
https://leetcode-cn.com/problems/merge-two-binary-trees/

方法1 中序递归
递归子问题是:2个点的合并（root节点），然后合并左右子树。才是完成逻辑。
1 利用入栈时候， 从上到下传入2个节点 来构造一个新的tree。 
说明：
a 如果2个tree形状不一致，这层次遍历就结束了。后面整个遍历也结束。
b 如果一致性。这仅仅修改当前节点，当前节点左右子树位置并没有发生变化

2 递归构造新树左右子树。
说明。遍历到当前节点，步骤1完成合并逻辑。重新构造对应左子树，然后做子树的做子树。
3 利用出栈时候，返回的时候 新的tree。
 说明：新的tree也可能是另外一个tree的子树
time:o(n) 48 ms	
space:o(n) 13.7 MB
**/

class Solution1 {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        
     if(NULL ==t1)
     {
         return t2;
     }
     if(NULL == t2 )
     {
         return t1;
     }
     //都存在
     t1->val+=t2->val;

     t1->left=mergeTrees(t1->left,t2->left);
     t1->right=mergeTrees(t1->right,t2->right);
     //delete t2;
     return t1;
    }
};

/**
617. 合并二叉树
https://leetcode-cn.com/problems/merge-two-binary-trees/

测试用例：
1 t1 只有做左树，t2只有右子树

方法2
1. 采用合适遍历方式 -从直观上判断，采用bfs遍历比较合适
二叉树2个遍历方式：
dfs（你理解中序遍历） 利用数据结构就是栈（保存历史轨迹）。
特点是下到上遍历。
bfs（你理解成层次遍历）,利用数据结构是队列(保存下一个访问数据)。
特点从上到下遍历。
从直观上判断，采用bfs遍历比较合适

2 BFS非遍历方式算法描述 
1 初四化： 
为了保持结构一致，定义一个队列结构q，2个root节点同时入队列 ,用vecotr存储[0]  表示t1.
（为什么不2个，因为队列还是栈无法区分该节点是子节点右节点）
2  出队列操作：
   第一次出队列的数据就是root节点。是返回结果。
   合并逻辑：
   如果t1节点左/右子树不存在，该最有节点层遍历结束。
3 入队列操作：
   如果节点t1 左右子树存在，左右子树入队列 

 4 重复步骤2和3 直到队列为空。


time:o(n) 
space:o(n)
 
**/

class Solution2 {
public:

   
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {  
      //t2合并到t1上,t1必须存在,如果不存在就结束。
      if(t1 ==NULL)
      {
          return t2;
      }
     vector<TreeNode*> node(2);
     node[0]=t1;
     node[1]=t2;

     queue<vector<TreeNode*>> data;
     data.push(node); //第一次出队列的数据就是root节点.
     

     while(!data.empty())
     {
         //出队列操作
         vector<TreeNode*> temp=data.front();
         data.pop();

         TreeNode*pt1=temp[0];
         TreeNode*pt2=temp[1];
         if(pt2==NULL)
         {
            continue;//维持pt1结构不变
            
         }
          //pt1如果null 是不入队列的。
          pt1->val+=pt2->val; // 结构不变，只修改节点数值
          //
         if(pt1->left ==NULL)
         {
            pt1->left =pt2->left; //结构发生生变化，不能如队列。该节点遍历将结束。
         }else
         {
             node[0]=pt1->left;
             node[1]=pt2->left;
             data.push(node); //结构不变，可以入队列操作

         }
 
        if(pt1->right ==NULL)
         {
            pt1->right =pt2->right; //结构发生生变化，不能如队列。该节点遍历将结束。
         }else
         {
             node[0]=pt1->right;
             node[1]=pt2->right;
             data.push(node);

         }
     }
    
     return t1;
    }
};