//#include "SListNode.h"

//int main()
//{
//	SList mylist;
//	SListInit(&mylist);
//	int choice;
//	int quit = 0;
//	int pos = 0;
//	ElemType item;
//	while (!quit) {
//		SListMenu();
//		printf("���������ѡ��#");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			printf("Slist����Ϊ[%d]\n", SListLength(&mylist)); 
//			break;
//		case 2:
//			printf("��������Ҫ���������(-1����)#");
//			while (scanf("%d", &item), item != -1) {
//				SListPushFront(&mylist, item);
//			}
//			SListShow(&mylist); break;
//		case 3:
//			printf("��������Ҫ���������(-1����)#");
//			while (scanf("%d", &item), item != -1) {
//				SListPushBack(&mylist, item);
//			}
//			SListShow(&mylist);
//			break;
//		case 4:
//			printf("��������Ҫ���������#");
//			scanf("%d", &item);
//			SListPushByVal(&mylist, item);
//			SListShow(&mylist);
//			break; SListShow(&mylist);break;
//		case 5:SListShow(&mylist); break;
//		case 6:SListPopFront(&mylist); SListShow(&mylist); break;
//		case 7:SListPopBack(&mylist); SListShow(&mylist); break;
//		case 8:
//			printf("��������Ҫɾ��������#");
//			scanf("%d", &item);
//			SListDeleteByVal(&mylist, item);
//			SListShow(&mylist);
//			break;
//		case 9:
//			printf("��������Ҫ���ҵ�����)#");
//			scanf("%d", &item);
//			SListNode* p = SListFind(&mylist, item);
//			if (NULL != p) {
//				printf("[%d]������洢��ַΪ[%p]\n", item, &p);
//			}
//			else
//				printf("[%d]��������SList��!\n", item);
//			break;
//		case 10:SlistDestroy(&mylist); break;
//		case 11:SListReverse(&mylist); SListShow(&mylist); break;
//		case 12:
//			printf("��������Ҫȫ��ɾ����ͬһ����)#");
//			scanf("%d", &item);
//			SListPopAllSame(&mylist, item);
//			break;
//		case 13:
//			if (SListLength(&mylist) == 0) {
//				printf("�ձ�!��ʹ������ѡ���������!\n");
//				break;
//			}
//			printf("��������Ҫ�����λ�ü�����(1-%d)#",SListLength(&mylist));
//			scanf("%d %d", &pos, &item);
//			SListPushPos(&mylist, pos,item);
//			SListShow(&mylist);
//			break;
//		case 14:
//			if (SListLength(&mylist) == 0) {
//				printf("�ձ�!\n");
//				break;
//			}
//			printf("��������Ҫɾ����λ��(1-%d)#", SListLength(&mylist));
//			scanf("%d", &pos);
//			SListPopPos(&mylist, pos);
//			break;
//		case 15:SListClear(&mylist); break;
//		case 16:SListSort(&mylist); SListShow(&mylist); break;
//		case 0:printf("�ټ�!\n");SlistDestroy(&mylist); quit = 1; break;
//		default:printf("�������!����������#"); break;
//		}
//	system("pause");
//	system("cls");
//	}
//	return 0;
//}

