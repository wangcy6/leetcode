#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional> // std::greater
using namespace std; 
/**
class Solution {
public:
    int nthUglyNumber(int n){
        vector<long long> ans;
        priority_queue<long long,vector<long long>,greater<long long>> Q;
        unordered_map<long long,bool> visited;
        Q.push(1);
        visited[1]=true;
        while (!Q.empty()&&ans.size()<n){
            long long x=Q.top();
            Q.pop();
            ans.push_back(x);
            if (!visited[x*2]){
                Q.push(x*2);
                visited[x*2]=true;
            }
            if (!visited[x*3]){
                Q.push(x*3);
                visited[x*3]=true;
            }
            if (!visited[x*5]){
                Q.push(x*5);
                visited[x*5]=true;
            }
        }
        return ans[n-1];
    }
};
**/
class Solution {
public:
    int nthUglyNumber(int n) 
    {   
        priority_queue<long long,vector<long long>,greater<long long> > queue;
        unordered_map<long long,bool> repeat;
        
        queue.push(1);
        repeat[1]=true;
      
        int array[3]={2,3,5};
        long long number=1;
        int i=0;
        while(!queue.empty()&&i++<n)
        {
           number=queue.top();
           queue.pop();//按照从小到大顺序

            for(int i=0;i<3;i++)
            {
                long long temp=array[i]*number;
                if(repeat[temp] ==false)
                {
                    repeat[temp]=true;
                    queue.push(temp);

                }
            }

        }

        return number;

    }
};

int main()
{   

   cout<<nthUglyNumber(1600)<<endl;
   cout<<"sizeof long = " <<sizeof(long)<<endl;
   cout<<"sizeof(long long)= " <<sizeof(long long )<<endl;
   
  int myints[]= {10,60,50,20};
  std::priority_queue<int> first (myints,myints+4); //大到小
  std::priority_queue<int, std::vector<int>, std::greater<int> > //小到大
                            second (myints,myints+4);
  //最完整的声明公式（吧）形如：
  //priority_queue< 结构名, vector<结构名> , greater/less<结构名> > 队列名;
  //// 优先队列，默认底层容器是 vector，利用 max-heap 规则
 /**
  priority_queue(const value_type* __first, const value_type* __last) 
    : c(__first, __last) { make_heap(c.begin(), c.end(), comp); }
**/ 
	while (!first.empty())
	{
		 std::cout << ' ' << first.top();
		 first.pop();
		 cout<<endl;
	}
	
	while (!second.empty())
	{
		 std::cout << ' ' << second.top();
		 second.pop();
		 cout<<endl;
	}
   return 0;
}
