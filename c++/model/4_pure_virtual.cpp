#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

class   
{
  public: 
   virtual void fun()=0;
};
class Derived : public Base
{
  public:
  void fun()
  {
    cout<<"this is a pure virutal fun"<<endl;
  }
};
class AbstractBase
{
    virtual void PureVirtualFunction() = 0;
}

class Derived : public AbstractBase
{
    virtual void PureVirtualFunction()  { }
}
void test_pure_size(){
    
    cout<< "sizeof (Base)="<<sizeof(Base)<<endl; //sizeof (Base)=8
    cout<< "sizeof (Derived)="<<sizeof(Derived)<<endl;//sizeof (Derived)=8
}
int main()
{
 
  test_pure_size();
	return 0;
}

