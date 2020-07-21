#include <deque>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

//std::move进行右值引用，可以将左值和右值转为右值引用， 这种操作意味着被引用的值将不再被使用，否则会引起“不可预期的结果”。

class Base
{
public:
    Base(int k)
    {
        p=new int(1);
        q=*p=k;
    }

    ~Base()
    {
        delete p;
    }
    void show()
    {
        cout<<"q address: "<<&q<<endl;
        cout<<"p address: "<<p<<endl;
    }
private:
    int q;
    int *p;
};

int main()
{  


    cout << endl << "class 对象-----------------------------------------" << endl;
    Base ba(5);
    Base bb(2);
    bb=std::move(ba);
    ba.show();
    bb.show();
	
	
    cout << endl << "常规变量-----------------------------------------" << endl;
    int k = 6, s = 7;
    cout << k << " " << s << endl;
    k=std::move(s);
    cout << k << " " << s << endl;
    k=8;
    cout<<k<<endl;

    cout << endl << "常规数组（自动清空）-----------------------------------------" << endl;
    vector<int> data1 = {1, 2};
    vector<int> data2 = {1, 3, 4, 5, 4, 3, 5, 2};
    data1 = std::move(data2);
//     data1 = static_cast<vector<int> &&>(data2);
    cout<< "after move:" << endl<< "data1:";
    for (int foo : data1)  cout << foo << " ";

    cout << endl<< "data2:";
    for (int foo : data2)  cout << foo << " ";

    cout<< endl << endl << "指针变量-----------------------------------------" << endl;
    int m = 3, n = 5;
    int *p = &m, *q = &n;
    p = std::move(q);
    cout<<p<<"       "<<*p<<endl;
    cout<<q<<"       " << *q << endl;

    cout << endl << "class 对象-----------------------------------------" << endl;
    Base ba(5);
    Base bb(2);
    bb=std::move(ba);
    ba.show();
    bb.show();

    cout << endl << "string（自动清空） -----------------------------------------" << endl;
    string str=std::move("deng wen");
    string str1("luo chao");
    str1=std::move(str);
    cout<<&str<<"   "<<str<<endl;
    cout<<&str1<<"   "<<str1<<endl;

    cout << endl << "vector（自动清空） -----------------------------------------" << endl;
    vector<int> vec1={1,2,3,4,5};
    vector<int> vec2={9,0,9};
    vec1=std::move(vec2);
    for (int foo : vec1)  cout << foo << "  ";cout<<endl;
    for (int i=0;i<vec1.size();i++)  cout << &vec1[i] << "   ";
    cout<<endl;

    cout << endl << "&&的真正含义--------------------------------------" << endl;
    int ta = 3; // int &&tb=2;//临时对象的引用，即tb存的是临时对象2的地址
    int tb = 2; //生成对象tb,并将2赋值给tb所指的地址中。 感觉两种的结果一样，但是含义不一样
    cout << &ta << "  " << ta << endl;
    cout << &tb << "  " << tb << endl;
    cout << endl;
    int tc = 1;
    ta = tc;
    tb = tc;
    cout << &ta << "  " << ta << endl;
    cout << &tb << "  " << tb << endl;

    return 0;
}