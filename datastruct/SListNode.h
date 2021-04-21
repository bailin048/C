//#pragma once
//#include "Sysutil.h"

//#define ElemType int
//
//
///////////////无头单链表///////////////////////////
//typedef struct SListNode
//{
//	ElemType data;//数据域
//	struct SListNode* next;//指针域
//}SListNode;
//
//typedef struct SList
//{
//	SListNode* head;
//}SList;
//void SListMenu();
///////////无头单向链表函数声明////////////////////
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
//	printf("*****************无头单链表****************\n");
//	printf("*****   [1]显示长度     [2]头部插入   *****\n");
//	printf("*****   [3]尾部插入     [4]按值插入   *****\n");
//	printf("*****   [5]打印所有     [6]头部删除   *****\n");
//	printf("*****   [7]尾部删除     [8]按值删除   *****\n");
//	printf("*****   [9]按值查找     [10]销毁链表  *****\n");
//	printf("*****   [11]元素翻转    [12]同值删除  *****\n");
//	printf("*****   [13]按位插入    [14]按位删除  *****\n");
//	printf("*****   [15]清除内容    [0]退出       *****\n");
//	printf("*******************************************\n");
//}
//void SListInit(SList* plist)
//{//初始化:无头单链表
//	plist->head = NULL;
//}
//static SListNode* BuyNode() 
//{
//	SListNode* p = (SListNode*)malloc(sizeof(SListNode));//申请节点
//	assert(p != NULL);
//	p->data = 0;//节点初始化
//	p->next = NULL;
//	return p;
//}
//void SListPushBack(SList* plist, ElemType x)
//{
//	assert(plist);//合法检查
//	SListNode* p = plist->head;
//	SListNode* s = BuyNode(); //创建新节点，存储数据
//	s->data = x;
//	if (NULL == p) {//空表，链接
//		plist->head = s;
//	}
//	else {//非空，尾插
//		while (NULL != p->next) {//找到表尾
//			p = p->next;
//		}
//		p->next = s;//链接
//	}
//}
//void SListShow(SList* plist)
//{
//	assert(plist);
//	SListNode* p = plist->head;//继承head
//	while (NULL != p) {//打印
//		printf("%d-->",p->data);
//		p = p->next;
//	}
//	printf("end\n");//结束指示
//}
//void SListPushFront(SList* plist, ElemType x)
//{
//	assert(plist);//合法检查
//	SListNode* s = BuyNode(); //创建新节点，存储数据
//	s->data = x;
//	s->next = plist->head;//继承 head->next
//	plist->head = s;//链接
//}
//int SListLength(SList* plist)
//{
//	assert(plist);
//	int cnt = 0;
//	SListNode* p = plist->head;
//	while (NULL != p) {//遍历求长度
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
//		if (p->next == NULL) {//只有一个节点
//			plist->head = NULL;
//		}
//		else {//多个节点
//			SListNode* pre = BuyNode();
//			while (p->next != NULL) {//寻找最后一个节点
//				pre = p;//前一个节点
//				p = p->next;
//			}
//			pre->next = NULL;
//		}
//		free(p);
//	}
//	else {
//		printf("空SList!\n");
//	}
//}	
//void SListPopFront(SList* plist)
//{
//	assert(plist);
//	SListNode* p = plist->head;
//	if (NULL != p) {
//		plist->head = p->next;//指向下一节点
//		free(p);
//	}
//}
//SListNode* SListFind(SList* plist, ElemType key)
//{
//	assert(plist);
//	SListNode* p = plist->head;
//	//非空表，遍历寻找
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
//		p = plist->head; //指向下个节点
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
//		if (pre == NULL)//第一个节点
//			plist->head = p->next;
//		else//中间节点
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
//	if (NULL == plist->head->next || NULL == plist->head)//不需要转置
//		return;
//	SListNode* p = plist->head->next;//继承当前SList的第二个节点
//	plist->head->next = NULL;//断开与第二个节点的链接
//	SListNode* q = p; //
//	while (NULL != q) {//未遍历到最后一个节点
//		q = q->next; //继承下一个节点
//		p->next = plist->head; //头插
//		plist->head = p; //头结点变化
//		p = q; //向后移动
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
//			if (pre == NULL)//第一个节点
//				plist->head = p->next;
//			else//中间节点
//				pre->next = p->next;
//			free(p);//释放data=key的节点
//		}
//		if (NULL != pre)//
//			p = pre->next;
//		else
//			p = plist->head;//从头开始
//	}
//}
//void SListPushPos(SList* plist, int pos, ElemType x)
//{
//	assert(plist);
//	int len = SListLength(plist);
//	if (pos<1 || pos>len) {
//		printf("插入位置非法!\n");
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
//		printf("输入位置非法!\n");
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
//		if (pre == NULL)//第一个节点
//			plist->head = p->next;
//		else//中间节点
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
//	plist->head->next = NULL;//断链
//	while (NULL != q) {
//		q = q->next;
//		SListNode* t = plist->head;
//		SListNode* pre = NULL;
//		while (NULL != t && p->data > t->data) {//p插在t的前面
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


