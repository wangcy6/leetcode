/**************************************************************************

Copyright:MyCompany

Author: wangcy6

Date:日期

Description: sizeof 

**************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;
//通过预编译命令#pragma pack(n)，n=1,2,4,8,16来改变这一系数
#pragma pack(8)
struct node{

  char f; //1
  short  a;//2
  int b;//4
  };

struct s1
{
	short a; //第一个，放在[0,1]位置，
	long b; //第二个，自身长度为4，按min(4, 8) = 4对齐，所以放在[4,7]位置
};
struct node n;

struct s2{
	char c; //8
	s1 d;//16
	long long e;//8
};


struct s3
{ 
	char a; //1
	int b; //4
	short c; //2
} ;
//min(2,4)=2
struct s4 
{ 
	char a; //1
	short b; //2
	char c; //1
} ; 

struct s5 
{ 
    char a; //1
    short b; //2
} ;
struct s6 
{ 
	char a; //1
} ;
//8
struct s7
{ 
	char a; //0-1     1
	char b; //1-2 -4  2 ->4
	int c;  //4->8    8
} ;
//变量顺序不一样，结果竟然不一样。
struct s8
{ 
	char a; //1    //0 ->1->4
	int c;         //4-->8
	char b;       //8->9-->12
} ;

struct s9
{ 
	char a; //1      
	short c; //2     
	int b; //4
} ;

//min(2,4)=2
//min(2,8)=2
struct s10
{ 
	short a; //2      
	char c; //1     
} ;

struct s11
{ 
	char a; //      
	char b; //  
	char c;   
} ;

struct s12
{
	short a; //第一个，放在[0,1]位置，
	long b; //第二个，自身长度为4，按min(4, 8) = 4对齐，所以放在[4,7]位置
	char c;
};
//sizeof 规则
//1开始位置是当前类型整数倍吗？ 如归不是 min(4,4)=4(第一个默认为开始位置默认为0)
//2 整个类大小 安装min(4,4) 倍数补齐  
struct s13
{
	int a;  //  0  4
	char b; //  4-->5
	char c; //  5---6
	char d; //  6--->7->8 
};
//sizeof 规则
//1开始位置是当前类型整数倍吗？ 如归不是 min(4,4)=4(第一个默认为开始位置默认为0)
//2 整个类大小 安装min(4,4) 倍数补齐 
struct s14
{
	char a;    //0-->1 -->4
	int b;     //4-->8
	char c;    //8---9
	char d;   //9--->10 ->12 
};
//通过预编译命令#pragma pack(n)，n=1,2,4,8,16来改变这一系数
//https://blog.csdn.net/lizhifeng2009/article/details/8838331
int main(int argc, char *argv[])
{   
	cout<<"long="<<sizeof(long)<<endl; //8
	cout<<"double="<<sizeof(double)<<endl;//8
	cout<<"float="<<sizeof(float)<<endl;//4
	cout<<"n="<<sizeof(n)<<endl;//8
	cout<<"s1="<<sizeof(s1)<<endl;//10,10,12.12

	cout<<"s2="<<sizeof(s2)<<endl;//,20,32,32
	
	cout<<"s3="<<sizeof(s3)<<endl;//7,8,12,12

	cout<<"s4="<<sizeof(s4)<<endl;//4,6,6,6
	cout<<"s5="<<sizeof(s5)<<endl;//3,4,4,4
	cout<<"s6="<<sizeof(s6)<<endl;//1,1,1,1,


	cout<<"s7="<<sizeof(s7)<<endl;//,,8,1,
	cout<<"s8="<<sizeof(s8)<<endl;//,,12,,
	cout<<"s9="<<sizeof(s9)<<endl;//7,8,8,8,
	cout<<"s10="<<sizeof(s10)<<endl;//3,4,4,4,
	cout<<"s11="<<sizeof(s11)<<endl;//3,4,4,4,
	cout<<"s12="<<sizeof(s12)<<endl;//11,12,16,16,
	cout<<"s13="<<sizeof(s13)<<endl;//7,8,8,8,
	cout<<"s14="<<sizeof(s14)<<endl;//7,8,12,12,
}