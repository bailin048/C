//#include "Stack.h"

//int main()
//{
//	SeqStack stack;
//	SeqStackInit(&stack,DEFAULT_SIZE);
//	ElemType item;
//	int choice = 0;
//	int quit = 1;
//	while (quit) {
//		SeqStackMenu();
//		printf("��������Ҫִ�еĲ���#");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			printf("�����뽫��ջԪ��(-1����)#");
//			while (scanf("%d", &item), item != -1) {
//				SeqStackPush(&stack, item);
//			}
//			SeqStackShow(&stack);
//			break;
//		case 2:
//			SeqStackPop(&stack);
//			SeqStackShow(&stack);
//			break;
//		case 3:
//			if (!SeqStackEmpty(&stack))
//				printf("�ǿ�ջ!\n");
//			else
//				printf("��ջ!\n");
//			break;
//		case 4:
//			printf("ջĿǰ����[%d]��Ԫ��!\n",SeqStackSize(&stack));
//			break;
//		case 5:
//			item = SeqStackTop(&stack);
//			if(-1!= item)
//				printf("ջ��Ԫ��Ϊ[%d]\n", SeqStackTop(&stack));
//			else
//				printf("��ջ!\n");
//			break;
//		case 6:
//			SeqStackShow(&stack);
//			break;
//		case 7:
//			SeqStackDestroy(&stack); break;
//		case 0:
//			printf("�ټ�!\n"); quit = 0; break;
//		}
//		system("pause");
//		system("cls");
//	}
//
//
//	return 0;
//}