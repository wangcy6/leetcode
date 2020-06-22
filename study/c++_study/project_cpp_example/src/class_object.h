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


