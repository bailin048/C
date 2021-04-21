//#ifndef _LINKSTACK_H__
//#define _LINKSTACK_H__
//
//#include"Sysutil.h"
//
//struct BTNode;
//#define StackElemType struct BTNode*
//
//#define SEQSTACK_DEFAULT_SIZE 8
//
////Á´Õ»
//typedef struct LinkStackNode
//{
//	StackElemType data;
//	struct LinkStackNode* next;
//}LinkStackNode;
//typedef struct LinkStack
//{
//	LinkStackNode* head;
//}LinkStack;
//
//void LinkStackInit(LinkStack* pst);
//void LinkStackDestroy(LinkStack* pst);
//void LinkStackPush(LinkStack* pst, StackElemType x);
//void LinkStackPop(LinkStack* pst);
//StackElemType LinkStackTop(LinkStack* pst);
//void LinkStackShow(LinkStack* pst);
//bool LinkStackEmpty(LinkStack* pst)
//{
//	return pst->head == NULL;
//}
//
//void LinkStackInit(LinkStack* pst)
//{
//	assert(pst);
//	pst->head = NULL;
//}
//
//void LinkStackPush(LinkStack* pst, StackElemType x)
//{
//	assert(pst);
//	LinkStackNode* s = (LinkStackNode*)malloc(sizeof(LinkStackNode));
//	assert(s != NULL);
//	s->data = x;
//
//	s->next = pst->head;
//	pst->head = s;
//}
//
//void LinkStackPop(LinkStack* pst)
//{
//	assert(pst);
//	if (pst->head != NULL)
//	{
//		LinkStackNode* p = pst->head;
//		pst->head = p->next;
//		free(p);
//	}
//}
//
//StackElemType LinkStackTop(LinkStack* pst)
//{
//	assert(pst && pst->head != NULL);
//	return pst->head->data;
//}
//
//void LinkStackShow(LinkStack* pst)
//{
//	assert(pst);
//	LinkStackNode* p = pst->head;
//	while (p != NULL)
//	{
//		printf("%d\n", p->data);
//		p = p->next;
//	}
//}
//
//void LinkStackDestroy(LinkStack* pst)
//{
//	assert(pst);
//	while (pst->head != NULL)
//	{
//		LinkStackNode* p = pst->head;
//		pst->head = p->next;
//		free(p);
//	}
//}
//
//#endif /* _STACK_H_ */
