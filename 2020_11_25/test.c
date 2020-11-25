#include <stdio.h>
#include <string.h>
#include <assert.h>

int IntCmp(const void* p,const void* q) 
{
    return (*(int*)p) - (*(int*)q); //��ǿת�ٽ����ã����㷵��ֵ
}
int StringCmp(const void* p, const void* q)
{
    const char* ps = *(char**)p;  //��һ��ָ�����ݸ���ps,psָ��һ�ַ�����Ԫ��
    const char* qs = *(char**)q;  //��һ��ָ�����ݸ���qs,qsָ��һ�ַ�����Ԫ��
    return strcmp(ps, qs);        //strcmp�����ַ����ȽϽ��
}
int CharCmp(const void* p, const void* q)
{
    return (*(char*)p) - (*(char*)q); //��ǿת�ٽ����ã����㷵��ֵ
}
void Swap(char* p, char* q, size_t num) {
    while (num) {       //���ֽڽ���
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
    assert(base);  //����Ϸ���У��
    assert(cmp);
    int flag = 1;  //���Ա�������󣬼���ѭ����������
    for (size_t i = 0; i < num - 1&&flag; i++) { //δѭ�����Ҵ�������
        flag = 0;  //����������
        for (size_t j = 0; j < num - 1 - i; j++) {
            if (cmp((char*)base + j * byte, (char*)base + (j + 1) * byte) > 0) { 
                Swap((char*)base + j * byte, (char*)base + (j + 1) * byte,byte); //����
                flag = 1; //����������Ϊ��˵����������
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