#include <stdio.h>
#include <string.h>
#include <assert.h>
#pragma warning(disable:4996)

/// <function>�ж��ַ���2�ǲ����ַ���1����ת���
/// ��return1,����return0 
/// <param name="p"></�ַ���1>
/// <param name="q"></�ַ���2>
/// <returns></returns ����ֵ>
int JudegeRotateString(char* p,char* q)
{ 
    assert(p);//����Ϸ���У��
    assert(q);
    if (strlen(p) != strlen(q)){ //���ȳ���Ҫ��ͬ
        return 0;
    }
    char arr[100] = { '\0' };
    strcpy(arr, p);
    strcat(arr, p); //���ַ���1�ظ����ξͿɰ���������ѭ����λ�����
    return strstr(arr, q) == NULL ? 0 : 1;//strstr(str1,str2)������str1�г���str2������
}

/// <ʵ���ַ�������ѭ����λkλ>
/// <param name="str"></Դ��>
/// <param name="k"></��ѭ����λλ��>
void LeftRotateStringK(char* str,int k) 
{
    int len = strlen(str);
    k %= len; //�������ڿ��÷�Χ��
    char* p = str;
    char arr[100] = { '\0' };
    p += k;  //�ҵ�k���ַ�֮����Ӵ�
    strcpy(arr,p); //��k���ַ�֮����ַ������ƽ�arr
    p -= k;    //��p����ָ��Դ�ַ�������ĸ
    for (int i = len - k; i < len; i++) {  //��k���ַ�����arr����
        arr[i] = *p;
        p++;
    }
    strcpy(str,arr); //����Դ��
}

/// �ж����Ͼ�����ĳ�������Ƿ���ڡ�>
/// <param name="arr"></��������ָ��>
/// <param name="target"></����Ŀ��>
/// <param name="row"></��ά��������>
/// <param name="col"></��ά��������>
/// <returns></returns 1�����ڣ�0��������>
int YMatrix(const int (*arr)[5], const int target,const int row,const int col)
{
    int i = 0;
    int j = col - 1;
    while (i < row && j >= 0) { //����δԽ�磬���Ͻ������
        if (arr[i][j] > target) {  //�������ų�һ��
            j--;
        }
        else if (arr[i][j] < target) { //С�����ų�һ��
            i++;
        }
        else { //�ҵ���
            return 1;
        }
    }
    return 0;//δ�ҵ�
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