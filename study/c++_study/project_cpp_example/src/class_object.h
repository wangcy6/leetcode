#include<iostream>
#include<string>
using namespace std;

class Base
{
public:
	virtual void Send()
	{ 
		cout << "\n Base Send_Base:" << mVal << endl;
	}
	~Base() {}
	void OutPut()
	{
		Send();
	}

	int mVal;
};

class Derive :public Base
{
public:
	Derive() { mVal = 100; }
	virtual void Send()
	{
		mVal++;
		cout << "\n Derive Send_Der: " << mVal << endl;
	}
	void OutPut()
	{
		Base::OutPut();
	}
};

void testVirtual()
{
	Derive user;
	Base &base = user;
	base.Send();
	
	Base *p = &base;
	p->OutPut();
	
	user.OutPut();
}


//定义构造函数时，只需要对本类中新增成员进行初始化，对继承来的基类成员的初始化，自动调用基类构造函数完成（使用“初始化列表”自动调用基类构造函数）
//问：构造函数和析构函数都不能被继承，为什么析构函可以为虚函数？这个跟构造顺序和析构顺序相反有关系吗？

