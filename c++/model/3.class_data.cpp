//指向类成员函数的函数指针
#include <iostream>
#include <cstdio>
using namespace std;
 
class A
{
	public:
		A(int aa = 0):a(aa){}
 
		~A(){}
 
		void setA(int aa = 1)
		{
			a = aa;
		}
		
		virtual void print()
		{
			cout << "A: " << a << endl;
		}
 
		virtual void printa()
		{
			cout << "A1: " << a << endl;
		}
	public:
		int a;
};
 
class B:public A
{
	public:
		B():A(), b(0)
    {

    }
		
		B(int aa, int bb):A(aa), b(bb){

    }
 
		~B(){}
 
		virtual void print()
		{
			A::print();
			cout << "B: " << b << endl;
		}
 
		virtual void printa()
		{
			A::printa();
			cout << "B: " << b << endl;
		}
	private:
		int b;
};
 
int main(void)
{
	A a;
	B b;

	void (A::*ptr)(int) = &A::setA;
	/**
  out:
  A::set(): 0x400de6
  B::print(): 0x1 //
  B::print(): 0x9 //虚函数vs非虚函数

  A: 0
  A: 10
  A: 100
  A: 1000
  A: 10000
  **/
	//对于非虚函数，返回其在内存的真实地址
 
	printf("A::set(): %p\n", &A::setA);
	//对于虚函数， 返回其在虚函数表的偏移位置
	printf("A::print(): %p\n", &A::print);
	printf("A::print(): %p\n", &A::printa);
  printf("A::a: %p\n", &A::a);
  
  printf("B::print(): %p\n", &B::print);
	printf("B::print(): %p\n", &B::printa);

 	A* pa = &a;
  
	a.print();
 
	a.setA(10);
	a.print();
 
	a.setA(100);
	a.print();

	//对于指向类成员函数的函数指针，
  //引用时必须传入一个类对象的this指针，所以必须由类实体调用
  //https://www.studytonight.com/cpp/pointer-to-members.php
	(pa->*ptr)(1000);
	a.print();
 
	(a.*ptr)(10000);
	a.print();
  
/**
对于nonstatic member function （非静态成员函数）取地址，获得该函数在内存中的实际地址(需要不需要)

对于virtual function（虚函数）,其地址在编译时期是未知的，所以对于virtual member function（虚成员函数）取其地址，所能获得的只是一个索引值(需要计算)
--------------------- 
作者：Crayondeng 
来源：CSDN 
原文：https://blog.csdn.net/crayondeng/article/details/16868351 
版权声明：本文为博主原创文章，转载请附上博文链接！
**/
	return 0;
}
