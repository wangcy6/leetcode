#include <cstring>
#include <iostream>
#include <string>

class Explicit {
private:
public:
    explicit Explicit(int size)
    {
        std::cout << " the size is " << size << std::endl;
    }
    explicit Explicit(const char* str)
    {
        std::string _str = str;
        std::cout << " the str is " << _str << std::endl;
    }

    Explicit(const Explicit& ins)
    {
        std::cout << " The Explicit is ins" << std::endl;
    }

    Explicit(int a, int b)
    {
        std::cout << " the a is " << a << " the b is " << b << std::endl;
    }
};
// g++ std=c++11 3_class.cpp
int main()
{

    Explicit test0(15);
    Explicit test1 = 10; // 无法调用 error: conversion from ‘int’ to non-scalar type ‘Explicit’ requested

    Explicit test2("RIGHTRIGHT");
    Explicit test3 = "BUGBUGBUG"; // 无法调用 error: conversion from ‘const char [10]’ to non-scalar type ‘Explicit’ requested

    Explicit test4(1, 10);
    Explicit test5 = test0;

    char* str = "hello, world";
    str[1] = 'a';
    const char* p = "test";
    //warning: deprecated conversion from string constant to ‘char*’
    //警告: 弃用的转换从字符串到char *
    //"other"是字符串常量, 内存分配在全局的const内存区
    // char * 声明了一个指针，而这个指针指向的是全局的const内存区，const内存区当然不会让你想改就改的。
    //所以，如果你一定要写这块内存的话，那就是一个非常严重的内存错误。
}