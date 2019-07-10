#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <map>
#include <time.h>
#include <stdio.h>
using namespace std;
class Point {
public:
	virtual ~Point();//1
	virtual Point &mult(float) = 0;//2
	float x() const { return _x; }
	virtual float y() const { return 0; }//3
	virtual float z() const { return 0; }//4
protected:
	Point(float x = 0.0);
	float _x;
};
//https://blog.csdn.net/yiranant/article/details/47379127
class Point2d : public Point {
public:
	Point2d(float x = 0.0, float y = 0.0) : Point(x), _y(y) {}
	~Point2d();
	// 改写base class virtual functions
	Point2d& mult(float);
	float y() const { return _y; }
protected:
	float _y;
};


class A
{
public:
	A(int arg):m_a(arg)
	{
		cout << "constructor of A" << endl;
		output(); //在构造函数调用虚函数
	}
  A()
	{
	
		this->output(); //在构造函数调用虚函数
	}
	virtual void output()
	{ 
		cout << "output A" << endl;
	}
	virtual void display()
	{ 
		output(); 
	}
private:
	int m_a;
};
 
class B : public A
{
public:
	B(int arg1, int arg2):A(arg1), m_b(arg2)
	{ 
		cout << "constructor of B" << endl;
	}
	virtual void output()
	{ 
		cout << "output B" << endl;
	}
private:
	int m_b;
};
 
 class TestCopy
 {
private:
 int m_int;
 int* m_pint;
 A* m_ptra;//
 A m_a;//
 public:
 TestCopy()
 {
     m_int=10;
     m_pint=new int(30);
     m_ptra =new A();
    
 }
 void show()
 {
     cout<<m_int<<endl;
     cout<<m_pint<<endl;
     cout<<m_ptra<<endl;
     cout<<&m_a<<endl; //不一样了。
 }
 };
int main(int argc, char* argv[])
{  

    TestCopy tc;
    tc.show();
    TestCopy tcc=tc;
    tcc.show();
    /**
    A aa;
 
	B b(1, 2);
	b.display();

  int init;
  init=10;**/
	return 0;
}

