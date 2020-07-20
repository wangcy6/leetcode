// using standard exceptions
#include <iostream>
#include <exception>
#include <vector>      
#include <stdexcept> 

using namespace std;
/**


class exception {
public:
  exception () noexcept;
  exception (const exception&) noexcept;
  exception& operator= (const exception&) noexcept;
  virtual ~exception();
  virtual const char* what() const noexcept;
}

assert vs throw
三、Catch Segmentation fault in c++

1. C++ try-catch blocks only handle C++ exceptions. 




ref：
- https://gist.github.com/fairlight1337/55978671ace2c75020eddbfbdd670221
- http://www.cplusplus.com/reference/exception/exception/
- https://isocpp.org/wiki/faq/exceptions#why-exceptions


**/
class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
public:
  myexception()
  {
      cout<< "myexception()" <<endl;
  }
} myex;

class Foo
{
private:
	int _id;
public:
	Foo() :_id(0)
	{  
		cout << "Default Construct " << this  << " id = " << _id << endl;
	}
	Foo(int id) :_id(id)
	{ 
		cout << "Construct " << this << " id = " << _id << endl;
	}
	~Foo()
	{  
		cout << "Destructor " << this << endl; 
	}
	static void *operator new (size_t size)
	{       
	    cout << "static void *operator new (size_t size)" << endl; 
		Foo *p = (Foo*)malloc(size);
		return p;
	}
	static void operator delete(void *p, size_t size)
	{      
	  cout << "static void operator delete" << endl; 
	  free(p);
	}
     //传入地址，返回地址，没有做其余操作
	static void *operator new (size_t size, void* start)
	{
		return start;
	}
	static void *operator new (size_t size, long extra)
	{
		return malloc(size + extra);
	}
	static void *operator new[](size_t size)
	{
		Foo *p = (Foo*)malloc(size);
		return p;
	}
    static void operator delete[](void *p, size_t size)
	{
		free(p);
	}	
};


//自己抛出异常,自己catch
void testException()
{
	try
	  {
		throw myex;
	  }
	  catch (exception& e)
	  {
		cout << e.what() << '\n';
	  }

}
//第三方库调用抛出异常,已经帮你throw了;
void test_out_of_range()
{
	  std::vector<int> myvector(10);
	  try {
		myvector.at(20)=100;	  // vector::at throws an out-of-range
	  }
	  catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	  }

}
//c++ sdk抛出异常    已经帮你throw了
//throwing (1)	void* operator new (std::size_t size);
void test_logic_error()
{
	try 
	{
        int x=10;
		int y=0;
       // std::cin >> x >> y;
       std::cout << x/y << std::endl;
    } catch(logic_error& e )
	{   //Floating point exception
	    std::cout<<"std::logic_error="<< e.what()  << "\n";
	}
	catch (...) 
	{
         std::cout<< "attempt to divide integer by 0." << std::endl;
    }
}
//liunx系统调用抛出异常

void test_segmentation()
{
	try
	{
		int *foo = NULL;
		*foo = 1;  /* Cause a seg fault */
	}
	catch (std::exception& e)
	{
		std::cerr << "test_segmentation Exception caught : " << e.what() << std::endl;
	}
	catch (...) 
	{
         std::cout<< "test_segmentation ....." << std::endl;
    }

}
int main () {
  test_segmentation();
  testException();
  test_out_of_range();
  test_logic_error();
  return 0;
}
