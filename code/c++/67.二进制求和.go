/*
 * @lc app=leetcode.cn id=67 lang=golang
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (51.49%)
 * Likes:    275
 * Dislikes: 0
 * Total Accepted:    53.2K
 * Total Submissions: 103.2K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

// @lc code=start
func addBinary(a string, b string) string {
    
}
// @lc code=end
/**
1 遍历2个字符串，
2. 累加 进位
3. 存在到另外一个位置
//别人想着省空间
如果统一管理长度不一样
累加
如果统一管理
a+b=c/2 &/2
**/
class Solution {
	public:
		string addBinary(string a, string b) {
		    string out;
			int alength =a.size();
			int bLength =b.size();
			
			int total =0;
			
			for ( int i=alength-1,int j=bLength-1; i>=0 || j>=0;i--,j--)

			  total +=i>=0?a[i]-'0':0;
			  total +=j>=0?b[j]-'0':0;
			  out.push_back(total%2);
			  out/=2;
		}
        if (total =1) {
			out.push_back('1');
		}

		reverse(out.begin(),out.end());
		return out;

	};