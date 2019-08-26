
/** 
 * 863 all-nodes-distance-k-in-binary-tree/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//递归实现2 
class Solution2 {
private:
	vector<int> m_data;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    	
    	m_data.clear();
    	dfs(root,target,K);
        return m_data;
    }
    
    //计算从root节点到target距离，  负数代表不存target节点. 
    int dfs(TreeNode* root, TreeNode* target, int k)
    {
    	if (NULL == root) return -1;//全部都找遍了，还找到肯定就是没有了
    	
    	if ( root == target)
    	{   
    		getKNodes(root,k); ////与target 距离k个元素在左右子树方向
    		return 0; //从target开始计算
    	}
    	
        //递归
    	int left  = dfs(root->left,target,k);
    	int right = dfs(root->right,target,k);
    	
		//target 在做子树
		if (left >= 0)
		{    
			if (left == k-1 )
		     {
			   m_data.push_back(root->val); //与target 距离k个元素至少四个方向 的paernt方向
		     }
			 
			getKNodes(root->right,k-left-2);//与target 距离k个元素至少四个方向 的同辈方向
			
			return left +1;
		}
    	//target 在做右子树
    	if (right >= 0)
		{    
			if (right == k-1 )
			{
				m_data.push_back(root->val); 
			
			getKNodes(root->left,k-right-2);
						
			return right +1;
		}
        
    	//target 没有找到
    	
    	return -1;
		
    }
    //获取二叉树root节点第k层所有元素
    void getKNodes(TreeNode* root,int k)
    {
    	if ( NULL == root || k < 0) return ;
    	if ( 0 == k) m_data.push_back(root->val);
    	
    	getKNodes(root->left,k-1);
    	getKNodes(root->right,k-1);
    }
};

//递归实现1 下面是错误代码，但是值得吸取教训。 
class Solution {
private:
	int m_targt;//判断targe位置 left，right
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    	
    	
        
    }
    
    /************************************************* 
    Function:   dfs     
    Description:    递归遍历 
    Input:     
    Output:
		isDown
		down：递归入栈传递数据
		isUP
		up：  递归出栈返回数据       
             
    Return:  out
    *************************************************/ 
    void dfs(TreeNode* root, TreeNode* target, int K,bool isDown,int down,bool isUP,int &up,vector<int>& out)
    {
    	if (NULL == root) ;//没有找到目标节点
    	if (true == isFind) 
    	{
    		down --;
    	}
    	if (root->val == target->val )
    	{
    		isDown = true;
    		down = k;
    	}
    	if (down == 0)
    	{
    		out.push_back(root->val);
    	}
    	
    
		//拦路虎1：
		//问题：回忆历史题目 求tree的高度，虽然每个节点看成root，但是调用最入口root是固定比较容易，但是这个题目，因为具体k不一定相对root的 卡住了
		//办法：写不出来，不能停留处于僵局状态，吧你能做一步做出来看看
		//用你直接思路，直接定义2个变量，相对每个root节点的。一个是 target-root距离m，一个root与k-n
    	int right =0 ;
    	int left = 0;
    	bool bleft = false;
    	bool bright =false;
    	dfs(root->left,target,K,isDown,bleft,left,out);
    	dfs(root->right,target,K,isDown,bright,right,out);
    	
		//拦路虎2：写不出来，不能停留处于僵局状态
    	//感觉：写到这里感觉出问题了，不敢脑洞了。bleft||bright 写在一块不对，统一都都向上反馈结果方式，另外一个就必须向下？卡住了。
		//你的思路是，m_targt区分，一个是 target-root距离m，一个root与k-n
    	//用m_targt变量标记 返回结果左右这地方出问题了，无法区分
    	    
    	if ( (bleft||bright) && left+right ==k)
    	{
    		out.push_back(root->val);
    		
    	} 
		//拦路虎3：写不出来，不能停留处于僵局状态
		//感觉：你返回值的方式有问题。但是找不到如何解决。
    	//回忆:如果是求最长路径，左右2个子树，返回最大一个，这个返回：左右子树那个呢？看例子
    	return isFind || bleft || bright;
    }
};