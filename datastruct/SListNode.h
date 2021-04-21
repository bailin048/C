//#pragma once
//#include "Sysutil.h"

//#define ElemType int
//
//
///////////////��ͷ������///////////////////////////
//typedef struct SListNode
//{
//	ElemType data;//������
//	struct SListNode* next;//ָ����
//}SListNode;
//
//typedef struct SList
//{
//	SListNode* head;
//}SList;
//void SListMenu();
///////////��ͷ��������������////////////////////
//void SListInit(SList* plist);
//static SListNode* BuyNode();
//void SListPushBack(SList* plist, ElemType x);
//void SListShow(SList* plist);
//void SListPushFront(SList* plist, ElemType x);
//int SListLength(SList* plist);
//void SListPopBack(SList* plist);
//void SListPopFront(SList* plist);
//SListNode* SListFind(SList* plist, ElemType key);
//void SListClear(SList* plist);
//void SListDeleteByVal(SList* plist, ElemType x);
//void SListPushByVal(SList* plist, ElemType key);
//void SListReverse(SList* plist);
//void SListPopAllSame(SList* plist, ElemType key);
//void SListPushPos(SList* plist, int pos, ElemType x);
//void SListPopPos(SList* plist, int pos);
//void SListDestroy(SList* plist);
//void SListSort(SList* plist);
//
//////////////////////////////////////
//void SListMenu()
//{
//	printf("*****************��ͷ������****************\n");
//	printf("*****   [1]��ʾ����     [2]ͷ������   *****\n");
//	printf("*****   [3]β������     [4]��ֵ����   *****\n");
//	printf("*****   [5]��ӡ����     [6]ͷ��ɾ��   *****\n");
//	printf("*****   [7]β��ɾ��     [8]��ֵɾ��   *****\n");
//	printf("*****   [9]��ֵ����     [10]��������  *****\n");
//	printf("*****   [11]Ԫ�ط�ת    [12]ֵͬɾ��  *****\n");
//	printf("*****   [13]��λ����    [14]��λɾ��  *****\n");
//	printf("*****   [15]�������    [0]�˳�       *****\n");
//	printf("*******************************************\n");
//}
//void SListInit(SList* plist)
//{//��ʼ��:��ͷ������
//	plist->head = NULL;
//}
//static SListNode* BuyNode() 
//{
//	SListNode* p = (SListNode*)malloc(sizeof(SListNode));//����ڵ�
//	assert(p != NULL);
//	p->data = 0;//�ڵ��ʼ��
//	p->next = NULL;
//	return p;
//}
//void SListPushBack(SList* plist, ElemType x)
//{
//	assert(plist);//�Ϸ����
//	SListNode* p = plist->head;
//	SListNode* s = BuyNode(); //�����½ڵ㣬�洢����
//	s->data = x;
//	if (NULL == p) {//�ձ�����
//		plist->head = s;
//	}
//	else {//�ǿգ�β��
//		while (NULL != p->next) {//�ҵ���β
//			p = p->next;
//		}
//		p->next = s;//����
//	}
//}
//void SListShow(SList* plist)
//{
//	assert(plist);
//	SListNode* p = plist->head;//�̳�head
//	while (NULL != p) {//��ӡ
//		printf("%d-->",p->data);
//		p = p->next;
//	}
//	printf("end\n");//����ָʾ
//}
//void SListPushFront(SList* plist, ElemType x)
//{
//	assert(plist);//�Ϸ����
//	SListNode* s = BuyNode(); //�����½ڵ㣬�洢����
//	s->data = x;
//	s->next = plist->head;//�̳� head->next
//	plist->head = s;//����
//}
//int SListLength(SList* plist)
//{
//	assert(plist);
//	int cnt = 0;
//	SListNode* p = plist->head;
//	while (NULL != p) {//�����󳤶�
//		p = p->next;
//		cnt++;
//	}
//	return cnt;
//}
//void SListPopBack(SList* plist)
//{
//	assert(plist);
//	SListNode* p = plist->head;
//	if (NULL != p) {
//		if (p->next == NULL) {//ֻ��һ���ڵ�
//			plist->head = NULL;
//		}
//		else {//����ڵ�
//			SListNode* pre = BuyNode();
//			while (p->next != NULL) {//Ѱ�����һ���ڵ�
//				pre = p;//ǰһ���ڵ�
//				p = p->next;
//			}
//			pre->next = NULL;
//		}
//		free(p);
//	}
//	else {
//		printf("��SList!\n");
//	}
//}	
//void SListPopFront(SList* plist)
//{
//	assert(plist);
//	SListNode* p = plist->head;
//	if (NULL != p) {
//		plist->head = p->next;//ָ����һ�ڵ�
//		free(p);
//	}
//}
//SListNode* SListFind(SList* plist, ElemType key)
//{
//	assert(plist);
//	SListNode* p = plist->head;
//	//�ǿձ�����Ѱ��
//	while (NULL != p && p->data != key)
//	{
//		p = p->next;
//	}
//	return p;
//}
//void SListClear(SList* plist)
//{
//	assert(plist);
//	SListNode* p = plist->head;
//	while (NULL != p){
//		plist->head = p->next;
//		free(p);
//		p = plist->head; //ָ���¸��ڵ�
//	}
//}
//void SlistDestroy(SList* plist)
//{
//	assert(plist);
//	SListClear(plist);
//
//}
//void SListDeleteByVal(SList* plist, ElemType x)
//{
//	assert(plist);
//	SListNode* p = plist->head;
//	SListNode* pre = NULL;
//	while (p != NULL && p->data != x) {
//		pre = p;
//		p = p->next;
//	}
//	if (p != NULL) {
//		if (pre == NULL)//��һ���ڵ�
//			plist->head = p->next;
//		else//�м�ڵ�
//			pre->next = p->next;
//		free(p);
//	}
//}
//void SListPushByVal(SList* plist, ElemType key)
//{
//	assert(plist);
//	SListNode* p = BuyNode();
//	p->data = key;
//	if (NULL == plist->head) 
//		plist->head = p;
//	else {
//		SListNode* s = plist->head;
//		SListNode* pre = NULL;
//		while (s != NULL && key > s->data) {
//			pre = s;
//			s = s->next;
//		}
//		if (NULL == pre) {
//			p->next = s;
//			plist->head = p;
//		}
//		else {
//			p->next = pre->next;
//			pre->next = p;
//		}
//	}
//}
//void SListReverse(SList* plist) 
//{
//	assert(plist);
//	if (NULL == plist->head->next || NULL == plist->head)//����Ҫת��
//		return;
//	SListNode* p = plist->head->next;//�̳е�ǰSList�ĵڶ����ڵ�
//	plist->head->next = NULL;//�Ͽ���ڶ����ڵ������
//	SListNode* q = p; //
//	while (NULL != q) {//δ���������һ���ڵ�
//		q = q->next; //�̳���һ���ڵ�
//		p->next = plist->head; //ͷ��
//		plist->head = p; //ͷ���仯
//		p = q; //����ƶ�
//	}
//}
//void SListPopAllSame(SList* plist, ElemType key) 
//{
//	assert(plist);
//	SListNode* p = plist->head;
//	SListNode* pre = NULL;
//	while (p != NULL) {
//		while (p != NULL && p->data != key) {
//			pre = p;
//			p = p->next;
//		}
//		if (p != NULL) {
//			if (pre == NULL)//��һ���ڵ�
//				plist->head = p->next;
//			else//�м�ڵ�
//				pre->next = p->next;
//			free(p);//�ͷ�data=key�Ľڵ�
//		}
//		if (NULL != pre)//
//			p = pre->next;
//		else
//			p = plist->head;//��ͷ��ʼ
//	}
//}
//void SListPushPos(SList* plist, int pos, ElemType x)
//{
//	assert(plist);
//	int len = SListLength(plist);
//	if (pos<1 || pos>len) {
//		printf("����λ�÷Ƿ�!\n");
//		return;
//	}
//	SListNode* s = BuyNode();
//	s->data = x;
//	int cnt = 1;
//	SListNode* p = plist->head;
//	while (cnt != pos) {
//		p = p->next;
//		cnt++;
//	}
//	s->next = p->next;
//	p->next = s;
//}
//void SListPopPos(SList* plist, int pos)
//{
//	assert(plist);
//	int len = SListLength(plist);
//	if (pos<1 || pos>len) {
//		printf("����λ�÷Ƿ�!\n");
//		return;
//	}
//	int cnt = 1;
//	SListNode* p = plist->head;
//	SListNode* pre = NULL;
//	while (p != NULL && cnt != pos) {
//		pre = p;
//		p = p->next;
//		cnt++;
//	}
//	if (p != NULL) {
//		if (pre == NULL)//��һ���ڵ�
//			plist->head = p->next;
//		else//�м�ڵ�
//			pre->next = p->next;
//		free(p);
//	}
//}
//void SListDestroy(SList* plist)
//{
//	assert(plist);
//	SListClear(plist);
//}
//void SListSort(SList* plist)
//{
//	assert(plist);
//	if (NULL == plist->head || NULL == plist->head->next)
//		return;
//	SListNode* p = plist->head->next;
//	SListNode* q = p;
//	plist->head->next = NULL;//����
//	while (NULL != q) {
//		q = q->next;
//		SListNode* t = plist->head;
//		SListNode* pre = NULL;
//		while (NULL != t && p->data > t->data) {//p����t��ǰ��
//			pre = t;
//			t = t->next;
//		}
//		if (NULL == pre) {
//			p->next = plist->head;
//			plist->head = p;
//		}
//		else {
//			p->next = pre->next;
//			pre->next = p;
//		}
//		p = q;
//	}
//}


