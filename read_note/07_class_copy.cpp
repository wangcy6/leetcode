#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
class A 
{
public:
	A(int a=0):a(a){
	}
	void test()
	{
		cout<<"test"<<endl;
	}
private:
	int a;
};
int main(void)
{
	A a;
	A a1=a;
	a1.test();
	return 0;
}