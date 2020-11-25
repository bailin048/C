#include <stdio.h>
#include <string.h>
#include <assert.h>

int IntCmp(const void* p,const void* q) 
{
    return (*(int*)p) - (*(int*)q); //先强转再解引用，再算返回值
}
int StringCmp(const void* p, const void* q)
{
    const char* ps = *(char**)p;  //将一级指针内容赋给ps,ps指向一字符串首元素
    const char* qs = *(char**)q;  //将一级指针内容赋给qs,qs指向一字符串首元素
    return strcmp(ps, qs);        //strcmp计算字符串比较结果
}
int CharCmp(const void* p, const void* q)
{
    return (*(char*)p) - (*(char*)q); //先强转再解引用，再算返回值
}
void Swap(char* p, char* q, size_t num) {
    while (num) {       //按字节交换
        int tmp = *p;  
        *p = *q;
        *q = tmp;
        q++,p++;
        num--;
    }
}
void Bubble_sort(void* base, size_t num, size_t byte,\
    const int(*cmp)(const void*, const void*))
{
    assert(base);  //输入合法性校验
    assert(cmp);
    int flag = 1;  //可以避免有序后，继续循环查找逆序
    for (size_t i = 0; i < num - 1&&flag; i++) { //未循环完且存在逆序
        flag = 0;  //不存在逆序
        for (size_t j = 0; j < num - 1 - i; j++) {
            if (cmp((char*)base + j * byte, (char*)base + (j + 1) * byte) > 0) { 
                Swap((char*)base + j * byte, (char*)base + (j + 1) * byte,byte); //交换
                flag = 1; //发生交换行为则说明存在逆序
            }
        }
    }
}
int main()
{
    //char* arr[] = { "aaaa","aaab","bb0","11" };
    //int num = sizeof(arr) / sizeof(arr[0]);
    //Bubble_sort(arr, num, sizeof(char*), StringCmp);
    //int arr[] = { 1,3,4,2,6,54,57,56,8,6,7,9,2,3,1,1,3 };
    //int num = sizeof(arr) / sizeof(arr[0]);
    //Bubble_sort(arr, num, sizeof(int), IntCmp);
    char arr[] = { 'a','0','1',' ','9' };
    int num = sizeof(arr) / sizeof(arr[0]);
    Bubble_sort(arr, num, sizeof(char), CharCmp);
    return 0;
}