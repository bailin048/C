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
//		printf("��������Ҫִ�еĲ���#");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			printf("�����뽫�����Ԫ��(-1����)#");
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
//				printf("�ǿն���!\n");
//			else
//				printf("�ն���!\n");
//			break;
//		case 4:
//			printf("����Ŀǰ����[%d]��Ԫ��!\n", QueueSize(&Q));
//			break;
//		case 5:
//			printf("��ͷԪ��Ϊ[%d]\n", QueueFront(&Q));
//			break;
//		case 6:
//			printf("��βԪ��Ϊ[%d]\n", QueueBack(&Q));
//			break;
//		case 7:
//			QueueDestroy(&Q); break;
//		case 8:QueueShow(&Q); break;
//		case 0:
//			printf("�ټ�!\n"); quit = 0; break;
//		}
//		system("pause");
//		system("cls");
//	}
//	return 0;
//}