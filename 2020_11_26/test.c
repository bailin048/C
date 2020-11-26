#include <stdio.h>

/// <function>ʵ���ַ�������λѭ��kλ
/// eg. ABCDEF->������λѭ��3λ->DEFABC
/// <param name="str"></const char *>ָ���ַ�������Ԫ��
/// <param name="num"></const int>�ַ�����Ԫ����Ŀ
/// <param name="k"></int>��λλ��
/// �޷���ֵ
void LeftRotateStringK(const char* str,const int num,int k)
{
    if (k > 0) { //�ݹ����
        char tmp = *str; //�����һ���ַ�
        char* p = str;   //˫ָ��Ϊ���θ�����׼��
        char* q = p + 1;
        while (*q) { //������ǰ���ǣ���\0����
            *p = *q;
            p++;
            q++;
        }
        *(q - 1) = tmp; //��Ϊqָ��\0������Ҫ��1
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