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
//		printf("请输入想要执行的操作#");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			printf("请输入将入栈元素(-1结束)#");
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
//				printf("非空栈!\n");
//			else
//				printf("空栈!\n");
//			break;
//		case 4:
//			printf("栈目前共有[%d]个元素!\n",SeqStackSize(&stack));
//			break;
//		case 5:
//			item = SeqStackTop(&stack);
//			if(-1!= item)
//				printf("栈顶元素为[%d]\n", SeqStackTop(&stack));
//			else
//				printf("空栈!\n");
//			break;
//		case 6:
//			SeqStackShow(&stack);
//			break;
//		case 7:
//			SeqStackDestroy(&stack); break;
//		case 0:
//			printf("再见!\n"); quit = 0; break;
//		}
//		system("pause");
//		system("cls");
//	}
//
//
//	return 0;
//}