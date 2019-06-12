#include <iostream>
	#include <cmath>
	using namespace std;

	class A
	{
	public:
		A(){cout << "Construct A" << endl;}
        A(int a){cout << "Construct A（int）" << endl;}
		~A(){cout << "Destruct A" << endl;}
	};

	class C
	{
	public:
		C(){cout << "Construct C" << endl;}
		~C(){cout << "Destruct C" << endl;}
		
	};

	class B: public A, public C
    //class B
	{
	public:
		//Notice: List initialize
		//B(): a(A()), c(C()) 
    B():a(A(10)) 
    {
      cout << "Construct B" << endl;
    }
	~B(){cout << "Destruct B" << endl;}
    C c;//默认构造函数
    A a;//指定构造函数
	};

	int main(int argc, char const *argv[])
	{
		B b;
		return 0;
	}