#include <stdio.h>
#include <assert.h>
#pragma warning(disable:4996)
//VSĬ�϶�����Ϊ8����Ϊ�������ṹ���ڲ�û�г����ֽ�������8�ĳ�Ա
//���Ը���Ա�Ķ������������ǵ����ʹ�С
//struct S
//{
//	int a; //��һ����Ա��ƫ����Ϊ0��ֱ�ӷţ����ʹ�СΪ4�ֽڣ�������һ����Ա��ƫ����Ϊ4
//	char b;//ƫ�Ƶ�ַΪ4��������Ϊ1��ƫ����4��������������1��ֱ�ӷţ����ʹ�СΪ1��������һ����Ա��ƫ����Ϊ5
//	double c;//ƫ�Ƶ�ַΪ5��������Ϊ8��ƫ����5����������������8������Ҫ�����ڴ���룬ƫ����+3 = 8����ʱƫ���������������������ţ���һ����Աƫ����Ϊ16
//	//û�ˣ�Ŀǰƫ����Ϊ16���������г�Առ16���ֽ�
//	//�ýṹ��Ķ�����=max{4,1,8}=8
//	//16��������8,����S�Ĵ�СΪ16���ֽ�
//};
//struct SS
//{
//	int a;//��һ����Ա��ƫ����Ϊ0��ֱ�ӷţ����ʹ�СΪ4�ֽڣ�������һ����Ա��ƫ����Ϊ4
//	double c;//ƫ�Ƶ�ַΪ4��������Ϊ8��ƫ����4����������������1������Ҫ�����ڴ���룬ƫ����+4 = 8����ʱƫ���������������������ţ���һ����Աƫ����Ϊ16
//	char b;//ƫ�Ƶ�ַΪ16��������Ϊ1��ƫ����16��������������1���ţ���һ����Աƫ����Ϊ17
//	//û�ˣ�Ŀǰƫ����Ϊ17���������г�Առ17���ֽ�
//	//�ýṹ��Ķ�����=max{4,1,8}=8
//	//17����������8,����Ҫ�����ڴ���룬17+7 = 24
//	//24��������8,����S�Ĵ�СΪ16���ֽ�
//};
struct S
{				 //(��ʼƫ���� + Ϊ����Ҫ������ƫ��)(������)+���ʹ�С=Ŀǰ��ռ�ֽ���
	int a;		 //0(4) + 4 = 4
	char b;		 //4(1) + 1 = 5
	double c;	 //(5 + 3)(8) + 8 = 16
				 //(16)(8) = 16
};

struct SS
{               //(��ʼƫ���� + Ϊ����Ҫ������ƫ��)(������)+���ʹ�С=Ŀǰ��ռ�ֽ���
	int _a;      // 0(4) + 4 = 4
	double _c;   // (4 + 4)(8) + 8 = 16
	char _b;     // 16(1) + 1 = 17
	            //(17 + 7)(8) = 24
};

enum color
{
	YELLOW,
	RED,
	GREEN,
	BALCK,
	//4(4)  ��ռ�ֽڣ���������   
};

struct E
{
	char a : 3;
	char b : 5;
	char c : 7;
	char d : 5;
	//3(4)  ��ռ�ֽڣ���������   
};

union Un
{
	int aa[2];
	double bb;
	//8(8)  ��ռ�ֽڣ���������   
};

struct SSS
{						//(��ʼƫ���� + Ϊ����Ҫ������ƫ��)(������)+���ʹ�С=Ŀǰ��ռ�ֽ���
	int a;	            //0 + 4 = 4
	struct SS e;		//(4 + 4)(8) + 24 = 32
	char b[5];			//32(1) + 5*1 = 37		
	double c;			//(37 + 3)(8) + 8 = 48 
	struct S g[3];		//48(8) + 3*16 = 96
	char* f[5];			//96(4) + 5*4 = 116 
	enum color u;	    //116(4) + 4 = 120
	long d[3];		    //120(4) + 3*4 = 132
	int(*p)[10];		//132(4) + 4 =136
	struct S* q[7];		//136(4) + 7*4 = 164
	short y;		    //164(2) +2 = 166
	union Un rr;		//(166 +  2)(8) + 8 = 174
					    //(174 + 2)(8) = 176
};
int main()
{
	printf("size of SSS  = %d\n",sizeof(struct SSS));
	return 0;
}






























//#define Size_char 64
//#define Num 1000
//enum { //ö�ٲ���
//    EXT,
//    Add,
//    Del, 
//    Seek,
//    Print,
//    Sort,
//};
//typedef struct //���Է�װ
//{
//    char name[Size_char/2];
//    char sex[Size_char/4];
//    int age;
//    long long tel;
//    char addr[Size_char];
//}USER;
//
//typedef struct USER//�ṹ�壺����Ա��Ϣ��װ
//{
//    PeoInfo* data;  //����ָ��
//    int count;  //��ǰ����
//    int capacity;//�������
//}USER, * puser;
//void menu()
//{
//    printf("###############################\n");
//    printf("#########1 �����ϵ�� #########\n");
//    printf("#########2 ɾ����ϵ�� #########\n");
//    printf("#########3 ������ϵ�� #########\n");
//    printf("#########4 ��ʾ������ #########\n");
//    printf("#########5 ���������� #########\n");
//    printf("#########0 �˳��绰�� #########\n");
//    printf("###############################\n");
//}
//
//void AddPerson(USER per[])
//{
//    static USER* p = per;
//
//}
//void DelPerson() {}
//void SeekPerson(USER per[])
//{
//    char name[Size_char / 2];
//    printf("��������Ҫ���ҵ���ϵ������# ");
//    scanf("%s",name);
//    for (int i = 0; i < Num; i++) {
//        if (per[i].name == name) { 
//            printf("��ϵ��������%s\n", per[i].name);
//            printf("      �Ա�%s\n", per[i].sex);
//            printf("      ���䣺%d\n", per[i].age);
//            printf("      �绰��%ld\n", per[i].tel);
//            printf("      סַ��%s\n", per[i].addr);
//            return 0;
//        }   
//    }
//    printf("��ϵ�˲����ڣ�\n");
//}
//void PrintAll(USER per[]) 
//{
//    printf("    ����      �Ա�       ����      �绰         סַ       \n");
//    for (int i = 0; i < Num && per[i].name != '\0'; i++) {
//        printf("%s %4s %3d %11ld %12s\n",per[i].name,per[i].sex,\
//            per[i].age,per[i].tel,per[i].addr);
//    }
//}
//void SortName() {}
//int main()
//{
//    USER per[Num] = {'\0','\0',0,0,'\0'}; //�����ṹ������
//    int exit = 1;//�˳���־��Ϊ0�˳�
//    while (exit) {
//        menu();
//        int choice = 0;
//        printf("����������Ŀ��# ");
//        scanf("%d",&choice);
//        system("cls");
//        switch (choice) {
//            case Add:AddPerson(); break;
//            case Del:DelPerson(); break;
//            case Seek:SeekPerson(per); break;
//            case Print:PrintAll(per); break;
//            case Sort:SortName(); break;
//            case EXT:exit = 0; break;
//            default:printf("�����������������# "); break;
//        }
//    }
//    return 0;
//}