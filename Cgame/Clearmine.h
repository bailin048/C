#ifndef __CLEARMINE_H__
#define __CLEARMINE_H__

#include <stdio.h>
#include <time.h>
#include <windows.h>
#pragma warning(disable:4996)
#define Size 10       //宏定义展示给人的面板的大小
#define DeathNum 35   //宏定义雷的数目

void ClearMine();
void SetMine(char arr[][Size + 2]);
void table(char arr[][Size + 2]);
void CountD(char arr[][Size + 2], char arr1[][Size + 2], int x, int y);

#endif
