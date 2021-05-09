#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <error.h>

int flag = 1;//0-Aer工作 1-Ber工作
pthread_cond_t cond;//条件变量
pthread_mutex_t mutex;//互斥锁
void* Aer(void* arg){
    while(1){
        pthread_mutex_lock(&mutex);
        if(flag)
            pthread_cond_wait(&cond,&mutex);//阻塞
        flag = 1;
        printf("我是线程A\n");
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
void* Ber(void* arg){
    while(1){
        pthread_mutex_lock(&mutex);
        if(!flag)
            pthread_cond_wait(&cond,&mutex);//阻塞
        flag = 0;
        printf("我是线程B\n");
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
int main(){
    pthread_t tid[2];
    int ret;
    pthread_cond_init(&cond,NULL);
    pthread_mutex_init(&mutex,NULL);
    ret = pthread_create(&tid[0],NULL,Aer,NULL);
    if(ret){
        perror("thread create failed!");
        return -1;
    }
    ret = pthread_create(&tid[1],NULL,Ber,NULL);
    if(ret){
        perror("thread create failed!");
        return -1;
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
