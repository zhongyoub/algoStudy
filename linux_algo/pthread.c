#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

void printids(const char* s)
{
    pid_t pid;
    pthread_t tid;
    pid=getpid();
    tid=pthread_self();
    printf("%s pid %u tid %u(0x%x)\n",s,(unsigned int)pid,(unsigned int)tid,(unsigned int)tid);
}

void* thr_fn(void* arg)
{
    printids("new thead:");
    return NULL;
}

int main()
{
    int err;
    pthread_t ntid;
    err=pthread_create(&ntid,NULL,thr_fn,NULL);
    if(err!=0)
        printf("can not create thread:%s\n",strerror(err));
    printids("main thread:");
    pthread_join(ntid,NULL);
    return 0;
}
