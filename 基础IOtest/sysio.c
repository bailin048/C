#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    int fd = open("bite.txt",O_RDWR|O_CREAT,0664);
    if(fd<0){
        perror("open file failed!");
        return -1;
    }
    char* ptr = "i like linux!\n";
    int ret = write(fd,ptr,strlen(ptr));
    if(ret<0){
        perror("write file failed!");
        return -1;
    }
    lseek(fd,0,SEEK_SET);
    char buf[128] = {'\0'};
    ret = read(fd,buf,127);
    if(ret<0){
        perror("read file failed!");
        return -1;
    }
    close(fd);
    printf("%s",buf);
    return 0;
}
