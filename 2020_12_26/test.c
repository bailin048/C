#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define SWAPBIT(x) ((x & 0xAAAAAAAA) >> 1) |  ((x & 0x55555555) << 1)      //留奇数位再左移一位|留偶数位再右移一位
#define OFFSETOF(Type, Member) (size_t)&(((Type *)0)->Member)
//将地址0强转为目标结构体的起始地址:即假设该目标结构体的起始地址为0，那么member的偏移地址就是member的地址
//eg.A与B比身高(B比A高，B身高已知)
//   由于不知道A身高，所以我们不知道B比A高多少
//   一旦我们假设了A的身高，B比A高多少立马就可以知道
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





























