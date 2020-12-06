#include <stdio.h>
#include <assert.h>
#pragma warning(disable:4996)
//VS默认对齐数为8，因为这两个结构体内并没有出现字节数大于8的成员
//所以各成员的对齐数就是它们的类型大小
//struct S
//{
//	int a; //第一个成员，偏移量为0，直接放，类型大小为4字节，所以下一个成员的偏移量为4
//	char b;//偏移地址为4，对齐数为1，偏移量4可以整除对齐数1，直接放，类型大小为1，所以下一个成员的偏移量为5
//	double c;//偏移地址为5，对齐数为8，偏移量5不可以整数对齐数8，所以要发生内存对齐，偏移量+3 = 8，此时偏移量可以整除对齐数，放，下一个成员偏移量为16
//	//没了，目前偏移量为16，所以所有成员占16个字节
//	//该结构体的对齐数=max{4,1,8}=8
//	//16可以整除8,所以S的大小为16个字节
//};
//struct SS
//{
//	int a;//第一个成员，偏移量为0，直接放，类型大小为4字节，所以下一个成员的偏移量为4
//	double c;//偏移地址为4，对齐数为8，偏移量4不可以整除对齐数1，所以要发生内存对齐，偏移量+4 = 8，此时偏移量可以整除对齐数，放，下一个成员偏移量为16
//	char b;//偏移地址为16，对齐数为1，偏移量16可以整数对齐数1，放，下一个成员偏移量为17
//	//没了，目前偏移量为17，所以所有成员占17个字节
//	//该结构体的对齐数=max{4,1,8}=8
//	//17不可以整除8,所以要发生内存对齐，17+7 = 24
//	//24可以整除8,所以S的大小为16个字节
//};
struct S
{				 //(初始偏移量 + 为对齐要发生的偏移)(对齐数)+类型大小=目前所占字节数
	int a;		 //0(4) + 4 = 4
	char b;		 //4(1) + 1 = 5
	double c;	 //(5 + 3)(8) + 8 = 16
				 //(16)(8) = 16
};

struct SS
{               //(初始偏移量 + 为对齐要发生的偏移)(对齐数)+类型大小=目前所占字节数
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
	//4(4)  所占字节（对齐数）   
};

struct E
{
	char a : 3;
	char b : 5;
	char c : 7;
	char d : 5;
	//3(4)  所占字节（对齐数）   
};

union Un
{
	int aa[2];
	double bb;
	//8(8)  所占字节（对齐数）   
};

struct SSS
{						//(初始偏移量 + 为对齐要发生的偏移)(对齐数)+类型大小=目前所占字节数
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
//enum { //枚举操作
//    EXT,
//    Add,
//    Del, 
//    Seek,
//    Print,
//    Sort,
//};
//typedef struct //属性封装
//{
//    char name[Size_char/2];
//    char sex[Size_char/4];
//    int age;
//    long long tel;
//    char addr[Size_char];
//}USER;
//
//typedef struct USER//结构体：将成员信息封装
//{
//    PeoInfo* data;  //柔性指针
//    int count;  //当前个数
//    int capacity;//最大容量
//}USER, * puser;
//void menu()
//{
//    printf("###############################\n");
//    printf("#########1 添加联系人 #########\n");
//    printf("#########2 删除联系人 #########\n");
//    printf("#########3 查找联系人 #########\n");
//    printf("#########4 显示所有人 #########\n");
//    printf("#########5 按名字排序 #########\n");
//    printf("#########0 退出电话簿 #########\n");
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
//    printf("请输入想要查找的联系人姓名# ");
//    scanf("%s",name);
//    for (int i = 0; i < Num; i++) {
//        if (per[i].name == name) { 
//            printf("联系人姓名：%s\n", per[i].name);
//            printf("      性别：%s\n", per[i].sex);
//            printf("      年龄：%d\n", per[i].age);
//            printf("      电话：%ld\n", per[i].tel);
//            printf("      住址：%s\n", per[i].addr);
//            return 0;
//        }   
//    }
//    printf("联系人不存在！\n");
//}
//void PrintAll(USER per[]) 
//{
//    printf("    姓名      性别       年龄      电话         住址       \n");
//    for (int i = 0; i < Num && per[i].name != '\0'; i++) {
//        printf("%s %4s %3d %11ld %12s\n",per[i].name,per[i].sex,\
//            per[i].age,per[i].tel,per[i].addr);
//    }
//}
//void SortName() {}
//int main()
//{
//    USER per[Num] = {'\0','\0',0,0,'\0'}; //创建结构体数组
//    int exit = 1;//退出标志，为0退出
//    while (exit) {
//        menu();
//        int choice = 0;
//        printf("请输入宁的目的# ");
//        scanf("%d",&choice);
//        system("cls");
//        switch (choice) {
//            case Add:AddPerson(); break;
//            case Del:DelPerson(); break;
//            case Seek:SeekPerson(per); break;
//            case Print:PrintAll(per); break;
//            case Sort:SortName(); break;
//            case EXT:exit = 0; break;
//            default:printf("输入错误！请重新输入# "); break;
//        }
//    }
//    return 0;
//}