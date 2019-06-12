#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> 
using namespace std; 

class Base
{
public:
       virtual void foo(){};
       virtual void hello(){
        cout<<"I'm a Base"<<endl;
    }
    virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
};
class Child : public Base
{
public:
    Child():m_c(10)
    {

    }
    void foo()
    {
        
    }
     virtual void hello(){
        cout<<"I'm a Child"<<endl;
    }
    int get_last(){
        string temp("1553855869136");
        char data=temp[temp.length()-1];
        int key=atoi(&data);
        return key;
    }
    int m_c;
};

typedef void(*Fun)(void);

void test_vtable()
{
    Base* ptr =new Base();
    printf("%x\n", *(int*)(void*)ptr);

    for(int i=0;i<20;i++)
    {
      Base* ptemp= new Base();
      printf("%x\n", *(int*)(void*)ptemp);
    }

    Fun pFun = NULL;
	Base obj_1,obj_2;

	// 输出 虚函数表地址 与 虚函数表元素 的值
	cout << "obj_1 虚函数表地址：" << (int*)(&obj_1) << endl;
	cout << "obj_2 虚函数表地址：" << (int*)(&obj_2) << endl;
	cout << "obj_1 虚函数表 — 第一个函数地址：" << (int*)*(int*)(&obj_1) << endl;
	cout << "obj_2 虚函数表 — 第一个函数地址：" << (int*)*(int*)(&obj_2) << endl;

};
int main()
{   


    test_vtable();
    Base* ptr=new Child() ;
    //cout<<ptr->m_c;
    ptr->hello();
    
    Child c;
    Base b=c;
    
    //method1 
    cout<<"cast= "<<((Child*)ptr)->m_c<<endl;
     //method2
     if( Child*  pc=dynamic_cast<Child*>(ptr))
     {
       cout<<"dynamic_cast="<<pc->m_c<<endl;
       
     }
   
     
    return 0;
}