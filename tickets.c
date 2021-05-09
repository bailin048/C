#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int tickets = 100;//临界资源
pthread_mutex_t mutex;//互斥锁

void* scalpers(void* arg){
    while(1){
        pthread_mutex_lock(&mutex);//加锁
        if(tickets>0){
            usleep(1);
            printf("我抢到了一张票:%p-%d\n",pthread_self(),tickets);
            --tickets;
        }else{
            pthread_mutex_unlock(&mutex);//解锁
            pthread_exit(NULL);//线程退出
        }
        pthread_mutex_unlock(&mutex);//解锁
        usleep(1);//防止时间片仍被线程掌握
    }
    return NULL;
}
int main(){
    int ret;
    pthread_t tid[4];//准备创建4个线程
    pthread_mutex_init(&mutex,NULL);//初始化互斥锁
    int i = 0;
    for(;i<4;++i){
        ret = pthread_create(&tid[i],NULL,scalpers,NULL);//创建4个黄牛线程
        if(ret){
            perror("threat creat failed!");
            return -1;
        }
    }
    for(i = 0;i<4;++i)
        pthread_join(tid[i],NULL);//线程等待
    pthread_mutex_destroy(&mutex);//销毁互斥锁
    return 0;
}
