#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define SWAPBIT(x) ((x & 0xAAAAAAAA) >> 1) |  ((x & 0x55555555) << 1)      //������λ������һλ|��ż��λ������һλ
#define OFFSETOF(Type, Member) (size_t)&(((Type *)0)->Member)
//����ַ0ǿתΪĿ��ṹ�����ʼ��ַ:�������Ŀ��ṹ�����ʼ��ַΪ0����ômember��ƫ�Ƶ�ַ����member�ĵ�ַ
//eg.A��B�����(B��A�ߣ�B�����֪)
//   ���ڲ�֪��A��ߣ��������ǲ�֪��B��A�߶���
//   һ�����Ǽ�����A����ߣ�B��A�߶�������Ϳ���֪��
struct ST {
	int ID;
	char sex;
	float weight;
}st1;
int main() 
{
	printf("%d\n", OFFSETOF(struct ST, sex));
	//int a = 11;
	//printf("%d\n", SWAPBIT(a));
	return 0;
}





























