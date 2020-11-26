#include <stdio.h>

/// <function>实现字符串左移位循环k位
/// eg. ABCDEF->向左移位循环3位->DEFABC
/// <param name="str"></const char *>指向字符数组首元素
/// <param name="num"></const int>字符数组元素数目
/// <param name="k"></int>移位位数
/// 无返回值
void LeftRotateStringK(const char* str,const int num,int k)
{
    if (k > 0) { //递归出口
        char tmp = *str; //保存第一个字符
        char* p = str;   //双指针为依次覆盖做准备
        char* q = p + 1;
        while (*q) { //依次往前覆盖，遇\0结束
            *p = *q;
            p++;
            q++;
        }
        *(q - 1) = tmp; //因为q指向\0，所以要减1
        LeftRotateStringK(str, num, k - 1);
    }
    else {
        return 0;
    }
}

int main()
{

    char str[] = "ABCDEFGTI";
    int k = 3;
    int num = sizeof(str) / sizeof(str[0]);
    printf("%s\n",str);
    LeftRotateStringK(str,num,k);
    printf("%s\n",str);
    return 0;
}