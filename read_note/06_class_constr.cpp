#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <map>
#include <time.h>
#include <stdio.h>
using namespace std;
//两种数据存储区的管理的机制
//只能在栈上创建，也就是不能在堆上创建对象
//栈： 由系统自动分配和回收的。
//堆： 由程序员分配和回收的。
//给系统管理的数据空间起了个名字，就栈；给程序员使用的空间，起了个名，就堆
class OnlyStack
{

public:
~OnlyStack(){}
OnlyStack(){}
private:
    void* operator new(size_t N)
    {
        return NULL;
    }

    void operator delete(void* p)
    {}
};
class OnlyHeap
{
  private:
  ~OnlyHeap(){}
   OnlyHeap(){}
   
   static A* Getinst()
    {
        return new A();
    }

    void destory()
    {
        delete this;
    }
}
int main()
{  
	
}