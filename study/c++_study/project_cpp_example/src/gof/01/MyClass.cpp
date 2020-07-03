// MyClass.cpp
 class MyClassImpl {
 public:
 int foo() {
         return bar();
 }
 int bar() { return var++; }
         int var;
 };
 
 MyClass::MyClass() : m_pImpl(new MyClassImpl){}
 
 MyClass::~MyClass()
 {
     try {
             delete m_pImpl;
     }
     catch (...) {}
 }
 
 int MyClass::foo(){ return m_pImpl->foo(); }
 
 
 
class sample  
{  
private:  
    class impl;                             //不完整的内部类声明  
    shared_ptr<impl> p;                     //shared_ptr成员变量  
public:  
    sample();                               //构造函数  
    void print();                           //提供给外界的接口  
};  
class sample::impl                      //内部类的实现  
{  
public:  
    void print()  
    {   cout << "impl print" << endl;}  
};  
 
 
 //https://blog.csdn.net/u014338577/article/details/47125177
1. 类的抽象以及它的实现都可以通过生成子类的方法加以扩充；
2. 对客户隐藏具体的实现部分；
3. 加快工程编译速度，不用因为实现部分的修改而导致大量源文件的重新编译；

#include <iostream>
#include <string>
#include <boost/scoped_ptr.hpp>
//#include <boost/scoped_array.hpp>
 


class WindowImp
{
public:

	~WindowImp()
	{
		std::cout << "~WindowImp()" << std::endl;
	}
	void Draw()
	{
		std::cout << "Draw Window --> "<< std::endl;
	}
	

};

class Window
{
public:
	Window()
	{   
	    
		m_pImpl.reset(new WindowImp());
	}
	void Draw()
	{
		m_pImpl->Draw();
	}
private:
	 //私有实现
	shared_ptr<WindowImp> m_pImpl;
};

int main(int argc, char **argv)
{
	Window wnd;
	wnd.Draw();
 
return 0;
}

 
 //https://www.cnblogs.com/mthoutai/p/7232837.html
 

/*将抽象部分与实现部分分离，使它们都能够独立的变化*/
#include "bridge.h"

int main()
{
	cout <<"main start" <<endl;	
	sample smp;
	smp.display();
	cout <<"main end" <<endl;	
	//sample::bridge bri;      //error: ‘class sample::bridge’ is private
	return 0;
}


class sample
{
	private:
		class bridge;
		shared_ptr<bridge> bptr;
	public:
		sample();
		void display();
};

class sample::bridge
{
	public:
		void display();
};

bridge.cpp
#include "bridge.h"
sample::sample()
{
		bptr = make_shared<bridge>();
}
void sample::display()
{
	bptr->display();
}
void sample::bridge::display()
{
	cout << "bridge display!"<<endl;
}

makefile
.SUFFIXES:.h .c .cpp .o

CC=$(CXX) $(CXX_FLAG)

RM = rm
SRCS = bridge.cpp main.cpp
PROGRAM = bridge
OBJS=$(SRCS:.cpp=.o)

INC_PATH =  -I$(BOOST_INCLUDE)
LIB_PATH =  -L$(BOOST_LIB)
LIBS = -lboost_date_time

$(PROGRAM):$(OBJS)
	$(CC) $? $(LIB_PATH) $(LIBS) -o $@

$(OBJS):$(SRCS)
	$(CC) $(CPPFLAGS) -c $(SRCS)  $(INC_PATH)
	
.PHONY:clean
clean:
	$(RM) $(PROGRAM) $(OBJS)