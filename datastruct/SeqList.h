//#pragma once
//#include "Sysutil.h"
//
//#define ElemType int     //顺序表元素类型
//#define ELEMENT_DEFAULT_SIZE 2   //顺序表元素数目
//
//typedef struct SeqList
//{
//	ElemType* base;
//	size_t capacity;//容量
//	size_t  size;//当前元素数目
//}SeqList;
//
//
//void SeqListMenu();
//void SeqListInit(SeqList *sq);
//void SeqListTailPop(SeqList* sq);
//void SeqListHeadPop(SeqList* sq);
//void SeqListHeadInsert(SeqList* sq, ElemType x);
//void SeqListTailInsert(SeqList* sq, ElemType x);
//void LengthofList(SeqList* sq);
//void CapacityofList(SeqList* sq);
//void SeqListClear(SeqList* sq);
//void SeqListDestroy(SeqList* sq);
//void SeqListSort(SeqList* sq);
//void SeqListShow(SeqList* sq);
//int SeqListBiSeekValue(SeqList* sq, ElemType x);
//int SeqListSeekValue(SeqList* sq, ElemType x);
//void SeqListCheekPos(SeqList* sq, int pos);
//void SeqListDelPos(SeqList* sq, int pos);
//void SeqListDelValue(SeqList* sq, ElemType x);
//void SeqListDelAllSame(SeqList* sq, ElemType x);
//void SeqListReverse(SeqList* sq);
//void SeqListInsertPos(SeqList* sq, int pos, ElemType x);
//void SeqListInsertValue(SeqList* sq, ElemType x);
//static void SeqListAddCapacity(SeqList* sq);
//static bool IsFull(SeqList* sq);
//static bool IsEmpty(SeqList* sq);
//
/////////////////////////////////////////////////////////
//void SeqListMenu()
//{
//	printf("*******************顺序表******************\n");
//	printf("*****   [1]显示长度     [2]显示容量   *****\n");
//	printf("*****   [3]头部插入     [4]尾部插入   *****\n");
//	printf("*****   [5]按位置插     [6]按值插入   *****\n");//6:插到第一个比自己大的数据之前，紧邻
//	printf("*****   [7]打印所有     [8]头部删除   *****\n");
//	printf("*****   [9]尾部删除     [10]按值删除  *****\n");//10:删除第一次出现的目标值
//	printf("*****   [11]按位置删    [12]按位置查  *****\n");
//	printf("*****   [13]按值查找    [14]增序排序  *****\n");//13:寻找第一次出现的目标值的索引
//	printf("*****   [15]元素翻转    [16]同值删除  *****\n");//16:删除所有相同的目标值
//	printf("*****   [17]清除内容    [18]放弃所有  *****\n");//17:清空SeqList  18:放弃SeqList结构
//	printf("*****   [19]二分查找    [0]退出       *****\n");
//	printf("*******************************************\n");	
//}
//
//static bool IsFull(SeqList* sq)
//{
//	assert(sq);
//	return sq->size >= sq->capacity; //满：true   不满：false
//}
//
//static bool IsEmpty(SeqList* sq)
//{
//	assert(sq);
//	return sq->size == 0;//空：true   非空：false
//}
//
//void SeqListInit(SeqList *sq)
//{
//	assert(sq);
//	sq->base = (ElemType*)malloc(sizeof(ElemType) * ELEMENT_DEFAULT_SIZE);//申请空间
//	assert(sq->base != NULL);
//	memset(sq->base, 0, sizeof(ElemType) * ELEMENT_DEFAULT_SIZE);//空间初始化
//	sq->capacity = ELEMENT_DEFAULT_SIZE; //容量初始化
//	sq->size = 0;				//数据数目初始化
//}
//
//void SeqListTailInsert(SeqList* sq, ElemType x)
//{
//	assert(sq);
//	if (IsFull(sq)) { //满则扩容
//		SeqListAddCapacity(sq);
//	}
//	if (!IsFull(sq)) {//扩容成功追加数据
//		sq->base[sq->size++] = x;
//	}
//	else {
//		printf("不可再添加数据!\n");
//	}
//
//}
//
//void SeqListHeadInsert(SeqList* sq,ElemType x)
//{
//	assert(sq);
//	if (IsFull(sq)) { //满则扩容
//		SeqListAddCapacity(sq);
//	}
//	if (!IsFull(sq)) {
//		int num = sq->size;  
//		while (num) {//数据后移
//			sq->base[num] = sq->base[num - 1];
//			num--;
//		}
//		sq->base[0] = x;//头插
//		sq->size++;//数目自增
//	}
//	else {
//		printf("不可再添加数据!\n");
//	}
//}
//
//void SeqListTailPop(SeqList* sq)
//{
//	assert(sq);
//	if (IsEmpty(sq)) {
//		printf("无数据不可删除!\n");
//		return;
//	}
//	sq->size--;//尾删
//}
//
//void SeqListHeadPop(SeqList* sq)
//{
//	assert(sq);
//	if (IsEmpty(sq)) {
//		printf("无数据不可删除!\n");
//		return;
//	}
//	for (int i = 0; i < sq->size - 1; i++){//数据前移
//		sq->base[i] = sq->base[i + 1];
//	}
//	sq->size--;//数目自减
//}
//
//void LengthofList(SeqList* sq) 
//{
//	printf("该表长度为%d\n", sq->size);
//}
//
//void CapacityofList(SeqList* sq) 
//{
//	printf("该表容量为%d\n", sq->capacity);
//}
//
//void SeqListClear(SeqList* sq) 
//{
//	sq->size = 0;
//}
//
//void SeqListDestroy(SeqList* sq) 
//{
//	assert(sq);
//	free(sq);//释放空间
//	sq->base = NULL;//防止野指针
//	sq->size = 0;//重置
//	sq->capacity = 0;
//}
//
//void SeqListShow(SeqList* sq)
//{
//	assert(sq);
//	printf("目前SeqList成员如下:\n");
//	for (int i = 0; i < sq->size; i++) {
//		printf("%d ",sq->base[i]);
//	}
//	printf("\n");
//}
//
//void SeqListSort(SeqList* sq)
//{//冒泡排序：增序
//	assert(sq);
//	int flag = 1;
//	for (int i = 0; i < sq->size-1&&flag; i++) {
//		flag = 0;
//		for (int j = 0; j < sq->size - 1; j++) {
//			ElemType tmp;
//			if (sq->base[j] > sq->base[j + 1]) {
//				tmp = sq->base[j + 1];
//				sq->base[j + 1] = sq->base[j];
//				sq->base[j] = tmp;
//				flag = 1;
//			}
//		}
//	}
//}
//
//int SeqListBiSeekValue(SeqList* sq, ElemType x)
//{//二分查找，要求数据有序
//	assert(sq);
//	SeqListSort(sq);//保证数据有序
//	int left = 0;
//	int right = sq->size;
//	while (left <= right) {
//		int mid = (right + left) / 2;
//		if (sq->base[mid] > x) {
//			right = mid - 1;
//		}
//		else if (sq->base[mid] < x) {
//			left = mid + 1;
//		}
//		else {
//			return mid;
//		}
//	}
//	return -1;
//}
//
//int SeqListSeekValue(SeqList* sq, ElemType x)
//{//按值查找
//	assert(sq);
//	for (int i = 0; i < sq->size; i++) {
//		if (x == sq->base[i]) {
//			return i;
//		}
//	}
//	return -1;
//}
//
//void SeqListCheekPos(SeqList* sq, int pos)
//{//按位置查数据
//	assert(sq);
//	if (0 <= pos && pos < sq->size) {
//		printf("索引[%d]处的元素为[%d]\n", pos, sq->base[pos]);
//	}
//	else {
//		printf("输入的索引不存在!");
//		return;
//	}
//}
//
//void SeqListDelPos(SeqList* sq, int pos)
//{
//	assert(sq);
//	if (0 <= pos && pos < sq->size) {//索引有效
//		if (pos == sq->size - 1) {//尾删
//			sq->size--;
//		}
//		else if (0 == pos) {//头删
//			SeqListHeadPop(sq);
//		}
//		else {
//			for (int i = pos; i < sq->size - 1; i++) {//从pos位置开始数据前移
//				sq->base[i] = sq->base[i + 1];
//			}
//			sq->size--;//数目自减
//		}
//	}
//	else{
//		printf("输入的索引不存在!");
//		return;
//	}	
//}
//
//void SeqListDelValue(SeqList* sq, ElemType x) {
//	assert(sq);
//	int pos = SeqListSeekValue(sq, x);//寻找第一次出现的位置
//	if (-1 != pos) {//存在则删除
//		SeqListDelPos(sq, pos);
//	}
//	else {
//		printf("输入的[%d]SeqList中不存在!\n",x);
//	}	
//}

