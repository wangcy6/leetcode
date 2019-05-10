#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
class  MemCopy 
{    
	public:  
	  int* m_a;
		MemCopy()
		{
			m_a = new int(122);
			cout<<"MemCopy()"<<endl;
		}
    MemCopy(const MemCopy& rhs)  // let's define a custom copy constructor
    {
       m_a = new int(123);
       memcpy(m_a, rhs.m_a, sizeof(int) * 1);
			 cout<<"MemCopy(const MemCopy& rhs)"<<endl;
    }
};

class BitCopy 
{  
	public: 
   int* m_a;

   BitCopy() 
   {
      m_a = new int();
			cout<<&m_a<<endl;
   }

   ~BitCopy()
   {
     //delete  m_a;
   }
};

void test(){
	
	BitCopy object1;
	BitCopy bc=object1;
	cout<<" BitCopy before="<<&object1.m_a<<endl;
	cout<<" BitCopy after="<<*bc.m_a<<endl;
  //core
	MemCopy object2;
	MemCopy mc=object2;
	cout<<" MemCopy before="<<&object2.m_a<<endl;
	cout<<" MemCopy after="<<*mc.m_a<<endl;
}
class Base{
public:
    virtual void vfunc() 
		{
			 cout<<"Base::vfunc()"<<endl; 
		}
		//需要生成默认构造函数
private:
  //带有Default Constructor的Member*
  MemCopy m_copy;
};
class Derived: public Base
{
public:
    virtual void vfunc() 
		{
			 cout<<"Derived::vfunc()"<<endl; 
		}

	bool operator==(const Base& rhs) const
  {  /**
    const Derived* ptr = dynamic_cast<const Derived*>(&rhs);        
    if (ptr != 0) {
        return (this == ptr) && (Base::operator==(*this, rhs));
    }
    else {
        return false;
    }**/
		return true;
   }
   //???
	 Derived& operator=(Base& rhs){
		 Derived temp;
     return temp;
	 }
};
void test_bitcopy(){
	  
		Derived d;
    Base b_assign = d; // member copy  Base
		b_assign.vfunc();  //普通的函数调用

    Base b_memcpy;
    memcpy(&b_memcpy, &d, sizeof(Base)); //bit copy  Derived
    b_memcpy.vfunc(); //普通的函数调用

    Base* memcpy_ptr1=&b_memcpy;  //bit copy  Derived
		memcpy_ptr1->vfunc();//virtual call 

		Base* memcpy_ptr2=&b_assign; // member copy  Base
		memcpy_ptr2->vfunc(); //virtual call 
    /**
		Derived.vptr: 400d20; 
		b_assign.vptr: 400d38; 
		b_memcpy.vptr: 400d20; 
		b_ref.vptr: 400d20
		Base::vfunc()
		Base::vfunc()
		Derived::vfunc()
		Base::vfunc()

		a bitwise copy is a copy of a block of memory
     a memberwise copy is a copy that requires intimate knowledge of the    structure of data that's being copied
		**/

    printf("sizeof Base : %d\n", sizeof(Base));

    Base &b_ref = d;
    b_ref.vfunc();

     
    printf("Derived.vptr: %x;  b_assign.vptr: %x; b_memcpy.vptr: %x; b_ref.vptr: %x\n", 
		    *(int *)&d,
        *(int *)&b_assign,
        *(int *)&b_memcpy,
        *(int *)&b_ref);
}

void test_constructor(){
    
		Base b1;	 //constructor
		b1.vfunc();

    Base b2=b1;	//copy constructor 
		b2.vfunc();


		Derived d;
		d=b1;
		d.vfunc();

}
int main(void)
{

	test_constructor();
	//test();
  //test_bitcopy();
	return 0;
}