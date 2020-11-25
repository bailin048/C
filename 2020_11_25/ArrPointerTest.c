#include <stdio.h>

void TestIntArr()
{
    int a[] = { 1,2,3,4 };              //4Ԫ����������
    printf("%d\n",sizeof(a));           //��������          16
    printf("%d\n", sizeof(a + 0));      //a[0]�ĵ�ַ        4
    printf("%d\n", sizeof(*a));         //a[0]              4
    printf("%d\n", sizeof(a + 1));      //a[1]�ĵ�ַ        4
    printf("%d\n", sizeof(a[1]));       //a[1]              4
    printf("%d\n", sizeof(&a));         //a�ĵ�ַ           4
    printf("%d\n", sizeof(*&a));        //a                 16
    printf("%d\n", sizeof(&a + 1));     //��a��������ĵ�ַ 4
    printf("%d\n", sizeof(&a[0]));      //a[0]�ĵ�ַ        4
    printf("%d\n", sizeof(&a[0] + 1));  //a[1]�ĵ�ַ        4
}

void TestCharArr()
{
    char arr[] = { 'a','b','c','d','e','f' };  //6Ԫ���ַ�����
    printf("%d\n", sizeof(arr));               //��������               6
    printf("%d\n", sizeof(arr + 0));           //arr[0]�ĵ�ַ           4
    printf("%d\n", sizeof(*arr));              //arr[0]                 1
    printf("%d\n", sizeof(arr[1]));            //arr[1]                 1
    printf("%d\n", sizeof(&arr));              //arr�ĵ�ַ              4
    printf("%d\n", sizeof(&arr + 1));          //��arr��������ĵ�ַ    4
    printf("%d\n", sizeof(&arr[0] + 1));       //arr[1]�ĵ�ַ           4
    //int strlen(char *);strlen�������ַ��ʼ��������0ֹͣ
    //arr[] ��û��'\0'   '\0'�����;���0
    printf("%d\n", strlen(arr));         //��������             �����>=6
    printf("%d\n", strlen(arr + 0));     //arr[0]�ĵ�ַ         �����>=6
    printf("%d\n", strlen(*arr));        //arr[0]               error���β�char*,ʵ��char
    printf("%d\n", strlen(arr[1]));      //arr[1]               error���β�char*,ʵ��char
    printf("%d\n", strlen(&arr));        //arr�ĵ�ַ            �����>=6,warning:�β�char*,ʵ��char*[6]
    printf("%d\n", strlen(&arr + 1));    //��arr��������ĵ�ַ  �����(��arr��6),warning:�β�char*,ʵ��char*[6] 
    printf("%d\n", strlen(&arr[0] + 1)); //arr[1]�ĵ�ַ         �����>=5(��arr��1)
}

void TestStringArr()
{
    char arr[] =  "abcdef";    //���ַ�����ʼ���ַ����飬���Զ����'\0'
    printf("%d\n", sizeof(arr));        //��������            7
    printf("%d\n", sizeof(arr + 0));    //arr[0]�ĵ�ַ        4
    printf("%d\n", sizeof(*arr));       //arr[0]              1
    printf("%d\n", sizeof(arr[1]));     //arr[1]              1
    printf("%d\n", sizeof(&arr));       //arr�ĵ�ַ           4 
    printf("%d\n", sizeof(&arr + 1));   //��arr��������ĵ�ַ 4
    printf("%d\n", sizeof(&arr[0] + 1));//arr[1]�ĵ�ַ        4 
    //��'\0'�Ĵ��ڣ���0
    printf("%d\n", strlen(arr));        //��������            6
    printf("%d\n", strlen(arr + 0));    //arr[0]�ĵ�ַ        6
    printf("%d\n", strlen(*arr));       //arr[0]              error 
    printf("%d\n", strlen(arr[1]));     //arr[1]              error
    printf("%d\n", strlen(&arr));       //arr�ĵ�ַ           6��warning:�β�char*��ʵ��char*[7]          
    printf("%d\n", strlen(&arr + 1));   //��arr��������ĵ�ַ �������warning:�β�char*��ʵ��char*[7]
    printf("%d\n", strlen(&arr[0] + 1));//arr[1]�ĵ�ַ        5
}

void TestStringPointer()
{
    char *p = "abcdef";
    printf("%d\n", sizeof(p));         //'a'�ĵ�ַ    4
    printf("%d\n", sizeof(p + 1));     //'b'�ĵ�ַ    4  
    printf("%d\n", sizeof(*p));        //'a'          1
    printf("%d\n", sizeof(p[0]));      //'a'          1               
    printf("%d\n", sizeof(&p));        //����ָ��     4
    printf("%d\n", sizeof(&p + 1));    //����ָ��     4
    printf("%d\n", sizeof(&p[0] + 1)); //'b'�ĵ�ַ    4
    //�ַ�����'\0'
    printf("%d\n", strlen(p));           //'a'->        6
    printf("%d\n", strlen(p + 1));       //'b'->        5
    printf("%d\n", strlen(*p));          //'a'          warning/����ʽ����   �β�char*,ʵ��char
    printf("%d\n", strlen(p[0]));        //'a'          warning/����ʽ����   �β�char*,ʵ��char
    printf("%d\n", strlen(&p));          //����ָ��     �����  warning      �β�char*,ʵ��char**
    printf("%d\n", strlen(&p + 1));      //����ָ��     �����  warning      �β�char*,ʵ��char**
    printf("%d\n", strlen(&p[0] + 1));   //'b'->        5                 
}
//
void TestInt2Arr()
{   //a��������Ԫ�أ�ÿ��Ԫ�ض���һά����
    int a[3][4] = { 0 };
                                         //����           ��ӡ���      ����
    printf("%d\n", sizeof(a));           //��������       48            int*[4]
    printf("%d\n", sizeof(a[0][0]));     //a[0][0]        4             int       
    printf("%d\n", sizeof(a[0]));        //a[0]           16            int*     
    printf("%d\n", sizeof(a[0] + 1));    //a[0][1]        4             int*
    printf("%d\n", sizeof(a + 1));       //a[1]�ĵ�ַ     4             int*[4]
    printf("%d\n", sizeof(*(a + 1)));    //a[1]           16            int*
    printf("%d\n", sizeof(&a[0] + 1));   //a[1]�ĵ�ַ     4             int*[4]
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