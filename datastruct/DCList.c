//#include "DCList.h"

//int main()
//{
//	DCList mylist;
//	DCListInit(&mylist);
//	int choice;
//	int quit = 0;
//	int pos = 0;
//	ElemType item;
//	while (!quit) {
//		DCListMenu();
//		printf("���������ѡ��#");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			printf("DClist����Ϊ[%d]\n", DCListLength(&mylist));
//			break;
//		case 2:
//			printf("��������Ҫ���������(-1����)#");
//			while (scanf("%d", &item), item != -1) {
//				DCListPushFront(&mylist, item);
//			}
//			DCListShow(&mylist); break;
//		case 3:
//			printf("��������Ҫ���������(-1����)#");
//			while (scanf("%d", &item), item != -1) {
//				DCListPushBack(&mylist, item);
//			}
//			DCListShow(&mylist);
//			break;
//		case 4:
//			printf("��������Ҫ���������#");
//			scanf("%d", &item);
//			DCListPushByVal(&mylist, item);
//		    DCListShow(&mylist); break;
//			case 5:DCListShow(&mylist); break;
//			case 6:DCListPopFront(&mylist); DCListShow(&mylist); break;
//			case 7:DCListPopBack(&mylist); DCListShow(&mylist); break;
//			case 8:
//				printf("��������Ҫɾ��������#");
//				scanf("%d", &item);
//				DCListPopByVal(&mylist, item);
//				DCListShow(&mylist);
//				break;
//		case 9:
//			printf("��������Ҫ���ҵ�����)#");
//			scanf("%d", &item);
//			DCListNode* p = DCListFind(&mylist, item);
//			if (NULL != p) {
//				printf("[%d]������洢��ַΪ[%p]\n", item, &p);
//			}
//			else
//				printf("[%d]��������SList��!\n", item);
//			break;
//			case 10:DCListDestroy(&mylist); break;
//		case 11:DCListReverse(&mylist); DCListShow(&mylist); 
//		break;
//		case 12:
//			printf("��������Ҫȫ��ɾ����ͬһ����)#");
//			scanf("%d", &item);
//			DCListPopAllSame(&mylist, item);
//			DCListShow(&mylist);
//			break;
//		case 13:DCListClear(&mylist); break;
//		case 14:DCListSort(&mylist); DCListShow(&mylist); break;
//		case 0:printf("�ټ�!\n"); DCListDestroy(&mylist); quit = 1;
//			break;
//		default:printf("�������!����������#"); break;
//		}
//		system("pause");
//		system("cls");
//	}
//	return 0;
//}