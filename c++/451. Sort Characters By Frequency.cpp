#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std; 

class Solution {
public:
    /**
    输入:
    "cccaaa"

    输出:
    "cccaaa"

    解释:
    'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
    注意"cacaca"是不正确的，因为相同的字母必须放在一起。
    ##2 描述
    1 map vecotr 
    执行用时 : 560 ms, 在Sort Characters By Frequency的C++提交中击败了0.96% 的用户
    内存消耗 : 10.4 MB, 在Sort Characters By Frequency的C++提交中击败了0.00% 的用户
    给定一个字符串，请将字符串里的字符按照出现的频率降序排列
    ##3 开发周期
    25分钟+25分钟+ 25分钟
    */
    string frequencySort(string s) 
    {
        unordered_map<char, int> hist;
        for (auto c : s) 
        {
             ++hist[c];
        }

        auto pred = [&hist] (char a, char b) {
            return hist[a] > hist[b] || (hist[a] == hist[b] && a > b);
        };

        sort(s.begin(), s.end(), pred);
       
      
        return s;

    }
};

class Big
{
 public:
    
    bool operator()(char a,char b) 
    {
       //此时 无法unordered_map变量的 实在佩服 lambe了
       //除非定义static 
       return a>b;
    }
};

int main()
{  

   return 0;
}
