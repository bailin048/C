//#include "SeqList.h"

//int main()
//{
//	SeqList mylist;
//	SeqListInit(&mylist);
//	int choice;
//	int exit = 1;
//	int pos = 0;
//	ElemType item;
//	while (exit) {
//		SeqListMenu();
//		printf("������ѡ��#");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:LengthofList(&mylist); break;
//		case 2:CapacityofList(&mylist); break;
//		case 3:
//			printf("��������Ҫ���������(-1����)#");
//			while (scanf("%d", &item), item != -1) {
//				SeqListHeadInsert(&mylist, item);
//			}
//			SeqListShow(&mylist);
//			break;
//		case 4:
//			printf("��������Ҫ���������(-1����)#");
//			while (scanf("%d", &item), item != -1) {
//				SeqListTailInsert(&mylist, item);
//			}
//			SeqListShow(&mylist);
//			break;
//		case 5:
//			printf("���������λ�ü�Ԫ��#");
//			scanf("%d %d", &pos, &item);
//			SeqListInsertPos(&mylist, pos, item);
//			SeqListShow(&mylist);
//			break;
//		case 6:
//			printf("����������Ԫ��#");
//			scanf("%d", &item);
//			SeqListInsertValue(&mylist, item);
//			SeqListShow(&mylist);
//			break; break;
//		case 7:SeqListShow(&mylist); break;
//		case 8:SeqListHeadPop(&mylist); SeqListShow(&mylist); break;
//		case 9:SeqListTailPop(&mylist); SeqListShow(&mylist); break;
//		case 10:
//			printf("��������Ҫɾ����ֵ#");
//			scanf("%d", &item);
//			SeqListDelValue(&mylist, item);
//			SeqListShow(&mylist);
//			break;
//		case 11:
//			printf("��������Ҫɾ��������#");
//			scanf("%d", &pos);
//			SeqListDelPos(&mylist, pos);
//			break;
//		case 12:
//			printf("��������Ҫ�鿴������#");
//			scanf("%d", &pos);
//			SeqListCheekPos(&mylist, pos);
//			break;
//		case 13:
//			printf("��������Ҫ���ҵ�ֵ#");
//			scanf("%d", &item);
//			int index = SeqListSeekValue(&mylist, item);
//			if (index == -1) {
//				printf("[%d]��������SeqList\n", item);
//			}
//			else {
//				printf("[%d]��SeqList������Ϊ[%d]\n", item, index);
//			}
//			break;
//		case 14:SeqListSort(&mylist); SeqListShow(&mylist); break;
//		case 15:SeqListReverse(&mylist); SeqListShow(&mylist); break;
//		case 16:
//			printf("��������Ҫɾ����Ԫ��#");
//			scanf("%d", &item);
//			SeqListDelAllSame(&mylist, item);
//			SeqListShow(&mylist);
//			break;
//		case 17:SeqListClear(&mylist); break;
//		case 18:SeqListDestroy(&mylist); break;
//		case 19:
//			printf("��������Ҫ���ҵ�ֵ#");
//			scanf("%d", &item);
//			index = SeqListBiSeekValue(&mylist, item);
//			if (index == -1) {
//				printf("[%d]��������SeqList\n", item);
//			}
//			else {
//				printf("[%d]��SeqList������Ϊ[%d]\n", item, index);
//			}
//			SeqListShow(&mylist);
//			break;
//		case 0:SeqListDestroy(&mylist); printf("�ټ�!\n"); exit = 0; break;//�˳��ͷŶ�̬�ռ�
//		default:printf("�������!����������#"); break;
//		}
//		system("pause");
//		system("cls");
//	}
//	return 0;
//}
