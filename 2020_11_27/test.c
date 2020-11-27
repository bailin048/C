#include <stdio.h>
#include <string.h>
#include <assert.h>
#pragma warning(disable:4996)

/// <function>判断字符串2是不是字符串1的旋转结果
/// 是return1,否则return0 
/// <param name="p"></字符串1>
/// <param name="q"></字符串2>
/// <returns></returns 布尔值>
int JudegeRotateString(char* p,char* q)
{ 
    assert(p);//输入合法性校验
    assert(q);
    if (strlen(p) != strlen(q)){ //首先长度要相同
        return 0;
    }
    char arr[100] = { '\0' };
    strcpy(arr, p);
    strcat(arr, p); //将字符串1重复两次就可包含其所有循环移位的情况
    return strstr(arr, q) == NULL ? 0 : 1;//strstr(str1,str2)：返回str1中出现str2的索引
}

/// <实现字符串向左循环移位k位>
/// <param name="str"></源串>
/// <param name="k"></左循环移位位数>
void LeftRotateStringK(char* str,int k) 
{
    int len = strlen(str);
    k %= len; //将限制在可用范围内
    char* p = str;
    char arr[100] = { '\0' };
    p += k;  //找到k个字符之后的子串
    strcpy(arr,p); //将k个字符之后的字符串复制进arr
    p -= k;    //将p重新指向源字符串首字母
    for (int i = len - k; i < len; i++) {  //将k个字符补在arr后面
        arr[i] = *p;
        p++;
    }
    strcpy(str,arr); //覆盖源串
}

/// 判断杨氏矩阵中某个数字是否存在。>
/// <param name="arr"></整型数组指针>
/// <param name="target"></查找目标>
/// <param name="row"></二维矩阵行数>
/// <param name="col"></二维矩阵列数>
/// <returns></returns 1：存在，0：不存在>
int YMatrix(const int (*arr)[5], const int target,const int row,const int col)
{
    int i = 0;
    int j = col - 1;
    while (i < row && j >= 0) { //索引未越界，右上角起查找
        if (arr[i][j] > target) {  //大于则排除一列
            j--;
        }
        else if (arr[i][j] < target) { //小于则排除一行
            i++;
        }
        else { //找到了
            return 1;
        }
    }
    return 0;//未找到
}

int main()
{
    

    //int arr[4][5] = { {1, 2, 8, 9 ,13}, 
    //                  {2, 4, 9, 12,14}, 
    //                  {4, 7, 10,13,17}, 
    //                  {6, 8, 11,15,19}};
    //int target = 20;
    //printf("%d\n",YMatrix(arr,target,4, 5));

    //char* str1 = "FGTIABCDE";
    //char* str2 = "ABCWEFGTI";
    //printf("%d\n",JudegeRotateString(str1,str2));

    /*char str1[] = "12345678";
    printf("%s\n",str1);
    LeftRotateStringK(str1, 2);
    printf("%s\n",str1);*/

    return 0;
}