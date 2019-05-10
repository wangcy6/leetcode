#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std; 

class Solution {
public:
    int numTrees(int n) 
    {
       vector<int> dp(n+1,0);
       dp[0]=1;
       dp[1]=1;
       //忘记 i<=n
       for(int i=2;i<=n;i++)
       {
           for (int j=0;j<i;j++)
           {
                dp[i]+=dp[j]*dp[i-1-j]; //忘记+=了
           }
       }

       return dp[n];    
    }
};

int main()
{  

   return 0;
}
