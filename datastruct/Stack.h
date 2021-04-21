//#ifndef __STACK_H__
//#define __STACK_H__
//
//#include "Sysutil.h"
//#define ElemType int
/////////��̬������˳��ջ////////
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
//		printf("����ʧ��!\n");
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
//		printf("ջ������!\n");
//}
//void SeqStackPush(SeqStack* ps,ElemType x)
//{
//	if (ps) {
//		if (IsFull(ps))
//			SeqStackInc(&ps);
//		ps->base[ps->top++] = x;
//	}		
//	else
//		printf("ջ������!\n");
//}
//void SeqStackShow(SeqStack* ps)
//{
//	if (ps) {
//		if (SeqStackEmpty(ps))
//			printf("��ջ!\n");
//		else {
//			printf("ջ��:");
//			for (int i = 0; i < ps->top; i++)
//				printf("%d-->", ps->base[i]);
//			printf("ջ��\n");
//		}	
//	}
//	else
//		printf("ջ������!\n");
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
//	printf("##############��̬˳���ջ#############\n");
//	printf("##########[1]��ջ     [2]��ջ##########\n");
//	printf("##########[3]���     [4]����##########\n");
//	printf("##########[5]ջ��     [6]չʾ##########\n");
//	printf("##########[7]�ݻ�     [0]�˳�##########\n");
//	printf("#######################################\n");
//}
//#endif

