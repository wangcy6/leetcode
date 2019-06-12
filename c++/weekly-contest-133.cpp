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