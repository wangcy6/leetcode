## 题目 完全二叉树

![image.png](https://upload-images.jianshu.io/upload_images/1837968-ab07842a07e1c387.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)




## 分析

![image.png](https://upload-images.jianshu.io/upload_images/1837968-e4648b7cdb3714f2.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)






## 答案

```
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

​      return true;

   }

   if(index>length)

   {

​     return false;

   }

  return  is_complete_binary(root->left,2*index,length) && is_complete_binary(root->right,2*index+1,length);

}

int get_node_number(node* root)

{

​    if(root ==NULL)

​    {

​        return 0;

​    }

​    

​    return 1+get_node_number(root->left)+get_node_number(root->right);

}
```

