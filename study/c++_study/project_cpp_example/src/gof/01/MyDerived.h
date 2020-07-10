#include "MyBase.h"
class MyDerived : public MyBase
{
public:
  int bar();
};
//对一个抽象的实现部分的修改应对客户不产生影响，即客户的代码不必重新编译