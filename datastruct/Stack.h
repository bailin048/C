//#ifndef __STACK_H__
//#define __STACK_H__
//
//#include "Sysutil.h"
//#define ElemType int
/////////动态增长的顺序栈////////
//#define DEFAULT_SIZE 8
//typedef struct SeqStack 
//{
//	ElemType* base;
//	int capacity;
//	int top;
//}SeqStack;
//
//void SeqStackInit(SeqStack* ps,int size);
//void SeqStackPush(SeqStack* ps,ElemType x);
//void SeqStackPop(SeqStack* ps);
//ElemType SeqStackTop(SeqStack* ps);
//int SeqStackSize(SeqStack* ps);
//int SeqStackEmpty(SeqStack* ps);
//void SeqStackDestroy(SeqStack* ps);
//void SeqStackShow(SeqStack* ps);
//static int IsFull(SeqStack* ps);
//static void SeqStackInc(SeqStack* ps);
//
//static int IsFull(SeqStack* ps) 
//{
//	return ps->top >= ps->capacity;
//}
//int SeqStackEmpty(SeqStack* ps)
//{
//	return 0 == ps->top;
//}
//static void SeqStackInc(SeqStack** pps)
//{
//	ElemType* q = (ElemType*)realloc((*pps)->base,sizeof(ElemType)* ((*pps)->capacity) * 2);
//	if (q)
//		(*pps)->base = q;
//	else
//		printf("扩容失败!\n");
//}
//void SeqStackInit(SeqStack* sp,int size)
//{
//	size = size > DEFAULT_SIZE ? size : DEFAULT_SIZE;
//	if (sp && size > 0) {
//		sp->base = (ElemType*)malloc(sizeof(ElemType) * size);
//		sp->capacity = size;
//		sp->top = 0;
//	}
//	else
//		printf("栈不存在!\n");
//}
//void SeqStackPush(SeqStack* ps,ElemType x)
//{
//	if (ps) {
//		if (IsFull(ps))
//			SeqStackInc(&ps);
//		ps->base[ps->top++] = x;
//	}		
//	else
//		printf("栈不存在!\n");
//}
//void SeqStackShow(SeqStack* ps)
//{
//	if (ps) {
//		if (SeqStackEmpty(ps))
//			printf("空栈!\n");
//		else {
//			printf("栈底:");
//			for (int i = 0; i < ps->top; i++)
//				printf("%d-->", ps->base[i]);
//			printf("栈顶\n");
//		}	
//	}
//	else
//		printf("栈不存在!\n");
//}
//void SeqStackDestroy(SeqStack* ps)
//{
//	free(ps->base);
//	ps->capacity = ps->top = 0;
//}
//void SeqStackPop(SeqStack* ps)
//{
//	if (!SeqStackEmpty(ps))
//		ps->top--;
//}
//int SeqStackSize(SeqStack* ps)
//{
//	if (!SeqStackEmpty(ps))
//		return ps->top;
//	else
//		return 0;
//}
//ElemType SeqStackTop(SeqStack* ps)
//{
//	assert(ps && !SeqStackEmpty(ps));
//	return ps->base[ps->top - 1];
//}
//void SeqStackMenu()
//{	
//	printf("##############动态顺序表栈#############\n");
//	printf("##########[1]入栈     [2]出栈##########\n");
//	printf("##########[3]验空     [4]计数##########\n");
//	printf("##########[5]栈顶     [6]展示##########\n");
//	printf("##########[7]摧毁     [0]退出##########\n");
//	printf("#######################################\n");
//}
//#endif

