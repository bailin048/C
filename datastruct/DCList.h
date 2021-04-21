//#ifndef __DCLIST_H__
//#define __DCLIST_H__
//
//#include "Sysutil.h"
//
//#define ElemType int
//
//typedef struct DCListNode
//{
//	ElemType data;
//	struct DCListNode* pre;
//	struct DCListNode* next;
//}DCListNode;
//
//typedef struct DCList
//{
//	size_t size;
//	DCListNode* first;
//	DCListNode* last;
//}DCList;
///// ////////////��ͷѭ������������///////////////
//void DCListMenu();
//static DCListNode* BuyDCListNode(ElemType x);
//void DCListInit(DCList* plist);
//void DCListPushFront(DCList* plist, ElemType x);
//void DCListClear(DCList* plist);
//void DCListDestroy(DCList* plist);
//void DCListShow(DCList* plist);
//size_t DCListLength(DCList* plist);
//void DCListPushBack(DCList* plist, ElemType x);
//void DCListPopBack(DCList* plist);
//void DCListPopFront(DCList* plist);
//DCListNode* DCListFind(DCList* plist, ElemType key);
//void DCListPopByVal(DCList* plist, ElemType key);
//void DCListPushByVal(DCList* plist, ElemType key);
//void DCListReverse(DCList* plist);
//void DCListrReverse(DCList* plist);
//void DCListPopAllSame(DCList* plist, ElemType key);
//void DCListPopAllSame(DCList* plist, ElemType key);
//void DCListSort(DCList* plist);
/////��ͷ˫��ѭ������////////////////////////////////////////////////////
//void DCListMenu()
//{
//	printf("**************��ͷ˫��ѭ������*************\n");
//	printf("*****   [1]��ʾ����     [2]ͷ������   *****\n");
//	printf("*****   [3]β������     [4]��ֵ����   *****\n");
//	printf("*****   [5]��ӡ����     [6]ͷ��ɾ��   *****\n");
//	printf("*****   [7]β��ɾ��     [8]��ֵɾ��   *****\n");
//	printf("*****   [9]��ֵ����     [10]��������  *****\n");
//	printf("*****   [11]Ԫ�ط�ת    [12]ֵͬɾ��  *****\n");
//	printf("*****   [13]�������    [14]��������  *****\n");
//	printf("*****            [0]�˳�              *****\n");
//	printf("*******************************************\n");
//}
//static DCListNode* BuyDCListNode(ElemType x)
//{
//	DCListNode* s = (DCListNode*)malloc(sizeof(DCListNode));
//	assert(NULL != s);
//	s->next = s->pre = NULL;
//	s->data = x;
//	return s;
//}
//void DCListInit(DCList* plist)
//{
//	DCListNode* s = BuyDCListNode(0);
//	plist->first = plist->last = s;
//	plist->last->next = plist->first;//������β
//	plist->first->pre = plist->last;
//	plist->size = 0;
//}
//void DCListPushFront(DCList* plist, ElemType x)
//{
//	assert(plist);
//	DCListNode* s = BuyDCListNode(x);
//	s->next = plist->first->next;//����first�ĺ�һ�ڵ�
//	plist->first->next->pre = s;//��s��Ϊfirst��һ�ڵ��pre
//	s->pre = plist->first;//����s��first
//	plist->first->next = s;
//	if (plist->first == plist->last)//�ձ�
//		plist->last = s; //s����last
//	plist->size++;//����++
//}
//size_t DCListLength(DCList* plist)
//{
//	return plist->size;
//}
//void DCListClear(DCList* plist)
//{
//	assert(plist);
//	DCListNode* p = plist->first->next;
//	DCListNode* s = NULL;
//	while (plist->first != p) {//�ǿձ�
//		p->next->pre = plist->first;//p�ĺ�����ǰ����Ϊfirst
//		plist->first->next = p->next;//first�ĺ�����Ϊp�ĺ���
//		free(p);
//		p = plist->first->next; //p������Ϊfirst�ĺ���
//	}
//	plist->size = 0;
//	plist->last = plist->first;
//}
//void DCListDestroy(DCList* plist)
//{
//	assert(plist);
//	DCListClear(plist);
//	free(plist->first);
//	plist->first = plist->last = NULL;
//	plist->size = 0;
//}
//void DCListShow(DCList* plist)
//{
//	assert(plist);
//	DCListNode* p = plist->first->next;
//	while (p != plist->first) {
//		printf("%d-->", p->data);
//		p = p->next;
//	}
//	printf("end\n");
//}
//void DCListPushBack(DCList* plist, ElemType x)
//{
//	assert(plist);
//	DCListNode* p = BuyDCListNode(x);
//	p->next = plist->first;//p�ĺ�����Ϊfirst
//	p->pre = plist->last;//p��ǰ����Ϊlast
//	plist->last->next = p;//last�ĺ�����Ϊp
//	plist->first->pre = p;//first��ǰ����Ϊp
//	plist->last = p;//last����
//	plist->size++;//��������
//}
//void DCListPopBack(DCList* plist)
//{
//	assert(plist);
//	DCListNode* p = plist->last;
//	if (plist->last != plist->first) {
//		p->pre->next = plist->first;
//		plist->first->pre = p->pre;
//		plist->size--;
//		plist->last = p->pre;
//		free(p);
//	}
//
//}
//void DCListPopFront(DCList* plist)
//{
//	assert(plist);
//	if (0 == plist->size)
//		return;
//	DCListNode* p = plist->first->next;
//	plist->first->next = p->next;
//	p->next->pre = plist->first;
//	plist->size--;
//	free(p);
//	p = NULL;
//	if (plist->size == 0)
//		plist->last = plist->first;
//}
//DCListNode* DCListFind(DCList* plist, ElemType key)
//{
//	assert(plist);
//	DCListNode* p = plist->first->next;
//	while (p != plist->first && p->data != key)
//		p = p->next;
//	if (p == plist->first)
//		return NULL;
//	return p;
//}
//void DCListPopByVal(DCList* plist, ElemType key)
//{
//	assert(plist);
//	DCListNode* p = DCListFind(plist, key);
//	if (NULL == p)
//		return;
//	if (plist->last == p)
//		plist->last = p->pre;
//	p->pre->next = p->next;
//	p->next->pre = p->pre;
//	free(p);
//	plist->size--;
//}
//void DCListPushByVal(DCList* plist, ElemType key)
//{
//	assert(plist);
//	DCListNode* s = BuyDCListNode(key);
//	s->data = key;
//	if (plist->first == plist->last)
//		plist->last = s;
//	DCListNode* p = plist->first->next;
//	while (p != plist->first && p->data < key)//����ѭ������:key������ or p->data>=key
//		p = p->next;
//	s->next = p;
//	s->pre = p->pre;
//	p->pre->next = s;
//	p->pre = s;
//	plist->size++;
//}
//void DCListReverse(DCList* plist)
//{
//	assert(plist);
//	if (plist->size <= 1)
//		return;
//	DCListNode* p = plist->first->next;
//	DCListNode* q = p->next;
//	plist->last = p;
//	plist->last->next = plist->first;
//	plist->first->pre = plist->last;
//	while (q != plist->first) {
//		p = q;
//		q = q->next;
//		p->next = plist->first->next;
//		p->next->pre = p;
//		plist->first->next = p;
//		p->pre = plist->first;
//	}
//}
//void DCListPopAllSame(DCList* plist, ElemType key)
//{
//	assert(plist);
//	if (0 == plist->size)
//		return;
//	DCListNode* p = plist->first->next;
//	while (plist->first != p) {
//		while (p != plist->first && p->data != key)
//			p = p->next;
//		if (p->data != key)//���������˵��������data=key�Ľڵ�
//			return;
//		if (plist->last != p) {//���������˵������data=key�Ľڵ������м�ڵ�
//			p->next->pre = p->pre;
//			p->pre->next = p->next;
//
//		}
//		else {//last�ڵ�
//			plist->last = p->pre;
//			plist->last->next = plist->first;
//			plist->first->pre = plist->last;
//		}
//		DCListNode* s = p->next;
//		free(p);
//		p = s;
//		plist->size--;
//	}
//}
//void DCListSort(DCList* plist)
//{
//	assert(plist);
//	if (plist->size <= 1)
//		return;
//	DCListNode* p = plist->first->next;
//	plist->last = p;
//	DCListNode* q = p->next;
//	plist->last->next = plist->first;
//	plist->first->pre = plist->last;//����
//	while (plist->first != q) {   //δ����
//		while (q->data >= p->data && plist->first != p)
//			p = p->next;
//		q->pre = p->pre;
//		p->pre->next = q;
//		if (plist->first == p) //��Ϊlast
//			plist->last = q;
//		p->pre = q;
//		q = q->next;//q����
//		p->pre->next = p;//q�������p
//		p = plist->first->next;//p����
//	}
//}
//
//
//#endif