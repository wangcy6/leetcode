#include <iostream>
#include <vector>
using namespace std;

void testVector(){

	vector<int> array(10);//create an empty vector  
	cout<<" size="<<array.size() << " cap=" <<array.capacity()<<endl; // size=10 cap=10
	array.push_back(10);
	cout<<" size="<<array.size() << " cap=" <<array.capacity()<<endl; // size=10 cap=10

}
//g++ -std=c++11 class_continer.cpp
int main() 
{
	testVector();
}