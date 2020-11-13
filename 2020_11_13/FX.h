#ifndef __FX_H__
#define __FX_H__

#include <stdio.h>
#include <math.h>
#include <string.h>
#pragma warning(disable:4996)
#define nums 8  //��·�鲢�㷨��Ҫ���������Ԫ����Ŀ

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
int Strlen(const char *s);
int FibNum(int n);
void reverse_string(char* string);
//int RemoveElement(int nums[], int numSize, int val);
int IsNarcissisticNum(int n);
void PrintRhombus(int n);

#endif