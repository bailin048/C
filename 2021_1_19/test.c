#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#pragma warning(disable:4996)
//回文数判断
int LenofNum(int x)
{
    int cnt = 1;
    while (x /= 10) {
        cnt++;
    }
    return cnt;
}
int isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) { //负数及个位为0的非0数必不是回文数
        return 0;
    }
    int k = LenofNum(x);
    for (int i = 0; i < k / 2; i++) {//计算一半就行
        int h = x / (int)pow(10, k - i - 1) % 10;  //获取高位数字
        int l = x / (int)pow(10, i) % 10;//获取低位数字
            if (h != l) {
                return 0;
            }
    }
    return 1;
}
//赎金信
bool canConstruct(char* ransomNote, char* magazine) {
    int num1[26] = { 0 };
    int num2[26] = { 0 };
    int k1 = strlen(ransomNote);
    int k2 = strlen(magazine);
    for (int i = 0; i < k1; i++) {
        num1[ransomNote[i] - 'a']++;
    }
    for (int i = 0; i < k2; i++) {
        num2[magazine[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (num1[i] > num2[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    char* ransomNote = "saw";
    char* magazine = "dasjdgalkf";
    printf("%d\n", canConstruct(ransomNote, magazine));
    printf("%d",sizeof(float));
	return 0;
}