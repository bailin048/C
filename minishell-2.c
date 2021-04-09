#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pwd.h>
#include <fcntl.h>
#include <unistd.h>

//自定义
#define QUIT "quit"
#define DEFAULT_PATH "path_error"
#define COMMAND_DEFAULT_LENGTH 1024
#define COMMAND_NUMBER 32



char* GetRoute();
void PrintInfo();
int SplitInput(char* buf,char* myargv[]);
void MyCd(char* path);


void PrintInfo(){
    struct passwd *pwd = NULL;
    pwd = getpwuid(getuid());
    printf("[%s@BL-0-4-centos %s]$ ",pwd->pw_name,GetRoute());
    fflush(stdout);//强制刷新缓冲区
}

char* GetRoute(){
    char* temp = (char*)calloc(COMMAND_DEFAULT_LENGTH/2,1);
    getcwd(temp,COMMAND_DEFAULT_LENGTH/2-1);
    int len = strlen(temp);
    if(len){//获取最近的一个路径，从尾部向前查找/，遇到后即找到
        int len = strlen(temp);
        char* ptr = temp + len;//此处应指向最后一个非\0字符
        while(*ptr != '/')
            --ptr;
        free(temp);//释放空间，但数据仍在
        return ptr+1;//因为ptr指向倒数第一个/所以要+1
    }
    return DEFAULT_PATH;
    //此处应该要提醒自己，除非像这种即调即用，一出结果立马用且不会修改结果的函数可以直接返回函数内部的指针。
    //其他函数应理智，因为函数运行结束会释放空间，一旦其他函数进栈，会有数据丢失的风险！！！
}

int SplitInput(char* input,char* myargv[]){//返回值为重定向标志
    //先检测重定向，进行字符串替换，将'>'换为' ',置换时改写重定向标志
    size_t redirect_flag = 0;
    char* p = input;
    int flag = 1;
    while(*p){
        if(*p == '>' && flag == 1){
            *p = ' ';
            redirect_flag = 1;//清空重定向
            flag = 0;
        }
        else if(*p == '>' && flag == 0){
            *p = ' ';
            redirect_flag = 2;
            break;
        }
        ++p;
    }
    //字符串分割
    int myargc = 0;
    char* ptr = input;
    while(*ptr){//输入非空
        if(!isspace(*ptr)){//当前非空白符
            myargv[myargc++] = ptr; //首字母地址记录
            while(!isspace(*ptr))
                ++ptr;
            *ptr = '\0';//该单词截止
        }
        ++ptr;
    }
    return redirect_flag;
}
void MyCd(char* path){
    if(!path)//路径为空
        return;
    else if(*path == '~'){//返回用户目录
        struct passwd *pwd = NULL;
        pwd = getpwuid(getuid());
        char root_path[64] = {"/home/"};
        strcat(root_path,pwd->pw_name);//家目录拼接用户
        chdir(root_path);
    }
    else if(!strcmp(path,"..")){//上层目录
        char pre_path[COMMAND_DEFAULT_LENGTH/2] = {'\0'};
        getcwd(pre_path,COMMAND_DEFAULT_LENGTH/2-1);
        int len = strlen(pre_path);
        char* ptr = pre_path + len;//追到倒数第一/
        while(*ptr != '/')
            --ptr;
        *ptr = '\0';//路径截止
        printf("%s\n",pre_path);
        chdir(pre_path);
    }
    else
        chdir(path);
}

int main(int argc,char* argv[]){
    while(1){
        //打印信息
        PrintInfo();

        //获取输入
        char buf[COMMAND_DEFAULT_LENGTH] = {'\0'};//因为一维数组，且后续代码不保存历史指令，所以不支持向上追溯历史指令
        fgets(buf,COMMAND_DEFAULT_LENGTH-1,stdin);

        //切分参数
        char* myargv[COMMAND_NUMBER] = {NULL}; 
        int redirect_flag = SplitInput(buf,myargv);
        
        //命令匹配
        if(!strcmp(myargv[0],QUIT))//退出
            exit(0);
        else if(!strcmp(myargv[0],"cd")){//cd 命令
            MyCd(myargv[1]);
            continue;
        }
        //创建子进程
        pid_t ret = fork();
        if(ret < 0)
            continue;
        else if(!ret){//进程程序替换
            if(redirect_flag){ //存在重定向
                if(redirect_flag == 1){//清空重定向
                    int fd = open(myargv[2],O_CREAT|O_TRUNC|O_WRONLY,0664);
                    dup2(fd,1);
                }
                if(redirect_flag == 2){//追加重定向 
                    int fd = open(myargv[2],O_CREAT|O_APPEND|O_WRONLY,0664);
                    dup2(fd,1);
                }
            }
            myargv[2] = NULL;
            execvp(myargv[0],myargv);
            exit(-1);//替换失败，子进程退出；成功则不会执行到此处
        }
        wait(NULL);//父进程等待子进程，避免僵死进程的产生
    }
    return 0;
}
