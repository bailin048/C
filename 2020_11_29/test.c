#include <stdio.h>
#include <string.h>
#include <assert.h>
#pragma warning(disable:4996)
#define NUM 50
int MyStrlen(const char* str)
{
    //方法1：指针运算
    //char* p = str;
    //while (*p) {
    //    p++;
    //}
    //return p - str;
    //方法2：设置计数器
    //int cnt = 0;
    //char* p = str;
    //while (*p) {
    //    p++;
    //    cnt++;
    //}
    //return cnt;
    //方法3：递归
    if (*str) {
        return 1 + MyStrlen(str + 1);
    }
    else{
        return 0;
    }
}
char* MyStrcpy(char* des, const char* src)
{
    assert(des != NULL);
    assert(src != NULL);//输入合法性校验
    char* p = des; 
    while (*des++ = *src++) { //先++，再解引用，再赋值，再检查*des是否为\0
        ;
    }
    return p; //返回源串的地址
}
char* MyStrcat(char* des, const char* src) 
{
    char* p = des;
    assert(des != NULL);
    assert(src != NULL);
    while (*des) {
        des++;
    }
    while (*des++ = *src++) {
        ;
    }
    return p;
}
int MyStrcmp(const char* src, const char* dst) {
    int ret = 0;
    assert(src != NULL);
    assert(dst != NULL);
    while (!(ret = *(unsigned char*)src - *(unsigned char*)dst) && *dst) {//dst指向的字符串未结束且*src==*dst
        ++src, ++dst;//强转是因为ASCII编码没有负编号，为了防止数据被读成负数，因此要强转
    }//ret = 直接可以获取对比结果
    if (ret < 0) { //*src < *dst
        ret = -1;
    }
    else if (ret > 0){ //*src > *dst
        ret = 1;
    }
    return(ret); //两串相等
}
char* MyStrstr(const char* str1, const char* str2)
{
    assert(str1);
    assert(str2);//输入合法性校验
    char* cp = (char*)str1; //源串
    char* substr = (char*)str2; //被查找的字符串2
    char* s1 = NULL; //
    if (*str2 == '\0') {//
        return NULL;
    }
    while (*cp) { //源串未遍历完
        s1 = cp;  //更新s1
        substr = str2;//重置substr，令其指向字符串2
        while (*s1 && *substr && (*s1 == *substr)) {//源串未结束&&字符串2未结束&&两个还一样
            s1++; //双双后移
            substr++;
        }
        if (*substr == '\0') { //进行到这一步，说明字符串2是源串的子串
            return cp; //返回找到的出现位置
        }
        cp++; //进行到这说明目前仍未匹配成功，cp后移
    }
}
int main()
{
    char* str1 = "131254154";
    char* str2 = "131254153";
    printf("%d\n",MyStrcmp(str1,str2));
    return 0;
}