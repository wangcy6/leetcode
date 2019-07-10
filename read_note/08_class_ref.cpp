#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> 
using namespace std; 
class CTest
{

public:

void test_overload(int a)
{
  cout<<"test(int)"<<endl;
}

void test_overload(int& a)
{
  cout<<"test(&int)"<<endl;
}

void test_overload(const int& a)
{
  cout<<"test(const &int)"<<endl;
}
};
int main(void)
{
	 CTest test;
   /**
   int b=10;
   test.test_overload(b); 
  call of overloaded ‘test_overload(int&)’ is ambiguous**/
  int value=10;
  const int& refvalue = value;
  test.test_overload(refvalue); // test(int)

  //const int& d =b; 
  const int& refvalue_const = 1;
  //test.test_overload(refvalue_const); 
 

}