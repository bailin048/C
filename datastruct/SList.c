//#include "SList.h"
//
//int main()
//{
//	SListNode* List = NULL;
//	SListNode* phead = &List;
//	SLTDateType item = 0;
//	int choice = 0;
//	int quit = 1;
//	while (quit) {
//		PSListMenu();
//		printf("����������ѡ��#\n");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			printf("�����������������ݣ�-1�������룩#");
//			while (scanf("%d", &item), item != -1) {
//				PSListPushBack(phead, item);
//			}
//			PSListPrint(List);
//			break;
//		case 2:
//			printf("�����������������ݣ�-1�������룩#");
//			while (scanf("%d", &item), item != -1) {
//				PSListPushFront(phead, item);
//			}
//			PSListPrint(List);
//			break;
//		case 3:PSListPopBack(phead); PSListPrint(List); break;
//		case 4:PSListPopFront(phead); PSListPrint(List); break;
//		case 5:
//			printf("���������������˭֮�󣿣�Ŀǰ��֧�ֲ����ظ����ֵĵ�һ������֮��\n");
//			PSListPrint(List);
//			printf("����˭����?#");
//			scanf("%d", &item);
//			SListNode* p = PSListFind(List, item);
//			printf("�������˭��#");
//			scanf("%d", &item);
//			PSListInsertAfter(p, item);
//			PSListPrint(List);
//			break;
//		case 6:
//			printf("����������ɾ��˭֮���Ԫ�أ�(ɾ��β��ѡ��������ʽ)\n");
//			PSListPrint(List);
//			printf("����������#");
//			scanf("%d", &item);
//			p = PSListFind(List, item);
//			PSListEraseAfter(p);
//			PSListPrint(List);
//			break;
//		case 7:PSListPrint(List); break;
//		case 8:PSListDestory(List); break;
//		case 0:printf("�ټ�!\n"); quit = 0; break;
//		default:printf("������������!����������!\n");  break;
//		}
//		system("pause");
//		system("cls");
//	}
//}