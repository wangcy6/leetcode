#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;
int add(int a,int b)
{
   return (a+b);
}
class A
{
public:
    static void test1()
    {  // m_a+=1;
        m_staticA += 1;
    }
    static void test2(void *pData)
    {
        A *a = (A *)pData;
        a->m_a += 1;
    }
    static void test() {

    }

    void hello(int aa)
    { 
      cout<< "A::hello is call " <<aa<<endl;
    };
private:
    static int m_staticA;
    int m_a;
};
void test_member_function_pointer(){
  A a;
  A::test2(&a);
  //member function pointer 类成员函数指针
  void (A::* FunPtr)(int); //一个类成员函数指针变量pmf的定义
  FunPtr= &A::hello;//成员函数指针变量pmf被赋值
  //p(); 
  A ins, *p;
  p=&ins;
  (ins.*FunPtr)(101);       //对实例ins，调用成员函数指针变量pmf所指的函数
  (p->*FunPtr)(102);      //对p所指的实例，调用成员函数指针变量pmf所指的函数
  //类成员函数指针与普通函数指针不是一码事。前者要用.*与->*运算符来使用，而后者可以用*运算符
}
class Foo {
public:
    Foo(int i = 0) { _i = i; }
    void f() {
        std::cout << "Foo::f()" << std::endl;
    }
    int f(string str) {
        cout << "Foo::f(string) " << str <<endl;
        return 1;
    }
    static void test() {
        cout << "Foo::test " <<endl;
    }

    virtual  int ff(char *c = 0) {
        std::cout << "Foo::f(char*)" << std::endl;
        return 1;
    }

private:
    int _i;
};



class Bar {
public:
   virtual   void b(int i = 0) {
        std::cout << "Bar::b()" << std::endl;
    }
};

class FooDerived : public Foo {
public:
    int ff(char *c = 0) {
        std::cout << "FooDerived::f()" << std::endl;
        return 1;
    }
};
void test_member_function_pointer2()
{   

     //01 一个数据变量的内存地址可以存储在相应的指针变量中，
     //函数的首地址也以存储在某个函数指针变量中。这样，我就可以通过这个函数指针变量来调用所指向的函数了
      typedef int (* FunPtr1)(int ,int ) ;
      FunPtr1 fptr2 =&add;
      cout<<"FunPtr = "<<fptr2(1,2)<<endl;

      int (* FunPtr2)(int ,int )=&add;
      cout<<"(*FunPtr2)(1,2) = "<<(*FunPtr2)(1,2)<<endl;
     
     //静态成员函数指针
     void (*FunPtr3) () = &Foo::test; // 正确
     (*FunPtr3)(); // 调用 Foo::test()

    //Pointer-to-Member Function Tables
     //02 
      Foo *p1 = 0;
      cout<<"p1="<<p1<<endl;
      p1->f();

      int (Foo::*fptr) (string) = &Foo::f;
      Foo obj;
      (obj.*fptr)("str"); // 通过对象来调用 Foo::f()
      Foo *p = &obj;
      (p->*fptr)("str"); // 通过指针来调用 Foo::f()
      
      //03 为什么C++如此费心地去发明这样的语法？很简单，因为它和常规指针是不同的东西，而且这样的类型转换也是违反直觉的。
      typedef int (Foo::*FPTR) (char*);
      typedef void (Bar::*BPTR) (int);
      typedef int (FooDerived::*FDPTR) (char*);

      FPTR fptr12 = &Foo::ff; //int f(char *c = 0) 
      BPTR bptr = &Bar::b;//void b(int i = 0)
      FDPTR fdptr = &FooDerived::ff;//int f(char *c = 0)

      // bptr = static_cast<void(Bar::*)(int)>(fptr); // 错误 Bar 和 foo 没有任何关系
      fdptr = static_cast<int(Foo::*)(char*)>(fptr12); // 正确，逆变性规则
      //对于static_cast，上行转换时安全的，而下行转换时不安全的
      //cout<< "fdptr= "<<fdptr("a")<<endl;
      //must use ‘.*’ or ‘->*’ to call pointer-to-member function in ‘fdptr (...)’ ????
     
   //Bar objBar;
  //(objBar.*(BPTR) fptr)(1);



   // FooDerived objDer;
   // (objDer.*fptr)(0); // 调用 FooDerived::f()，而不是 Foo::f()

  
  
}

class Printer { // 一台虚拟的打印机
public:
    void Copy(char *buff, const char *source) { // 复制文件
        strcpy(buff, source);
    }

    void Append(char *buff, const char *source) { // 追加文件
        strcat(buff, source);
    }
};

enum OPTIONS { COPY, APPEND }; // 菜单中两个可供选择的命令

typedef void(Printer::*PTR) (char*, const char*); // 成员函数指针

void working(OPTIONS option, Printer *machine,
             char *buff, const char *infostr) {
    PTR pmf[2] = { &Printer::Copy, &Printer::Append }; // 指针数组

    switch (option) {
    case COPY:
        (machine->*pmf[COPY])(buff, infostr);
        break;
    case APPEND:
        (machine->*pmf[APPEND])(buff, infostr);
        break;
    }
}

void test_woking()
{
    OPTIONS option;
    Printer machine;
    char buff[40];

    working(COPY, &machine, buff, "Strings ");
    working(APPEND, &machine, buff, "are concatenated!");

    std::cout << buff << std::endl;
}

class Base {
private:
    int a;

public:
    Base():a(0) {}
    void test() { cout << "call Base ::test()" << endl; }//没有操作成员变量
    void testMember() { a = 6; }//操作了成员变量
    static void testStatic() { cout << "call Base::testStatic"<<endl; }//静态成员函数
    virtual void test1() { cout << "call Base ::test1()" << endl; }//虚成员函数1
    virtual void test2()const { cout << "call Base ::test2()" << endl; }//const虚成员函数2
    virtual void test3(int a) { cout << "call Base ::test3(int a)" << endl; }//带参数的虚成员函数3
};

void TestVirtualTable()
 {
    printf("%p\n",&Base::test3);
    printf("%p\n",&Base::test2);
    printf("%p\n",&Base::test1);
}

int main()
{

  //test_member_function_pointer();
 // test_member_function_pointer2();
 // test_woking();
 TestVirtualTable();
	return 0;
}

