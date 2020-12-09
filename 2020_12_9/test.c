#include <stdio.h>
#include <assert.h>
#include <string.h>
#pragma warning(disable:4996)
char *MyStrncat(char *des,const char * src,size_t num)
{
	assert(des);
	assert(src);//输入合法性校验
	char* tmp = des;
	while (*des) {
		des++;
	}
	while (num-- && (*des++ = *src++)) { //未串接完&&串接（隐含校验src未走到\0）
		;
	}
	*des = '\0';//最后一位填\0
	return tmp;
}

char* MyStrncpy(char* des, const char* src, size_t num)
{
	assert(des);
	assert(src);//输入合法性校验
	char* tmp = des;
	while (num-- && (*des++ = *src++)) { //覆盖（隐含校验src未走到\0）&&未串接完
		;
	}
	*des = '\0';//最后一位填\0
	return tmp;
}
void SeekSingleBNum(int arr[], int n) 
{
	int res = 0;
	for (int i = 0; i < n; i++) {
		res ^= arr[i];
	}// res = 单身狗1 ^ 单身狗2
	int pos = 0;
	for (int i = 0; i < 32; i++) {//寻找res的最低位的1
		if (((res >> i) & 1 )== 1) {
			pos = i;
			break;
		}
	}
	int num1 = 0, num2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)//按1的位置对数组分组，分两组使两个不同数分开
			num1 ^= arr[i];        //再次按位与找到单数
	}
	num2 = res ^ num1;
	printf("%d %d \n", num1, num2);
}

int main() 
{
	int arr[] = { 1,2,3,6,5,3,2,1,5,7,7,9 };
	SeekSingleBNum(arr, sizeof(arr) / sizeof(arr[0]));
	//char str1[20];
	//char str2[20];
	//strcpy(str1,"To be ");
	//strcpy(str2, "or not to be");
	//MyStrncpy(str1, str2, 2);
	//printf("%s\n",str1);
	return 0;
}






























