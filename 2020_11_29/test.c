#include <stdio.h>
#include <string.h>
#include <assert.h>
#pragma warning(disable:4996)
#define NUM 50
int MyStrlen(const char* str)
{
    //����1��ָ������
    //char* p = str;
    //while (*p) {
    //    p++;
    //}
    //return p - str;
    //����2�����ü�����
    //int cnt = 0;
    //char* p = str;
    //while (*p) {
    //    p++;
    //    cnt++;
    //}
    //return cnt;
    //����3���ݹ�
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
    assert(src != NULL);//����Ϸ���У��
    char* p = des; 
    while (*des++ = *src++) { //��++���ٽ����ã��ٸ�ֵ���ټ��*des�Ƿ�Ϊ\0
        ;
    }
    return p; //����Դ���ĵ�ַ
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
    while (!(ret = *(unsigned char*)src - *(unsigned char*)dst) && *dst) {//dstָ����ַ���δ������*src==*dst
        ++src, ++dst;//ǿת����ΪASCII����û�и���ţ�Ϊ�˷�ֹ���ݱ����ɸ��������Ҫǿת
    }//ret = ֱ�ӿ��Ի�ȡ�ԱȽ��
    if (ret < 0) { //*src < *dst
        ret = -1;
    }
    else if (ret > 0){ //*src > *dst
        ret = 1;
    }
    return(ret); //�������
}
char* MyStrstr(const char* str1, const char* str2)
{
    assert(str1);
    assert(str2);//����Ϸ���У��
    char* cp = (char*)str1; //Դ��
    char* substr = (char*)str2; //�����ҵ��ַ���2
    char* s1 = NULL; //
    if (*str2 == '\0') {//
        return NULL;
    }
    while (*cp) { //Դ��δ������
        s1 = cp;  //����s1
        substr = str2;//����substr������ָ���ַ���2
        while (*s1 && *substr && (*s1 == *substr)) {//Դ��δ����&&�ַ���2δ����&&������һ��
            s1++; //˫˫����
            substr++;
        }
        if (*substr == '\0') { //���е���һ����˵���ַ���2��Դ�����Ӵ�
            return cp; //�����ҵ��ĳ���λ��
        }
        cp++; //���е���˵��Ŀǰ��δƥ��ɹ���cp����
    }
}
int main()
{
    char* str1 = "131254154";
    char* str2 = "131254153";
    printf("%d\n",MyStrcmp(str1,str2));
    return 0;
}