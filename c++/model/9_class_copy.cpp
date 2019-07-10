#include <iostream>
using namespace std;

class CExample
{
private:
	int m_nTest;

public:
	CExample(int x) : m_nTest(x)      //带参数构造函数
	{ 
		cout << "constructor with argument" <<x<<endl;
	}

	// 拷贝构造函数，参数中的const不是严格必须的，但引用符号是必须的
	CExample(const CExample * ex)     //拷贝构造函数
	{
		//m_nTest = ex.m_nTest;
		cout << "copy constructor"<<endl;
	}

	CExample& operator = (const CExample &ex)   //赋值函数(赋值运算符重载)
	{	
		cout << "assignment operator"<<endl;
		m_nTest = ex.m_nTest;
		return *this;
	}

	void myTestFunc(CExample ex)
	{
	}
};
class A
{
private:
	int value;
public:
	A(int n)
	{
		value = n;
	}
    //因此C++的标准不允许复制构造函数传值参数，而必须是传引用或者常量引用
	//A(A other)
    A(const A* other)
	{
		value = other->value;
		cout << "A(const A* other) " <<endl;
	}
	void Print()
	{
		cout<<value<<endl;
	}
};
void test1()
{
    A a = 10;
	A b = a;
	A c(&a);
	c.Print();
	b.Print();
	
}
int main(void)
{   
    test1();
	/**
	CExample aaa(2);
	CExample bbb(3);
	bbb = aaa;

	CExample ccc = aaa;
	bbb.myTestFunc(aaa);**/
   /**
   constructor with argument        // CExample aaa(2);
constructor with argument        // CExample bbb(3);
assignment operator              // bbb = aaa;
copy constructor                 // CExample ccc = aaa;
copy constructor                 //  bbb.myTestFunc(aaa);
   **/
	return 0;	
}
