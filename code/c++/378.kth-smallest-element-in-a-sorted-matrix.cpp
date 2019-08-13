#include <iostream>
#include <string>
#include <vector>
using namespace std; 

//函数对象
class Item  
{
public:
    int x, y, val;
    Item()
    {

    }
    Item (int x, int y, int val) 
    {
        x = x;
        y = y;
        val = val;
    }
	//小顶堆是升序 
	bool operator()(const Item  &first,const Item  &second) const{
		return  first.val>second.val;
	}
	bool operator<(const Item& b) const
   {
     return val > b.val;
   }

};

class Solution {
public:

    int kthSmallest(vector<vector<int>>& arr, int k) {
        
        int rows = arr.size();
		if ( 0 == rows) return -1;
		int cols = arr[0].size();
        
        priority_queue<Item,std::vector<Item>,Item()> min_heap;
        
        for (int j=0;j<cols;j++)
		{   
	        Item item(0,j,arr[0][j]);
			min_heap.push(item);
		}
        int result=0;
        while(k-->0)
        {    
	        Item item = (Item)min_heap.top();
            min_heap.pop();
            result=item.val;
            if (item.x != rows-1)
            {  
               Item item1(item.x+1,item.y,arr[item.x+1][item.y]);
               min_heap.push(item1);
            }
           
        }
       return result;
        
    }
};
//g++ -g -werror -std=c++11
int main()
{
    vector<int> v1 = { 1,  5,  9 };
    vector<int> v2 = { 10, 11, 13};
    vector<int> v3 = { 12, 13, 15};

    vector<vector<int>> board;
    board.push_back(v1);
    board.push_back(v2);
    board.push_back(v3);
 
    Solution solution;
    cout<< solution.kthSmallest(board,8);

}