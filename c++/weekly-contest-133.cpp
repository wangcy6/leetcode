<<<<<<< HEAD
#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    { 
     auto compare=[](const vector<int> &v1, const vector<int> &v2) {
        return (v1[0] - v1[1] < v2[0] - v2[1]);
    
  };
      std:sort(costs.begin(),costs.end(),compare);

      int n=costs.size();
      int sum=0;
      for(int i=0;i<n/2;i++)
      {
        sum+=(costs[i][0]+costs[i+n/2][1]);
      }
      return sum;
    }
};
int main()
{  
  vector<int> myvector;
   for (int i = 0; i < 17; i++)
  {
        myvector.push_back(i);
        myvector.push_back(i);
  }

	std::sort (myvector.begin(), myvector.end(), [](int x,int y){ return x<y;});
  for (auto n : myvector) 
	{
		cout << n << " ";
	}
	cout << endl;
	return 0;
}
=======
#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    { 
     auto compare=[](const vector<int> &v1, const vector<int> &v2) {
        return (v1[0] - v1[1] < v2[0] - v2[1]);};
      std:sort(costs.begin(),costs.end(),compare);

      int n=costs.size();
      int sum=0;
      for(int i=0;i<n/2;i++)
      {
        sum+=(costs[i][0]+costs[i+n/2][1]);
      }
      return sum;
    }
	//https://leetcode-cn.com/problems/maximal-square/
		/**
		 找到只包含 1 的最大正方形，并返回其面积。
		**/
	 int maximalSquare(vector<vector<char>>& matrix) 
	 {
        
     }
	 //https://leetcode-cn.com/problems/maximal-rectangle/
	 
	 //https://leetcode.com/problems/island-perimeter/
	  int islandPerimeter(vector<vector<int>>& grid) 
	  {
		  
      } 
	  //https://www.youtube.com/watch?v=yKr4iyQnBpY
    }
	
};

int main()
{  
	return 0;
}
>>>>>>> branch 'master' of https://wang_cyi%40163.com:qwer%2112345@github.com/wangcy6/leetcode.git
