#include <iostream>

using namespace std;

string IntToString(int input)
{
   string temp;
   //不确定大小的
    //常规做法，不然我就没法完成这个计算过程。
    while(input >0 )
    {   //stirng to int 
        temp.push_back(input%10+'0');
        input /=10;
    }
    return temp;
}

int main()
{
    int input;
    
    while(cin >> input)
    {
        cout<< IntToString(input)<<endl;
    }
}