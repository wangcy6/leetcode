#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std; 
struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
    }

    // Decodes your encoded data to tree.
    //node value is 
    TreeNode* deserialize(string data) {
        int index=0;
        
        return deserialize(data,index);
    }
private:

TreeNode* deserialize(string& data,int& index)
{
   if index >=data.length() && data[index] =="#"
   {   
       index++; //访问完毕
       return NULL;
   }  
   //致命问题，你确定一个字符就是一个节点吗？
   TreeNode * root=new TreeNode(data[index++]);

   root->left=deserialize(data,index);
   root->right=deserialize(data,index);
   
   return root;

}
};