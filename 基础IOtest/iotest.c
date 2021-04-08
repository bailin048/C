#include <stdio.h>
#include <string.h>

int main(){
    //fopen
    FILE* fp = fopen("./bite.txt","wb+");
    if(!fp){
        perror("open file failed!");
        return -1;
    }
    char* ptr = "linux so easy!";
    int ret = fwrite(ptr,1,strlen(ptr)+1,fp);
    if(ret<0){
        perror("write file failed!");
        return -1;
    }
    ret = fseek(fp,0,SEEK_SET);
    char res[128]={'\0'};
    fread(res,1,128,fp);
    printf("%s\n",res);
    fclose(fp);
    return 0;
}
