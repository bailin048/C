//#pragma once
//#include "Sysutil.h"
//
//#define ElemType int     //˳���Ԫ������
//#define ELEMENT_DEFAULT_SIZE 2   //˳���Ԫ����Ŀ
//
//typedef struct SeqList
//{
//	ElemType* base;
//	size_t capacity;//����
//	size_t  size;//��ǰԪ����Ŀ
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
//	printf("*******************˳���******************\n");
//	printf("*****   [1]��ʾ����     [2]��ʾ����   *****\n");
//	printf("*****   [3]ͷ������     [4]β������   *****\n");
//	printf("*****   [5]��λ�ò�     [6]��ֵ����   *****\n");//6:�嵽��һ�����Լ��������֮ǰ������
//	printf("*****   [7]��ӡ����     [8]ͷ��ɾ��   *****\n");
//	printf("*****   [9]β��ɾ��     [10]��ֵɾ��  *****\n");//10:ɾ����һ�γ��ֵ�Ŀ��ֵ
//	printf("*****   [11]��λ��ɾ    [12]��λ�ò�  *****\n");
//	printf("*****   [13]��ֵ����    [14]��������  *****\n");//13:Ѱ�ҵ�һ�γ��ֵ�Ŀ��ֵ������
//	printf("*****   [15]Ԫ�ط�ת    [16]ֵͬɾ��  *****\n");//16:ɾ��������ͬ��Ŀ��ֵ
//	printf("*****   [17]�������    [18]��������  *****\n");//17:���SeqList  18:����SeqList�ṹ
//	printf("*****   [19]���ֲ���    [0]�˳�       *****\n");
//	printf("*******************************************\n");	
//}
//
//static bool IsFull(SeqList* sq)
//{
//	assert(sq);
//	return sq->size >= sq->capacity; //����true   ������false
//}
//
//static bool IsEmpty(SeqList* sq)
//{
//	assert(sq);
//	return sq->size == 0;//�գ�true   �ǿգ�false
//}
//
//void SeqListInit(SeqList *sq)
//{
//	assert(sq);
//	sq->base = (ElemType*)malloc(sizeof(ElemType) * ELEMENT_DEFAULT_SIZE);//����ռ�
//	assert(sq->base != NULL);
//	memset(sq->base, 0, sizeof(ElemType) * ELEMENT_DEFAULT_SIZE);//�ռ��ʼ��
//	sq->capacity = ELEMENT_DEFAULT_SIZE; //������ʼ��
//	sq->size = 0;				//������Ŀ��ʼ��
//}
//
//void SeqListTailInsert(SeqList* sq, ElemType x)
//{
//	assert(sq);
//	if (IsFull(sq)) { //��������
//		SeqListAddCapacity(sq);
//	}
//	if (!IsFull(sq)) {//���ݳɹ�׷������
//		sq->base[sq->size++] = x;
//	}
//	else {
//		printf("�������������!\n");
//	}
//
//}
//
//void SeqListHeadInsert(SeqList* sq,ElemType x)
//{
//	assert(sq);
//	if (IsFull(sq)) { //��������
//		SeqListAddCapacity(sq);
//	}
//	if (!IsFull(sq)) {
//		int num = sq->size;  
//		while (num) {//���ݺ���
//			sq->base[num] = sq->base[num - 1];
//			num--;
//		}
//		sq->base[0] = x;//ͷ��
//		sq->size++;//��Ŀ����
//	}
//	else {
//		printf("�������������!\n");
//	}
//}
//
//void SeqListTailPop(SeqList* sq)
//{
//	assert(sq);
//	if (IsEmpty(sq)) {
//		printf("�����ݲ���ɾ��!\n");
//		return;
//	}
//	sq->size--;//βɾ
//}
//
//void SeqListHeadPop(SeqList* sq)
//{
//	assert(sq);
//	if (IsEmpty(sq)) {
//		printf("�����ݲ���ɾ��!\n");
//		return;
//	}
//	for (int i = 0; i < sq->size - 1; i++){//����ǰ��
//		sq->base[i] = sq->base[i + 1];
//	}
//	sq->size--;//��Ŀ�Լ�
//}
//
//void LengthofList(SeqList* sq) 
//{
//	printf("�ñ���Ϊ%d\n", sq->size);
//}
//
//void CapacityofList(SeqList* sq) 
//{
//	printf("�ñ�����Ϊ%d\n", sq->capacity);
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
//	free(sq);//�ͷſռ�
//	sq->base = NULL;//��ֹҰָ��
//	sq->size = 0;//����
//	sq->capacity = 0;
//}
//
//void SeqListShow(SeqList* sq)
//{
//	assert(sq);
//	printf("ĿǰSeqList��Ա����:\n");
//	for (int i = 0; i < sq->size; i++) {
//		printf("%d ",sq->base[i]);
//	}
//	printf("\n");
//}
//
//void SeqListSort(SeqList* sq)
//{//ð����������
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
//{//���ֲ��ң�Ҫ����������
//	assert(sq);
//	SeqListSort(sq);//��֤��������
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
//{//��ֵ����
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
//{//��λ�ò�����
//	assert(sq);
//	if (0 <= pos && pos < sq->size) {
//		printf("����[%d]����Ԫ��Ϊ[%d]\n", pos, sq->base[pos]);
//	}
//	else {
//		printf("���������������!");
//		return;
//	}
//}
//
//void SeqListDelPos(SeqList* sq, int pos)
//{
//	assert(sq);
//	if (0 <= pos && pos < sq->size) {//������Ч
//		if (pos == sq->size - 1) {//βɾ
//			sq->size--;
//		}
//		else if (0 == pos) {//ͷɾ
//			SeqListHeadPop(sq);
//		}
//		else {
//			for (int i = pos; i < sq->size - 1; i++) {//��posλ�ÿ�ʼ����ǰ��
//				sq->base[i] = sq->base[i + 1];
//			}
//			sq->size--;//��Ŀ�Լ�
//		}
//	}
//	else{
//		printf("���������������!");
//		return;
//	}	
//}
//
//void SeqListDelValue(SeqList* sq, ElemType x) {
//	assert(sq);
//	int pos = SeqListSeekValue(sq, x);//Ѱ�ҵ�һ�γ��ֵ�λ��
//	if (-1 != pos) {//������ɾ��
//		SeqListDelPos(sq, pos);
//	}
//	else {
//		printf("�����[%d]SeqList�в�����!\n",x);
//	}	
//}

