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
//		printf("请输入你的选择#");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			printf("DClist长度为[%d]\n", DCListLength(&mylist));
//			break;
//		case 2:
//			printf("请输入想要插入的数据(-1结束)#");
//			while (scanf("%d", &item), item != -1) {
//				DCListPushFront(&mylist, item);
//			}
//			DCListShow(&mylist); break;
//		case 3:
//			printf("请输入想要插入的数据(-1结束)#");
//			while (scanf("%d", &item), item != -1) {
//				DCListPushBack(&mylist, item);
//			}
//			DCListShow(&mylist);
//			break;
//		case 4:
//			printf("请输入想要插入的数据#");
//			scanf("%d", &item);
//			DCListPushByVal(&mylist, item);
//		    DCListShow(&mylist); break;
//			case 5:DCListShow(&mylist); break;
//			case 6:DCListPopFront(&mylist); DCListShow(&mylist); break;
//			case 7:DCListPopBack(&mylist); DCListShow(&mylist); break;
//			case 8:
//				printf("请输入想要删除的数据#");
//				scanf("%d", &item);
//				DCListPopByVal(&mylist, item);
//				DCListShow(&mylist);
//				break;
//		case 9:
//			printf("请输入想要查找的数据)#");
//			scanf("%d", &item);
//			DCListNode* p = DCListFind(&mylist, item);
//			if (NULL != p) {
//				printf("[%d]的物理存储地址为[%p]\n", item, &p);
//			}
//			else
//				printf("[%d]不存在于SList中!\n", item);
//			break;
//			case 10:DCListDestroy(&mylist); break;
//		case 11:DCListReverse(&mylist); DCListShow(&mylist); 
//		break;
//		case 12:
//			printf("请输入想要全部删除的同一数据)#");
//			scanf("%d", &item);
//			DCListPopAllSame(&mylist, item);
//			DCListShow(&mylist);
//			break;
//		case 13:DCListClear(&mylist); break;
//		case 14:DCListSort(&mylist); DCListShow(&mylist); break;
//		case 0:printf("再见!\n"); DCListDestroy(&mylist); quit = 1;
//			break;
//		default:printf("输入错误!请重新输入#"); break;
//		}
//		system("pause");
//		system("cls");
//	}
//	return 0;
//}