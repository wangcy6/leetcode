## 题目 完全二叉树



check-completeness-of-a-binary-tree





![image.png](https://upload-images.jianshu.io/upload_images/1837968-ab07842a07e1c387.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)




## 分析

![image.png](https://upload-images.jianshu.io/upload_images/1837968-e4648b7cdb3714f2.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



拦路虎：



完全二叉树 ，不是BST，根据数字大小没有关系。满二叉树相对。

判断节点存在不存在，ptr--null ,这个太难了，这个逻辑关系不好描述



为什么不能直接判断子tree 不存在可以了

![image.png](https://i.loli.net/2020/02/07/XnLA6tUz4dVQyqE.png)


## 答案

```c++
//完全二叉树：

/**

1 Calculate the number of nodes (count) in the binary tree.

2 Start recursion of the binary tree from the root node of the binary tree with index (i) being set as 0 and the number of nodes in the binary (count).

3 If the current node under examination is NULL, then the tree is a complete binary tree. Return true.

4 If index (i) of the current node is greater than or equal to the number of nodes in the binary tree (count) i.e. (i>= count), then the tree is not a complete binary. Return false.

5 Recursively check the left and right sub-trees of the binary tree for same condition. 

For the left sub-tree use the index as (2*i + 1) while for the right sub-tree use the index as (2*i + 2).

6 The time complexity of the above algorithm is O(n). 

**/

bool isCompleteBinary(node *root)

{

​    int total=isCompleteBinary(root);

   return is_complete_binary(root,1,total);

​    

}

bool is_complete_binary(node *root,int index,int& length)

{

   if(root ==NULL)
   {
       return true;
   }
    
   if(index>length)

   {

       
       
       return false;

   }

  return  is_complete_binary(root->left,2*index,length) && is_complete_binary(root->right,2*index+1,length);

}

int get_node_number(node* root)

{

    if(root ==NULL)

    {

        return 0;

    }

    

    return 1+get_node_number(root->left)+get_node_number(root->right);

}
```



c++

~~~c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root)
     {
         int total =getNode(root);


        return isCompleteTree(root,1,total);
     } 

     bool isCompleteTree(TreeNode* root,int index,int total)
     {
         if( root ==NULL)
         {
            return true;
         }

         if(index >total)
         {
            return false;
         }

         return isCompleteTree(root->left,2*index,total) &&isCompleteTree(root->right,2*index+1,total);
     }


     int getNode(TreeNode* root)
     {
         if(root ==NULL)
         {
            return 0;
         }

         return 1+getNode(root->left)+getNode(root->right);
     }   
       
};
~~~



### 错误代码

~~~c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        
        if(root ==NULL)
        {
             return true;
        }
        if(root->left ==NULL && root->right ==NULL)
        {

        }else
        {
            if(root->left ==NULL &&root->right !=NULL )
            {
                   return false; //这个其中的一个情况，
            }
            //left ok right notxt 可以是，可以不是，根本不知道其他的情况
        }

        return  isCompleteTree(root->left) && isCompleteTree(root->right);

    }
};
~~~

