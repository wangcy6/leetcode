#include<stdio.h>
#include<iostream>
#include <string.h>
#include <memory>
#include <mutex>
#include <thread>
using namespace std;

shared_ptr<long> global_instance = make_shared<long>(0);
std::mutex g_i_mutex;
 
void thread_fcn()
{
    //std::lock_guard<std::mutex> lock(g_i_mutex);
     shared_ptr<long> local = global_instance; // thread-safe
 
    for(int i = 0; i < 100000000; i++)
    {
        //*global_instance = *global_instance + 1;
        *local = *local + 1;
    }
}
//g++ -std=c++11 thead_01.cpp -lpthread 
int main(int argc, char** argv)
{
    thread thread1(thread_fcn);
    thread thread2(thread_fcn);
 
    thread1.join();
    thread2.join();
 
    cout << "*global_instance is " << *global_instance << endl;
 
    return 0;
}