//void SeqListDelAllSame(SeqList* sq, ElemType x) {
//	assert(sq);
//	int cnt = 0;
//	for (int i = 0; i < sq->size; i++) {//计算重复出现次数
//		if (x == sq->base[i]) {
//			cnt++;
//		}
//	}
//	while (cnt--) {
//		int pos = SeqListSeekValue(sq, x);//查位置
//		SeqListDelPos(sq, pos);//按位置删
//	}
//}
//
//void SeqListReverse(SeqList* sq)
//{
//	assert(sq);
//	for (int i = 0; i < sq->size / 2; i++) {//对称翻转
//		ElemType tmp;
//		tmp = sq->base[i];
//		sq->base[i] = sq->base[sq->size - 1 - i]; 
//		sq->base[sq->size - 1 - i] = tmp;
//	}
//}
//
//void SeqListInsertPos(SeqList* sq, int pos,ElemType x)
//{
//	assert(sq);
//	if (IsFull(sq)) {//满则扩容
//		SeqListAddCapacity(sq);
//	}
//	if (pos < 0 || pos > sq->size) {//保证插入位置有效
//		printf("插入位置非法!\n");
//		return;
//	}
//	if (!IsFull(sq)) {//扩容成功
//		for (int i = sq->size; i > pos; i--) {
//			sq->base[i] = sq->base[i - 1];
//		}
//		sq->base[pos] = x;
//		sq->size++;
//		printf("插入成功!\n");
//	}
//}
//
//void SeqListInsertValue(SeqList* sq, ElemType x)
//{
//	assert(sq);
//	if (IsFull(sq)) {//满则扩容
//		SeqListAddCapacity(sq);
//	}
//	if (IsFull(sq)) {
//		printf("已满不能插入!\n");
//		return;
//	}
//	int i = 0;
//	for (; i < sq->size; i++) { //寻找合适的插入位置
//		if (sq->base[i] >= x) {
//			break;
//		}
//	}
//	if (0 == i) {//头插
//		SeqListHeadInsert(sq,x);
//	}
//	else if(sq->size == i) {//尾插
//		SeqListTailInsert(sq,x);
//	}
//	else {//按位置插
//		SeqListInsertPos(sq, i, x);
//	}
//}
//
//static void SeqListAddCapacity(SeqList* sq)
//{
//	assert(sq);
//	ElemType* p = (ElemType*)realloc(sq->base, 2 * (sq->capacity) * sizeof(ElemType));//2倍扩容
//	if (NULL != p) {
//		sq->base = p;
//		sq->capacity = 2 * sq->capacity;//容量更新
//		p = NULL;
//		printf("扩容成功!\n");
//	}
//	else {
//		printf("扩容失败!\n");
//	}
//	return sq;
//}