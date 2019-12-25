/*
 * @lc app=leetcode.cn id=66 lang=golang
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (42.03%)
 * Likes:    390
 * Dislikes: 0
 * Total Accepted:    101.9K
 * Total Submissions: 241.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */
 class Solution {
	public:
		 //[ 9 9 9] 
		vector<int> plusOne(vector<int>& digits) {
			vector<int> res;
			int length =digits.size();
			if (0 == length) return res;
	
			int sum =0;//返回值
			//倒顺遍历
			for ( int i=length-1;i>=0;i--)
			{
			  sum +=digits[i]; // 累加
			  if (i == length-1) sum+=1; //最后一个+1
			 //cout<< sum<<endl;
			  res.push_back(sum%10);
			  sum/=10;
			  //cout<< sum<<endl;
	
			}
	
			if (sum ==1)
			{
				res.push_back(1);
			}
			reverse(res.begin(),res.end());
			return res;
		}
	};
// @lc code=start
func plusOne(digits []int) []int {
    
}
// @lc code=end

class Solution {
	public:
		ListNode* plusOne(ListNode* head) {
			if (head == NULL) return head;

			int ret =dfs(head);
			if (1== ret){
				ListNode *ptr =new ListNode(1);
				ptr->next =head;
				return ptr;
			}
			rentur head;

		}
        //返回该节点进位数，有依赖关系
		int dfs(ListNode *node){
			if ( node == NULL ) return 1;
			
			int result =dfs(node->next);
			result+=node->val;

			node->val =result%10;
			return result/10;
		}


	};
