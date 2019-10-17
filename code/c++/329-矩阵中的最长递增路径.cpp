#include <iostream>
#include <vector>
using namespace std;


/**
给定一个整数矩阵，找出最长递增路径的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

示例 1:

输入: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
输出: 4 
解释: 最长递增路径为 [1, 2, 6, 9]。
示例 2:

输入: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
输出: 4 
解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

直觉：
   2个方向移动，和4个方向移动 问题复杂度就增加了。具体增加在哪里的不清楚
想法：
最长递增路径的长度，四个方向，每个点都可能，2个方向不一样。

描述：

**/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
     int rows = matrix.size();
     if (0 == rows)
     {
         return 0;
     }
        
     int cols = matrix[0].size();
     vector<vector<int>> dp (rows,vector<int>(cols,0));//start from (i,j)
     int longest =0;
     
     for (int i=0;i < rows;i++)
     {
        for (int j=0;j < cols ;j++)
        {    
            //没有被访问过
             if ( 0 == dp[i][j])
             {
                 int temp =dfs(matrix,INT_MIN,i,j,dp,rows,cols);//计算一个节点
                 longest =max(temp,longest);
             }
        }
     }
        
    return longest;
  }
  
  int dfs(vector<vector<int>>& matrix,int pre,int i,int j,vector<vector<int>>& dp,int rows,int cols )
  {
      if ( i < 0 || j <0 || i >=rows || j>=cols)
      {
          return 0;
      }
      
      if ( pre >= matrix[i][j])
      {
          return 0; //这个方向是降序
      }
      
      if ( dp[i][j] > 0)
      {
          return dp[i][j]; //已经存在
      }
      //依赖关系：这个不是从上到下或者从下到上关系。每个节点都为其他人服务
      int left  =dfs(matrix,matrix[i][j],i,j-1,dp,rows,cols);
      int right =dfs(matrix,matrix[i][j],i,j+1,dp,rows,cols);
      int up    =dfs(matrix,matrix[i][j],i+1,j,dp,rows,cols);
      int down  =dfs(matrix,matrix[i][j],i-1,j,dp,rows,cols);
      
      dp[i][j]=max(max(left,right),max(up,down))+1;
      
      return dp[i][j];
      
  }
};
// g++ -w  329.cpp -std=c++11
int main(int argc, char *argv[]) {
  Solution test;

  vector<vector<int>> data;
  vector<int> a{9, 9, 4};
  vector<int> b{6, 6, 8};
  vector<int> c{2, 1, 1};
/**
00=1
01=1
12=1
02=2
10=2
11=2
20=3
21=4
22=2
 */
  data.push_back(a);
  data.push_back(b);
  data.push_back(c);



  cout << test.longestIncreasingPath(data);

    vector<vector<int>> data1;
    vector<int> a1{3,4,5};
    vector<int> b1{3, 2, 6};
    vector<int> c1{2, 2, 1};

    data1.push_back(a1);
    data1.push_back(b1);
    data1.push_back(c1);

    cout << test.longestIncreasingPath(data1);


  return 0;
}
