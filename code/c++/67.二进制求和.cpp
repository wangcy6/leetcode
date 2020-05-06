/*
 * @lc app=leetcode.cn id=67 lang=cpp
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
 *  1 遍历
 *  2 累加 
  * 3 进位
 */

// @lc code=start
class Solution {
public:

string addBinary1(string a, string b)
    {
        string s = "";
        
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }
        
        return s;
    }
    string addBinary(string a, string b) {

        string  out;

        int alen =a.size();
        int blen =b.size();
        
        int i =alen -1;
        int j =blen -1;
        
        int sum =0;

        while (i >= 0 || j >= 0)
        {   
            
             if(i >= 0)
             {  
                 cout<<a[i]<<endl;
                sum+=a[i]-'0';
                i--;
             }    

             if(j >= 0)
             {   
                 cout<<b[j]<<endl;
                sum+=b[j]-'0';
                j--;
             } 
              cout<< "push="<<sum%2<<endl;
            out.push_back(char(sum%2+ '0'));
           
            cout<< "sum="<<sum<<endl;
            sum =sum/2;

            cout<< "sum="<<sum<<endl;
            

        }

        if (sum ==1)
        {
           out.push_back('1');
            cout<< "push=1 "<<endl;

        }
        reverse(out.begin(),out.end());

         return out;
        
    }
};
// @lc code=end

