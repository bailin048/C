#include <stdio.h>
#pragma warning(disable:4996)

//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
void SortChampion()
{
    int a, b, c, d, e;
    for (a = 1; a <= 5; a++)
    {
        for (b = 1; b <= 5; b++)
        {
            for (c = 1; c <= 5; c++)
            {
                for (d = 1; d <= 5; d++)
                {
                    for (e = 1; e <= 5; e++)
                    {
                        if ((b == 3) + (a == 3) == 1 &&
                            (b == 2) + (e == 4) == 1 &&
                            (c == 1) + (d == 2) == 1 &&
                            (c == 5) + (d == 3) == 1 &&
                            (e == 4) + (a == 1) == 1){
                            printf("A=%d, B=%d, C=%d, D=%d, E=%d\n",a, b, c, d, e);
                        }
                    }
                }
            }
        }
    }
}

/// <summary>
/// �жϼ������С��ģʽ
/// </summary>
/// <returns></returns  1:С�� 0:���>
int Check_Sys()
{
    int i = 1;
    //1�Ĳ��룺 0000 0000   0000 0000   0000 0000   0000 0001
    //�ֽڻ��֣�0000 0000 | 0000 0000 | 0000 0000 | 0000 0001
    //             ��λ ----------------------------> ��λ
    return (*(char*)&i); 
    //(*(char*)&i) :  ��i�ĵ�ַǿתchar *,�ٽ����ã�ʵ�ַ��ر����͵�ַ�ռ��е�����
    // �����˴洢��Ӧ�÷���0�����򷵻�1
}

int Add(int x, int y)
{   
    return x + y;
}
int Sub(int x,int y)
{
    return x - y;
}
int Mul(int x, int y)
{
    return x * y;
}
int Div(int x, int y)
{
    return x / y;
}
int main()
{
    int x, y;
    int input = 1;
    int ret = 0;
    int (*p[5])(int x, int y) = { 0,Add,Sub,Mul,Div };//ת�Ʊ�
    while (input) {
        printf("*************************\n");
        printf("***  1:add     2.sub  ***\n");
        printf("***  3:mul     4.div  ***\n");
        printf("��ѡ��# ");
        scanf("%d",&input);
        if (input <= 4 && input >= 1) {
            printf("�����������# ");
            scanf("%d %d",&x,&y);
            ret = (*p[input])(x, y);
        }
        else{
            printf("�������\n");
        }
        printf("ret = %d\n",ret);
    }
    return 0;
}