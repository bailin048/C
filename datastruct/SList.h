//#pragma once
//#include "Sysutil.h"
//
//typedef int SLTDateType;
//typedef struct SListNode
//{
//	SLTDateType data;
//	struct SListNode* next;
//}SListNode;
//
//SListNode* BuyPSListNode(SLTDateType x);
//void PSListPrint(SListNode* plist);
//void PSListPushBack(SListNode** pplist, SLTDateType x);
//void PSListPushFront(SListNode** pplist, SLTDateType x);
//void PSListPopBack(SListNode** pplist);
//void PSListPopFront(SListNode** pplist);
//SListNode* PSListFind(SListNode* plist, SLTDateType x);
//void PSListInsertAfter(SListNode* pos, SLTDateType x);
//void PSListEraseAfter(SListNode* pos);
//void PSListDestory(SListNode* plist);
//void PSListMenu();
//
//SListNode* BuyPSListNode(SLTDateType x)
//{
//	SListNode* p = (SListNode*)malloc(sizeof(SListNode));
//	p->data = x;
//	p->next = NULL;
//}
//void PSListPrint(SListNode* plist)
//{
//	if (plist != NULL) {
//		SListNode* p = plist;
//		while (p) {
//			printf("%d-->", p->data);
//			p = p->next;
//		}
//		printf("end\n");
//	}
//}
//void PSListPushBack(SListNode** pplist, SLTDateType x)
//{
//	SListNode* s = BuyPSListNode(x);
//	if (!*pplist)
//		*pplist = s;
//	else {
//		SListNode* p = *pplist;
//		SListNode* pre = NULL;
//		while (p) {
//			pre = p;
//			p = p->next;
//		}
//		pre->next = s;
//	}
//}
//void PSListPushFront(SListNode** pplist, SLTDateType x)
//{
//	SListNode* s = BuyPSListNode(x);
//	SListNode* p = (*pplist);
//	s->next = p;
//	*pplist = s;
//}
//void PSListPopBack(SListNode** pplist)
//{
//	if (!*pplist) {
//		printf("空链表!\n");
//	}
//	else {
//		SListNode* p = *pplist;
//		if ((*pplist)->next == NULL) {
//			free(*pplist);
//			*pplist = NULL;
//		}
//		else {
//			SListNode* rear = p->next;
//			while (rear->next) {
//				p = p->next;
//				rear = rear->next;
//			}
//			p->next = NULL;
//			free(rear);
//			rear = NULL;
//		}
//	}
//}
//void PSListPopFront(SListNode** pplist)
//{
//	if (!*pplist) {
//		printf("空链表!\n");
//	}
//	else {
//		SListNode* p = (*pplist)->next;
//		free(*pplist);
//		*pplist = p;
//	}
//}
//SListNode* PSListFind(SListNode* plist, SLTDateType x)
//{
//	if (!plist) {
//		printf("空链表");
//	}
//	SListNode* p = plist;
//	while (p&&p->data != x) 
//		p = p->next;
//	return p;
//}
//void PSListInsertAfter(SListNode* pos, SLTDateType x)
//{
//	SListNode* s = BuyPSListNode(x);
//	s->next = pos->next;
//	pos->next = s;
//}
//void PSListEraseAfter(SListNode* pos)
//{
//	if (pos) {
//		SListNode* p = pos->next->next;
//		free(pos->next);
//		pos->next = p;
//	}
//}
//void PSListDestory(SListNode* plist)
//{
//	SListNode* p = plist;
//	SListNode* pre = p;
//	while (p) {
//		p = p->next;
//		free(pre);
//		pre = p;
//	}
//	pre = NULL;
//}
//void PSListMenu()
//{
//	printf("**************二级指针单向链表*************\n");
//	printf("*****   [1]尾部插入     [2]头部插入   *****\n");
//	printf("*****   [3]尾部删除     [4]头部删除   *****\n");
//	printf("*****   [5]按位插入     [6]按位删除   *****\n");
//	printf("*****   [7]打印所有     [8]销毁链表   *****\n");
//	printf("*****            [0]退出              *****\n");
//	printf("*******************************************\n");
//}
