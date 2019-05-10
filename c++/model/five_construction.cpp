
#include <iostream>
using namespace std;
//g++ five_construction.cpp
/**
Semantics of Construction, Destruction, and Copy
1 define
2 why 
3 appliction 


**/

class Abstract_base {
    public:
      //virtual ~Abstract_base(void) = 0; //不要将虚析构函数声明为纯虚的,因为可以通过静态的方式调用
      virtual ~Abstract_base(void){};
      virtual void interface(void) const = 0;
      virtual const char* mumble(void) const { return mumble_; }
    protected:
      Abstract_base(char* pc = NULL);
      char* mumble_; 
};

class Concrete_derived : public Abstract_base {
public:
  Concrete_derived();
virtual void interface(void) const
{
  Abstract_base::interface();
}
};


class A {
public:
    A(){pi = new int;}

    ~A(){delete pi;}
    int *pi;

};

void testcopy(){
    A obj1;
    A *obj2 = new A(obj1);//bit wise copy
    delete obj2;// destructor called on obj2
    *(obj1.pi)=1;// might be crashed
    /*A class does not exhibit bitwise copy semantics for the default copy assignment operator in the following cases
    1. When the class contains a member object of a class for which a copy assignment operator exists
    2. When the class is derived from a base class for which a copy assignment operator exists
    3. When the class declares one or more virtual functions (we must not copy the vptr address of the righthand class object, since it    might be a derived class object)
    4. When the class inherits from a virtual base class (this is independent of whether a copy operator exists
    for the base class)*/
  // memberwise copy the derived class members

}

class Something
{
private:
    int m_value1;
    double m_value2;
    char m_value3;
 
public:
    Something(int value1, double value2, char value3='c')
        : m_value1(value1), m_value2(value2), m_value3(value3) // directly initialize our member variables
    {
    // No need for assignment here
    }
 
    void print()
    {
         std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
    }
 
};

void test_construct()
{
  Something something(1, 2.2); // value1 = 1, value2=2.2, value3 gets default value 'c'
    something.print();
}
//http://luodw.cc/2015/10/12/Cplus4/
int main()
{
test_construct();
//	testcopy();
	return 0;
}

