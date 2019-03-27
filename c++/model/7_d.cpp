#include <iostream>
using namespace std;
class base;
class derived;
class base
{
public: 
  //virtual ~base()
  ~base()
  {
      cout<<"~base()"<<endl;
  }
      
  virtual void print()
  {
      cout<<"we are in base"<<endl;
  }
  void func(base* pb)
 {
    
  //derived *pd1 = static_cast<derived*>(pb);
 // derived *pd2 = dynamic_cast<derived*>(pb);
 }
};
class derived : public base
{
public:
	void print()
	{
		cout <<"we are in derived"<<endl;
	}
};
class B { virtual void fun() {}}; 
class D: public B {}; 
  

int main()
{  
  //向上转换 derived--> base ok 隐式转换
    derived d;
    base * pb1 = dynamic_cast<base*>(&d);
    base * pb2 = static_cast<base*>(&d);
    //pb1指向Base subobject of Derived
    pb1->print();//derived
    pb2->print();//derived

  //downcast
	base *b1 = new base();
  // null fail
  if(derived* d = dynamic_cast<derived*>(b1))
  {
        std::cout << "downcast from b1 to d successful\n";
        d->print(); // 调用安全
    }
  
    base* b2 = new derived;
    //ok 
    if(derived* d = dynamic_cast<derived*>(b2))
    {
        std::cout << "downcast from b2 to d successful\n";
        d->print(); // 调用安全
    }
 
	

    

  //Q1 dynamic_cast 为什么会失败  ，base derived大小都是4 大小一样的

  cout<<"size(base) =" <<sizeof(base)<<endl;
  cout<<"sizef(derived)="<<sizeof(derived)<<endl;
  //a1 https://www.jianshu.com/p/f2631fc62bde
  //https://blog.csdn.net/K346K346/article/details/49652209
  //https://songlee24.github.io/2014/07/16/cpp-access-control/
  //https://www.zhihu.com/question/36133278

  //virtual 
  base b3;
  int * vptrAdree = (int *)(&b3);  
  cout << "虚函数指针（vprt）的地址是：\t"<<vptrAdree << endl;

     typedef void(*Fun)(void);
    Fun vfunc = (Fun)*( (int *)*(int*)(&b3));
    cout << "第一个虚函数的地址是：" << (int *)*(int*)(&b3) << endl;
    cout << "通过地址，调用虚函数Base::print()：";
    vfunc();
    /**
    我们把虚表指针的值取出来： ＊(int＊)(&b)，它是一个地址，虚函数表的地址
    把虚函数表的地址强制转换成 int* : ( int ＊) ＊( int＊ )( &b )
    再把它转化成我们Fun指针类型 ： (Fun )＊(int ＊)＊(int＊)(&b)
    https://www.cnblogs.com/QG-whz/p/4909359.html
    **/
    //q2  dynamic_cast的作用
    //https://www.geeksforgeeks.org/g-fact-33/
    //cannot dynamic_cast ‘bb’ (of type ‘class B*’) to type ‘class D*’ 
    //(source type is not polymorphic)
    B *bb = new D;  //p
    D *dd = dynamic_cast<D*>(bb); //down
    if(dd != NULL) 
        cout<<"works"; 
    else
        cout<<"cannot cast B* to D*";

  return 0;
}//virtual void fun() {}