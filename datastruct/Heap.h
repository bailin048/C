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
	int i = (j - 1) / 2;//计算j的父节点
	HeapElemType temp = php->heap[j];
	while (j > 0) {//非根节点
		if (temp < php->heap[0]) {//小堆调整
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
		printf("堆已满，无法插入!\n");
		return;
	}
	php->heap[php->size] = x;//插入堆尾
	_AdjustUp(php,php->size);//向上调整算法
	php->size++;//数量自增
}
static void _AdjustDown(Heap* php, int start)
{
	int j = start;
	int i = 2 * j + 1;
	HeapElemType temp = php->heap[j];
	while (i < php->size) {
		if (i + 1 < php->size && php->heap[i] > php->heap[i + 1]) //左孩子比右孩子大
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
		printf("空堆!\n");
		return;
	}
	return php->heap[0];
}
void HeapRemove(Heap* php)
{
	if(IsEmpty(php)){
		printf("空堆，无法完成删除!\n");
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
	int curpos = n / 2 - 1; //找到二叉树的最后一个分支
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
{//堆排序（升序or降序取决于传进哪种堆，小根堆则降序，大根堆则升序）
	int n = php->size;//备份堆的数据数目
	int k = php->size;//动态数目调整
	while (k--) {
		HeapElemType tmp = HeapTop(php);
		php->heap[0] = php->heap[k];
		php->heap[k] = tmp;
		php->size--;//隐去最后一个数据，避免被调整
		_AdjustDown(php, 0);
	}
	php->size = n;//恢复数目
}
void HeapTopK(HeapElemType* a, int n, int k)
{//输出最大的K个数(因为建立的小根堆) 
	Heap h;
	HeapInit(&h,k);
	for (int i = 0; i < k; i++)//先用k个数建堆
		HeapInsert(&h,a[i]);
	if (n > k) {//剩下的数入堆
		for (int i = k; i < n; i++) {
			if (a[i] > (&h)->heap[0]) {//大于最小的数，入堆
				(&h)->heap[0] = a[i];
				_AdjustDown(&h, 0);//将最小的要调整到堆顶
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
	//随机生成10000个数存入数组，保证元素都小于1000000
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	//确定10个最大的数
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
