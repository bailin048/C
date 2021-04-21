#ifndef __HEADP_H__
#define __HEADP_H__

#include "Sysutil.h"
#include <time.h>
#define HeapElemType int

typedef struct Heap
{
	HeapElemType* heap;
	int capacity;
	int size;
}Heap;

void HeapInit(Heap* php, int sz);
void HeapInsert(Heap* php, HeapElemType x);
static void _AdjustDown(Heap* php, int start);
static void _AdjustUp(Heap* php, int start);
void HeapInsert(Heap* php, HeapElemType x);
void HeapShow(Heap* php);
void HeapClear(Heap* php);
void HeapDestory(Heap* php);
HeapElemType HeapTop(Heap* php);
void HeapRemove(Heap* php);
void HeapInitByArray(Heap* php, int* A, int n);
int HeapSize(Heap* php);
void HeapSort(Heap* php);
void HeapTopK(HeapElemType* a, int n, int k);
void TestTopK();


int IsEmpty(Heap* php)
{
	return php->size == 0;
}
int IsFull(Heap* php)
{
	return php->capacity <= php->size;
}
static void _AdjustUp(Heap* php, int start)
{
	int j = start;
	int i = (j - 1) / 2;//����j�ĸ��ڵ�
	HeapElemType temp = php->heap[j];
	while (j > 0) {//�Ǹ��ڵ�
		if (temp < php->heap[0]) {//С�ѵ���
			php->heap[i] = php->heap[j];
			j = i;
			i = (j - 1) / 2;
		}
		else
			break;
	}
	php->heap[j] = temp;
}
void HeapInit(Heap* php, int sz)
{
	assert(php);
	HeapElemType* p = (HeapElemType*)malloc(sizeof(HeapElemType) * sz);
	assert(p);
	php->heap = p;
	php->capacity = sz;
	php->size = 0;
}
void HeapInsert(Heap* php, HeapElemType x)
{
	if (IsFull(php)) {
		printf("���������޷�����!\n");
		return;
	}
	php->heap[php->size] = x;//�����β
	_AdjustUp(php,php->size);//���ϵ����㷨
	php->size++;//��������
}
static void _AdjustDown(Heap* php, int start)
{
	int j = start;
	int i = 2 * j + 1;
	HeapElemType temp = php->heap[j];
	while (i < php->size) {
		if (i + 1 < php->size && php->heap[i] > php->heap[i + 1]) //���ӱ��Һ��Ӵ�
			i += 1;
		if (temp > php->heap[i]) {
			php->heap[j] = php->heap[i];
			j = i;
			i = 2 * j + 1;
		}
		else
			break;
	}
	php->heap[j] = temp;
}
void HeapShow(Heap* php)
{
	for (int i = 0; i < php->size; i++) 
		printf("%d ",php->heap[i]);
	printf("\n");
}
void HeapClear(Heap* php)
{
	php->size = 0;
}
void HeapDestory(Heap* php)
{
	free(php->heap);
	php->heap = NULL;
	php->size = 0;
	php->capacity = 0;
}
HeapElemType HeapTop(Heap* php)
{
	if (IsEmpty(php)) {
		printf("�ն�!\n");
		return;
	}
	return php->heap[0];
}
void HeapRemove(Heap* php)
{
	if(IsEmpty(php)){
		printf("�նѣ��޷����ɾ��!\n");
		return;
	}
	php->size--;
	php->heap[0] = php->heap[php->size];
	_AdjustDown(php, 0);
}
void HeapInitByArray(Heap* php, int* A, int n)
{
	php->heap = (HeapElemType*)malloc(sizeof(HeapElemType) * n);
	assert(php->heap != NULL);
	php->capacity = n;
	php->size = n;
	for (int i = 0; i < n; ++i)
		php->heap[i] = A[i];
	int curpos = n / 2 - 1; //�ҵ������������һ����֧
	while (curpos >= 0)
	{
		_AdjustDown(php, curpos);
		curpos--;
	}
}
int HeapSize(Heap* php)
{
	return php->size;
}
void HeapSort(Heap* php)
{//����������or����ȡ���ڴ������ֶѣ�С�������򣬴����������
	int n = php->size;//���ݶѵ�������Ŀ
	int k = php->size;//��̬��Ŀ����
	while (k--) {
		HeapElemType tmp = HeapTop(php);
		php->heap[0] = php->heap[k];
		php->heap[k] = tmp;
		php->size--;//��ȥ���һ�����ݣ����ⱻ����
		_AdjustDown(php, 0);
	}
	php->size = n;//�ָ���Ŀ
}
void HeapTopK(HeapElemType* a, int n, int k)
{//�������K����(��Ϊ������С����) 
	Heap h;
	HeapInit(&h,k);
	for (int i = 0; i < k; i++)//����k��������
		HeapInsert(&h,a[i]);
	if (n > k) {//ʣ�µ������
		for (int i = k; i < n; i++) {
			if (a[i] > (&h)->heap[0]) {//������С���������
				(&h)->heap[0] = a[i];
				_AdjustDown(&h, 0);//����С��Ҫ�������Ѷ�
			}
		}
	}
	HeapShow(&h);
}
void TestTopK()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	//�������10000�����������飬��֤Ԫ�ض�С��1000000
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	//ȷ��10��������
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;

	HeapTopK(a, n, 10);
}
#endif
