#include <stdio.h>

void TestIntArr()
{
    int a[] = { 1,2,3,4 };              //4元素整型数组
    printf("%d\n",sizeof(a));           //整个数组          16
    printf("%d\n", sizeof(a + 0));      //a[0]的地址        4
    printf("%d\n", sizeof(*a));         //a[0]              4
    printf("%d\n", sizeof(a + 1));      //a[1]的地址        4
    printf("%d\n", sizeof(a[1]));       //a[1]              4
    printf("%d\n", sizeof(&a));         //a的地址           4
    printf("%d\n", sizeof(*&a));        //a                 16
    printf("%d\n", sizeof(&a + 1));     //与a相邻数组的地址 4
    printf("%d\n", sizeof(&a[0]));      //a[0]的地址        4
    printf("%d\n", sizeof(&a[0] + 1));  //a[1]的地址        4
}

void TestCharArr()
{
    char arr[] = { 'a','b','c','d','e','f' };  //6元素字符数组
    printf("%d\n", sizeof(arr));               //整个数组               6
    printf("%d\n", sizeof(arr + 0));           //arr[0]的地址           4
    printf("%d\n", sizeof(*arr));              //arr[0]                 1
    printf("%d\n", sizeof(arr[1]));            //arr[1]                 1
    printf("%d\n", sizeof(&arr));              //arr的地址              4
    printf("%d\n", sizeof(&arr + 1));          //与arr相邻数组的地址    4
    printf("%d\n", sizeof(&arr[0] + 1));       //arr[1]的地址           4
    //int strlen(char *);strlen从输入地址开始计数，遇0停止
    //arr[] 中没有'\0'   '\0'的整型就是0
    printf("%d\n", strlen(arr));         //整个数组             随机数>=6
    printf("%d\n", strlen(arr + 0));     //arr[0]的地址         随机数>=6
    printf("%d\n", strlen(*arr));        //arr[0]               error，形参char*,实参char
    printf("%d\n", strlen(arr[1]));      //arr[1]               error，形参char*,实参char
    printf("%d\n", strlen(&arr));        //arr的地址            随机数>=6,warning:形参char*,实参char*[6]
    printf("%d\n", strlen(&arr + 1));    //与arr相邻数组的地址  随机数(比arr少6),warning:形参char*,实参char*[6] 
    printf("%d\n", strlen(&arr[0] + 1)); //arr[1]的地址         随机数>=5(比arr少1)
}

void TestStringArr()
{
    char arr[] =  "abcdef";    //以字符串初始化字符数组，会自动添加'\0'
    printf("%d\n", sizeof(arr));        //整个数组            7
    printf("%d\n", sizeof(arr + 0));    //arr[0]的地址        4
    printf("%d\n", sizeof(*arr));       //arr[0]              1
    printf("%d\n", sizeof(arr[1]));     //arr[1]              1
    printf("%d\n", sizeof(&arr));       //arr的地址           4 
    printf("%d\n", sizeof(&arr + 1));   //与arr相邻数组的地址 4
    printf("%d\n", sizeof(&arr[0] + 1));//arr[1]的地址        4 
    //有'\0'的存在，即0
    printf("%d\n", strlen(arr));        //整个数组            6
    printf("%d\n", strlen(arr + 0));    //arr[0]的地址        6
    printf("%d\n", strlen(*arr));       //arr[0]              error 
    printf("%d\n", strlen(arr[1]));     //arr[1]              error
    printf("%d\n", strlen(&arr));       //arr的地址           6，warning:形参char*，实参char*[7]          
    printf("%d\n", strlen(&arr + 1));   //与arr相邻数组的地址 随机数，warning:形参char*，实参char*[7]
    printf("%d\n", strlen(&arr[0] + 1));//arr[1]的地址        5
}

void TestStringPointer()
{
    char *p = "abcdef";
    printf("%d\n", sizeof(p));         //'a'的地址    4
    printf("%d\n", sizeof(p + 1));     //'b'的地址    4  
    printf("%d\n", sizeof(*p));        //'a'          1
    printf("%d\n", sizeof(p[0]));      //'a'          1               
    printf("%d\n", sizeof(&p));        //二级指针     4
    printf("%d\n", sizeof(&p + 1));    //二级指针     4
    printf("%d\n", sizeof(&p[0] + 1)); //'b'的地址    4
    //字符串带'\0'
    printf("%d\n", strlen(p));           //'a'->        6
    printf("%d\n", strlen(p + 1));       //'b'->        5
    printf("%d\n", strlen(*p));          //'a'          warning/运行式报错   形参char*,实参char
    printf("%d\n", strlen(p[0]));        //'a'          warning/运行式报错   形参char*,实参char
    printf("%d\n", strlen(&p));          //二级指针     随机数  warning      形参char*,实参char**
    printf("%d\n", strlen(&p + 1));      //二级指针     随机数  warning      形参char*,实参char**
    printf("%d\n", strlen(&p[0] + 1));   //'b'->        5                 
}
//
void TestInt2Arr()
{   //a里面三个元素，每个元素都是一维数组
    int a[3][4] = { 0 };
                                         //意义           打印结果      类型
    printf("%d\n", sizeof(a));           //整个数组       48            int*[4]
    printf("%d\n", sizeof(a[0][0]));     //a[0][0]        4             int       
    printf("%d\n", sizeof(a[0]));        //a[0]           16            int*     
    printf("%d\n", sizeof(a[0] + 1));    //a[0][1]        4             int*
    printf("%d\n", sizeof(a + 1));       //a[1]的地址     4             int*[4]
    printf("%d\n", sizeof(*(a + 1)));    //a[1]           16            int*
    printf("%d\n", sizeof(&a[0] + 1));   //a[1]的地址     4             int*[4]
    printf("%d\n", sizeof(*(&a[0] + 1)));//a[1]           16            int*
    printf("%d\n", sizeof(*a));          //a[0]           16            int*
}

int main()
{
    //TestIntArr();
    //TestCharArr();
    //TestStringArr();
    //TestStringPointer();
    TestInt2Arr();
    return 0;
}