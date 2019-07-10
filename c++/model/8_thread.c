#include <pthread.h>

#include <stdio.h>

#include <string.h>

#include <unistd.h>

void *ThreadFunc()
{
    static int count = 1;
    printf ("Create thread %d\n", count);
    count++;
    pthread_detach(pthread_self()); //标记为DETACHED状态，完成后释放自己占用的资源
}
void main(void)

{
    int     err;
    pthread_t tid;
    while (1)
    {
           err= pthread_create(&tid, NULL, ThreadFunc, NULL);
           if(err != 0){
               printf("can't create thread: %s\n",strerror(err));
           break;
           }
          usleep(2000);
    }
}
