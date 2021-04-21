//#ifndef __QUEUE_H__
//#define __QUEUE_H__
//
//#include "Sysutil.h"
////#define QDataType int 
//struct BTNode;
//#define QDataType struct BTNode*
//
//////////单向链表队列///////////
//typedef struct QListNode
//{
//	struct QListNode* _next;
//	QDataType _data;
//}QNode;
//
//typedef struct Queue
//{
//	QNode* _front;
//	QNode* _rear;
//}Queue;
//
//void QueueInit(Queue* q);
//void QueuePush(Queue* q, QDataType data);
//void QueuePop(Queue* q);
//QDataType QueueFront(Queue* q);
//QDataType QueueBack(Queue* q); 
//int QueueSize(Queue* q);
//int QueueEmpty(Queue* q);
//void QueueDestroy(Queue* q);
//void QueueMenu();
//static QNode* BuyNode(QDataType x);
//void QueueShow();
//
//static QNode* BuyNode(QDataType x)
//{
//	QNode* p = (QNode*)malloc(sizeof(QNode));
//	p->_data = x;
//	p->_next = NULL;
//	return p;
//}
//void QueueInit(Queue* q)
//{
//	if (q) {
//		q->_front = NULL;
//		q->_rear = NULL;
//	}
//	else
//		printf("队列不存在!\n");
//}
//void QueuePush(Queue* q, QDataType data)
//{
//	if (!q) {
//		printf("队列不存在!\n");
//		return;
//	}
//	else {
//		QNode* s = BuyNode(data);
//		if (QueueEmpty(q))
//			q->_front = q->_rear = s;
//		else {
//			q->_rear->_next = s;
//			q->_rear = s;
//		}
//	}
//}
//void QueuePop(Queue* q)
//{
//	if (q) {
//		if (q->_front)
//		{
//			QNode* p = q->_front;
//			q->_front = q->_front->_next;
//			free(p);
//			p = NULL;
//		}
//		else
//			printf("空队列!\n");
//	}
//	else 
//		printf("队列不存在!\n");
//}
//QDataType QueueFront(Queue* q)
//{
//	assert(q&&q->_front);
//		return q->_front->_data;
//}
//QDataType QueueBack(Queue* q)
//{
//	assert(q&&q->_rear);
//	return q->_rear->_data;
//}
//int QueueSize(Queue* q)
//{
//	int size = 0;
//	if (q) {
//		QNode* p = q->_front;
//		while (p) {
//			size++;
//			p = p->_next;
//		}
//	}
//	else {
//		printf("队列不存在!\n");
//	}
//	return size;
//}
//int QueueEmpty(Queue* q)
//{
//	if (q)
//		return !q->_front;
//	else {
//		printf("队列不存在!\n");
//		return 1;
//	}
//}
//void QueueDestroy(Queue* q)
//{
//	if (q) {
//		QNode* p = q->_front;
//		QNode* pre = p;
//		while (pre) {
//			p = p->_next;
//			free(pre);
//			pre = p;
//		}
//		q->_front = q->_rear = NULL;
//	}
//}
//void QueueShow(Queue* q)
//{
//	if (q->_front == q->_rear && !q->_front) 
//		printf("空队列!\n");
//	else {
//		QNode* p = q->_front;
//		printf("队头:");
//		while (p) {
//			printf("%d<--", p->_data);
//			p = p->_next;
//		}
//		printf("队尾\n");
//	}
//}
//void QueueMenu()
//{
//	printf("##############单向链表队列#############\n");
//	printf("##########[1]入队     [2]出队##########\n");
//	printf("##########[3]验空     [4]计数##########\n");
//	printf("##########[5]队头     [6]队尾##########\n");
//	printf("##########[7]摧毁     [8]展示##########\n");
//	printf("##########      [0]退出      ##########\n");
//	printf("#######################################\n");
//}
//
//#endif
//