//void SeqListDelAllSame(SeqList* sq, ElemType x) {
//	assert(sq);
//	int cnt = 0;
//	for (int i = 0; i < sq->size; i++) {//�����ظ����ִ���
//		if (x == sq->base[i]) {
//			cnt++;
//		}
//	}
//	while (cnt--) {
//		int pos = SeqListSeekValue(sq, x);//��λ��
//		SeqListDelPos(sq, pos);//��λ��ɾ
//	}
//}
//
//void SeqListReverse(SeqList* sq)
//{
//	assert(sq);
//	for (int i = 0; i < sq->size / 2; i++) {//�ԳƷ�ת
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
//	if (IsFull(sq)) {//��������
//		SeqListAddCapacity(sq);
//	}
//	if (pos < 0 || pos > sq->size) {//��֤����λ����Ч
//		printf("����λ�÷Ƿ�!\n");
//		return;
//	}
//	if (!IsFull(sq)) {//���ݳɹ�
//		for (int i = sq->size; i > pos; i--) {
//			sq->base[i] = sq->base[i - 1];
//		}
//		sq->base[pos] = x;
//		sq->size++;
//		printf("����ɹ�!\n");
//	}
//}
//
//void SeqListInsertValue(SeqList* sq, ElemType x)
//{
//	assert(sq);
//	if (IsFull(sq)) {//��������
//		SeqListAddCapacity(sq);
//	}
//	if (IsFull(sq)) {
//		printf("�������ܲ���!\n");
//		return;
//	}
//	int i = 0;
//	for (; i < sq->size; i++) { //Ѱ�Һ��ʵĲ���λ��
//		if (sq->base[i] >= x) {
//			break;
//		}
//	}
//	if (0 == i) {//ͷ��
//		SeqListHeadInsert(sq,x);
//	}
//	else if(sq->size == i) {//β��
//		SeqListTailInsert(sq,x);
//	}
//	else {//��λ�ò�
//		SeqListInsertPos(sq, i, x);
//	}
//}
//
//static void SeqListAddCapacity(SeqList* sq)
//{
//	assert(sq);
//	ElemType* p = (ElemType*)realloc(sq->base, 2 * (sq->capacity) * sizeof(ElemType));//2������
//	if (NULL != p) {
//		sq->base = p;
//		sq->capacity = 2 * sq->capacity;//��������
//		p = NULL;
//		printf("���ݳɹ�!\n");
//	}
//	else {
//		printf("����ʧ��!\n");
//	}
//	return sq;
//}