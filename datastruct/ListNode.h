//#pragma once
//#include "Sysutil.h"
//
//typedef int LTDataType;
//
//typedef struct ListNode
//{
//	LTDataType _data;
//	struct ListNode* _next;
//	struct ListNode* _prev;
//}ListNode;
//
//void ListMenu()
//{
//	printf("***************带头双向循环链表************\n");
//	printf("*****   [1]尾部插入     [2]头部插入   *****\n");
//	printf("*****   [3]尾部删除     [4]头部删除   *****\n");
//	printf("*****   [5]按位插入     [6]按位删除  *****\n");
//	printf("*****   [7]打印所有     [8]销毁链表   *****\n");
//	printf("*****            [0]退出              *****\n");
//	printf("*******************************************\n");
//}
//ListNode* ListCreate();
//void ListDestory(ListNode* pHead);
//void ListPrint(ListNode* pHead);
//void ListPushBack(ListNode* pHead, LTDataType x);
//void ListPopBack(ListNode* pHead);
//void ListPushFront(ListNode* pHead, LTDataType x);
//void ListPopFront(ListNode* pHead);
//ListNode* ListFind(ListNode* pHead, LTDataType x);
//void ListInsert(ListNode* pos, LTDataType x);
//void ListErase(ListNode* pos);
//
//static ListNode* BuyNode(LTDataType x)
//{
//	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
//	p->_data = x;
//	p->_next = p;
//	p->_data = x;
//	p->_next = p;
//	p->_prev = p;
//}
//ListNode* ListCreate()
//{
//	ListNode* p = BuyNode(0);//传0,将头结点的data设为size
//	return p;
//}
//void ListDestory(ListNode* pHead)
//{
//	assert(pHead);
//	ListNode* last = pHead->_prev;//最后一个节点
//	ListNode* p = pHead;
//	while (p != last) {
//		ListNode* q = p;
//		p = p->_next;
//		free(q);
//		q = NULL;
//	}
//	free(p);
//	p = NULL;
//	last = NULL;
//}
//void ListPrint(ListNode* pHead)
//{
//	assert(pHead);
//	ListNode* p = pHead->_next;
//	while (p != pHead) {
//		printf("%d-->", p->_data);
//		p = p->_next;
//	}
//	printf("end\n");
//}
//void ListPushBack(ListNode* pHead, LTDataType x)
//{
//	assert(pHead);
//	ListNode* p = BuyNode(x);
//	p->_next = pHead;
//	ListNode* s = pHead->_next;
//	while (s != pHead->_prev) //找到表尾
//		s = s->_next;
//	s->_next = p;
//	p->_prev = s;
//	pHead->_prev = p;
//	pHead->_data++;
//}
//void ListPopBack(ListNode* pHead)
//{
//	assert(pHead);
//	ListNode* p = pHead->_prev;
//	if (p != pHead) {
//		p->_prev->_next = pHead;
//		pHead->_prev = p->_prev;
//		free(p);
//		p = NULL;
//		pHead->_data--;
//	}
//}
//void ListPushFront(ListNode* pHead, LTDataType x)
//{
//	assert(pHead);
//	ListNode* p = pHead->_next;
//	ListNode* s = BuyNode(x);
//	s->_prev = pHead;
//	s->_next = pHead->_next;
//	p->_prev = s;
//	pHead->_next = s;
//	pHead->_data++;
//}
//void ListPopFront(ListNode* pHead)
//{
//	assert(pHead);
//	ListNode* p = pHead->_next;
//	if (p != pHead) {//非空表
//		p->_next->_prev = pHead;
//		pHead->_next = p->_next;
//		pHead->_data--;
//		free(p);
//		p = NULL;
//	}
//}
//ListNode* ListFind(ListNode* pHead, LTDataType x)
//{
//	assert(pHead);
//	ListNode* p = pHead->_next;
//	while (p != pHead && p->_data != x)
//		p = p->_next;
//	if (p->_data == x)
//		return p;
//	else
//		return NULL;
//}
//void ListInsert(ListNode* pos, LTDataType x)
//{
//	if (NULL != pos) {
//		ListNode* s = BuyNode(x);
//		ListNode* p = pos;
//		s->_next = pos;
//		s->_prev = pos->_prev;
//		pos->_prev = s;
//		s->_prev->_next = s;
//
//	}
//}
//void ListErase(ListNode* pos)
//{
//	if (NULL != pos) {
//		pos->_next->_prev = pos->_prev;
//		pos->_prev->_next = pos->_next;
//	}
//}
