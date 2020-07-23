#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/syscall.h>
#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
#include<iostream>
#include <signal.h>
#include <string.h>
using namespace std;

#define gettid()    syscall(__NR_gettid)

#define log_info(fmt, args...)  do {                                    \
	printf("[%ld] %ld info : " fmt, gettid(), time(NULL), ## args); \
} while(0)
#define log_error(fmt, args...) do {                                    \
	printf("[%ld] %ld error: " fmt, gettid(), time(NULL), ## args); \
} while(0)

#define THD_NUMS   1

void sighandler(int signo)
{
        log_info("Thread %lu received signo %d.\n", gettid(), signo);
}

void *thr1_fn(void *arg)
{       
                /* register but still blocked now */
		struct sigaction action;
        action.sa_flags = 0;
        action.sa_handler = sighandler;
        sigaction(SIGQUIT, &action, NULL);
		
        (void) arg;

        log_info("Worker thread started.\n");
        while (1)
                sleep(1);

        return NULL;
}
class SigalQuitTest {

public:
//    SigalQuitTest();
//    ~SigalQuitTest();

    static void* pthread_handle(void* obj);
    void chreat_pthread();

private:
     pthread_t pid1;
    pthread_t pid2;
//    sigaction actions;
};


void handle_quit(int signo)
{
    LOGI("SigalQuitTest  [handle_quit signal:%d]", signo);
//    pthread_exit(NULL);

}

//SigalQuitTest::SigalQuitTest() {
//
//}
//
//SigalQuitTest::~SigalQuitTest() {
//
//}

void* SigalQuitTest::pthread_handle(void* obj) {

//    signal(SIGQUIT,handle_quit );
//    memset(&actions, 0, sizeof(actions));
    struct sigaction actions;
//        sigemptyset(&actions.sa_mask);
    actions.sa_flags = 0;
    actions.sa_handler = handle_quit;
    sigaction(SIGUSR1,&actions,NULL);

        LOGI("SigalQuitTest  [pthread_handle] [in pthread test] %lu", gettid());
    sleep(25);

}

void SigalQuitTest::chreat_pthread() {
    LOGI("SigalQuitTest  [chreat_pthread] [begin] pid=%d", pid1);
    LOGI("SigalQuitTest  [chreat_pthread] [begin] pid=%d", pid2);

    struct sigaction actions;
//        sigemptyset(&actions.sa_mask);
    actions.sa_flags = 0;
    actions.sa_handler = handle_quit;
    sigaction(SIGUSR1,&actions,NULL);


    pthread_create(&pid1, NULL , &pthread_handle, NULL);
    pthread_create(&pid2, NULL , &pthread_handle, NULL);
    sleep(3);

        LOGI("SigalQuitTest  [chreat_pthread] [thread %lu exists!]", pid1);
    LOGI("SigalQuitTest  [chreat_pthread] [thread %lu exists!]", pid2);
        int sturt = pthread_kill(pid1, SIGUSR1);
    if(sturt == ESRCH)
    {
        LOGI("SigalQuitTest  [pthread_kill] [ESRCH]");
    }else if(sturt == EINVAL)
    {
        LOGI("SigalQuitTest  [pthread_kill] [EINVAL]");
    }
    LOGI("SigalQuitTest  [pthread_kill] [sturt %d!]", sturt);
    pthread_kill(pid2, SIGUSR1);
        LOGI("SigalQuitTest  [chreat_pthread] [after kill]");


    sleep(30);
    LOGI("SigalQuitTest  [chreat_pthread] [exit in chreat_pthread]");
}

//g++ thread.cpp -pthread
int main(void)
{    
        int i, rc;
		/*
        sigset_t bset;
        sigemptyset(&bset);
        sigaddset(&bset, SIGINT);*/
		
        pthread_t thds[THD_NUMS];

      


        log_info("Main thread started.\n");

        for (i = 0; i < THD_NUMS; i++) {
                rc = pthread_create(&thds[i], NULL, thr1_fn, NULL);
                if (rc != 0) {
                        log_error("Create thread failed, %s.\n", strerror(rc));
                        exit(1);
                }
        }

        /* only accpet SIGINT in main thread 
        if (pthread_sigmask(SIG_UNBLOCK, &bset, NULL) != 0) {
                log_error("Set pthread mask failed.");
                exit(1);
        }
       if (pthread_sigmask(SIG_BLOCK, &bset, NULL) != 0) {
                log_error("Set pthread mask failed.");
                exit(1);
        }*/
		
		sleep(2);
		log_info("11111111111111111111111Thread %ld received signo .\n", thds[0]);
		pthread_kill(thds[0],SIGQUIT);
 /*
		
        for (i = 0; i < THD_NUMS; i++)
                pthread_join(thds[i], NULL);*/
			
		sleep(20);

        return 0;
}
