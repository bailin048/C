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
///// ////////////带头循环链表函数声明///////////////
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
/////带头双向循环链表////////////////////////////////////////////////////
//void DCListMenu()
//{
//	printf("**************带头双向循环链表*************\n");
//	printf("*****   [1]显示长度     [2]头部插入   *****\n");
//	printf("*****   [3]尾部插入     [4]按值插入   *****\n");
//	printf("*****   [5]打印所有     [6]头部删除   *****\n");
//	printf("*****   [7]尾部删除     [8]按值删除   *****\n");
//	printf("*****   [9]按值查找     [10]销毁链表  *****\n");
//	printf("*****   [11]元素翻转    [12]同值删除  *****\n");
//	printf("*****   [13]清除内容    [14]增序排序  *****\n");
//	printf("*****            [0]退出              *****\n");
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
//	plist->last->next = plist->first;//链接首尾
//	plist->first->pre = plist->last;
//	plist->size = 0;
//}
//void DCListPushFront(DCList* plist, ElemType x)
//{
//	assert(plist);
//	DCListNode* s = BuyDCListNode(x);
//	s->next = plist->first->next;//链接first的后一节点
//	plist->first->next->pre = s;//将s设为first后一节点的pre
//	s->pre = plist->first;//链解s与first
//	plist->first->next = s;
//	if (plist->first == plist->last)//空表
//		plist->last = s; //s就是last
//	plist->size++;//长度++
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
//	while (plist->first != p) {//非空表
//		p->next->pre = plist->first;//p的后驱的前驱设为first
//		plist->first->next = p->next;//first的后驱设为p的后驱
//		free(p);
//		p = plist->first->next; //p重新设为first的后驱
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
//	p->next = plist->first;//p的后驱设为first
//	p->pre = plist->last;//p的前驱设为last
//	plist->last->next = p;//last的后驱设为p
//	plist->first->pre = p;//first的前驱设为p
//	plist->last = p;//last后移
//	plist->size++;//长度自增
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
//	while (p != plist->first && p->data < key)//出此循环满足:key是最大的 or p->data>=key
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
//		if (p->data != key)//满足此条件说明不存在data=key的节点
//			return;
//		if (plist->last != p) {//满足此条件说明存在data=key的节点且是中间节点
//			p->next->pre = p->pre;
//			p->pre->next = p->next;
//
//		}
//		else {//last节点
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
//	plist->first->pre = plist->last;//链接
//	while (plist->first != q) {   //未排完
//		while (q->data >= p->data && plist->first != p)
//			p = p->next;
//		q->pre = p->pre;
//		p->pre->next = q;
//		if (plist->first == p) //成为last
//			plist->last = q;
//		p->pre = q;
//		q = q->next;//q后移
//		p->pre->next = p;//q向后链接p
//		p = plist->first->next;//p重置
//	}
//}
//
//
//#endif