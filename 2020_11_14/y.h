#ifndef __Y_H__
#define __Y_H__

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#pragma warning(disable:4996)
#define nums 8  //��·�鲢�㷨��Ҫ���������Ԫ����Ŀ
//2020_11_12
int isPrimeNum(int x);
void BubbleSort(int x[], int num);
void SelectSort(int x[], int num);
void QKSort(int x[], int L, int H);
void InsertSort(int x[], int num);
void BiInsertSort(int x[], int num);
void ShellSort(int x[], int x_num);
void MergeSort(int x[], int L, int R);
long int Factorials(int n);
int FactorialsSum(int num);  //���Ż�
int SeekMaxFactor2(int _a, int _b);  //��շת���������շת���������ʵ��
void PrintLeapyear(int _Min, int _Max);
int Count9(int _Min, int _Max);
int BiSearch(int x[], int target, int _num);
int IsLeapyear(int year);
int MyStrlen(const char* s);
int FibNum(int n);
void reverse_string(char* string);
int IsNarcissisticNum(int n);
void PrintRhombus(int n);
//2020_11_13
char* MyStrcpy(char* arr, const char* p);
void SwapNumBit(int* arr, int num);
void Hanoi(int n, char a, char b, char c);
int WayOfFrogJumpsStairs(int n);
void PrintLilyNum(int n);


#endif
