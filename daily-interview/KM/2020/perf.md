



### case 1



~~~
//test.c 
void longa() 
{ 
  int i,j; 
  for(i = 0; i < 1000000; i++) 
  j=i; //am I silly or crazy? I feel boring and desperate. 
} 
 
void foo2() 
{ 
  int i; 
  for(i=0 ; i < 10; i++) 
       longa(); 
} 
 
void foo1() 
{ 
  int i; 
  for(i = 0; i< 100; i++) 
     longa(); 
} 
 
int main(void) 
{ 
  foo1(); 
  foo2(); 
}
https://www.ibm.com/developerworks/cn/linux/l-cn-perf1/index.html?ca=drs-
gcc -o  t1  -g  ./test.c
perf stat ./t1 
~~~





~~~shell
perf stat ./t1 
perf stat ./t1 

 Performance counter stats for './t1':

        333.929337      task-clock (msec)         #    0.999 CPUs utilized           
                 0      context-switches          #    0.000 K/sec                  
                 1      cpu-migrations            #    0.003 K/sec                  
                97      page-faults               #    0.290 K/sec                  
         

       0.334224488 seconds time elapsed
 Task-clock-msecs：CPU 利用率，该值高，说明程序的多数时间花费在 CPU 计算上而非 IO。

Context-switches：进程切换次数，记录了程序运行过程中发生了多少次进程切换，频繁的进程切换是应该避免的。

Cache-misses：程序运行过程中总体的 cache 利用情况，如果该值过高，说明程序的 cache 利用不好
~~~





~~~
#include <stdio.h> 
#include <stdlib.h> 
 
void foo() 
{ 
 int i,j; 
 for(i=0; i< 10; i++) 
 j+=2; 
} 
int main(void) 
{ 
 int i; 
 for(i = 0; i< 100000000; i++) 
 foo(); 
 return 0; 
}
gcc -o  t3  -g  ./test.c
~~~



### ref

1.  [Linux 效能分析工具: Perf](http://wiki.csie.ncku.edu.tw/embedded/perf-tutorial)
2.  http://www.brendangregg.com/perf.html