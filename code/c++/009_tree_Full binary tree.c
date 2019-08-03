
/*Check if the binary tree is a complete  binary tree
*/

#include<iostream>
#include<conio.h>
using namespace std;

struct BinaryTree
{
    int data;
    struct BinaryTree *left;
    struct BinaryTree *right;
};
typedef struct BinaryTree node;

node* insert(node *r,node *z)
{
    if(!r)
    return z;

    if(z->data < r->data)
    r->left=insert(r->left,z);

    else
    r->right=insert(r->right,z);

    return r;
}

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
	int total=isCompleteBinary(root);

   return is_complete_binary(root,1,total);
	
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


bool isFullBinaryTree( node *root) 
{ 
    if(!root) 
    return true; 
    if((root->left && !root->right)||(root>right && !root->left)) 
    return false; 
    return(isFullBinaryTree(R->lef)&&isFullBinaryTree(R->right)); 
}

int main()
{
    int i,h=0;
    node *root=0,*newnode;
    int a[10]={5,9,7,3,1,4,12,13,0,6};

    for(i=0;i<;7;i++)
    {
        newnode=new node;
        newnode->data=a[i];
        newnode->left=newnode->right=0;

        root=insert(root,newnode);
    }
    cout<<isFullBinaryTree(root);
}