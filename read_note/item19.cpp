#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <map>
#include <time.h>
#include <stdio.h>

using namespace std;

void uppercasify(const string& str){}
void test_const_ref()
{
	int n = 100;
	int &r1 = n; //正确
	const float &r2 = n; //正确

	char c = '@';
	char &r3 = c;
	//正确c
	const int &r4 = c; //正确

	//cout << ((a + b) = c) << endl;   //临时对象作为左值
}
void test_pointer(){
	int a=10;
	int* p1=&a;
	//char*p2=&a;//cannot convert ‘int*’ to ‘char*’ in initialization
	const char &p3=a;
	//给引用添加 const 限定后，
	//不但可以将引用绑定到临时数据，还可以将引用绑定到类型相近的数据
}
int main()
{  
	test_pointer();
	test_const_ref();
	char subtleBookPlug[] = "Effective C++";
	uppercasify(subtleBookPlug); 
	return 0;
}