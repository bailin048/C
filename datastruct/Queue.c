//#include "Queue.h"
//
//int main()
//{
//	Queue Q;
//	QueueInit(&Q);
//	QDataType item;
//	int choice = 0;
//	int quit = 1;
//	while (quit) {
//		QueueMenu();
//		printf("请输入想要执行的操作#");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			printf("请输入将入队列元素(-1结束)#");
//			while (scanf("%d", &item), item != -1) {
//				QueuePush(&Q, item);
//			}
//			QueueShow(&Q);
//			break;
//		case 2:
//			QueuePop(&Q);
//			QueueShow(&Q);
//			break;
//		case 3:
//			if (!QueueEmpty(&Q))
//				printf("非空队列!\n");
//			else
//				printf("空队列!\n");
//			break;
//		case 4:
//			printf("队列目前共有[%d]个元素!\n", QueueSize(&Q));
//			break;
//		case 5:
//			printf("队头元素为[%d]\n", QueueFront(&Q));
//			break;
//		case 6:
//			printf("队尾元素为[%d]\n", QueueBack(&Q));
//			break;
//		case 7:
//			QueueDestroy(&Q); break;
//		case 8:QueueShow(&Q); break;
//		case 0:
//			printf("再见!\n"); quit = 0; break;
//		}
//		system("pause");
//		system("cls");
//	}
//	return 0;
//}