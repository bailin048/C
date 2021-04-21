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
//		printf("请输入你的选择#");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			printf("Slist长度为[%d]\n", SListLength(&mylist)); 
//			break;
//		case 2:
//			printf("请输入想要插入的数据(-1结束)#");
//			while (scanf("%d", &item), item != -1) {
//				SListPushFront(&mylist, item);
//			}
//			SListShow(&mylist); break;
//		case 3:
//			printf("请输入想要插入的数据(-1结束)#");
//			while (scanf("%d", &item), item != -1) {
//				SListPushBack(&mylist, item);
//			}
//			SListShow(&mylist);
//			break;
//		case 4:
//			printf("请输入想要插入的数据#");
//			scanf("%d", &item);
//			SListPushByVal(&mylist, item);
//			SListShow(&mylist);
//			break; SListShow(&mylist);break;
//		case 5:SListShow(&mylist); break;
//		case 6:SListPopFront(&mylist); SListShow(&mylist); break;
//		case 7:SListPopBack(&mylist); SListShow(&mylist); break;
//		case 8:
//			printf("请输入想要删除的数据#");
//			scanf("%d", &item);
//			SListDeleteByVal(&mylist, item);
//			SListShow(&mylist);
//			break;
//		case 9:
//			printf("请输入想要查找的数据)#");
//			scanf("%d", &item);
//			SListNode* p = SListFind(&mylist, item);
//			if (NULL != p) {
//				printf("[%d]的物理存储地址为[%p]\n", item, &p);
//			}
//			else
//				printf("[%d]不存在于SList中!\n", item);
//			break;
//		case 10:SlistDestroy(&mylist); break;
//		case 11:SListReverse(&mylist); SListShow(&mylist); break;
//		case 12:
//			printf("请输入想要全部删除的同一数据)#");
//			scanf("%d", &item);
//			SListPopAllSame(&mylist, item);
//			break;
//		case 13:
//			if (SListLength(&mylist) == 0) {
//				printf("空表!请使用其他选项加入数据!\n");
//				break;
//			}
//			printf("请输入想要插入的位置及数据(1-%d)#",SListLength(&mylist));
//			scanf("%d %d", &pos, &item);
//			SListPushPos(&mylist, pos,item);
//			SListShow(&mylist);
//			break;
//		case 14:
//			if (SListLength(&mylist) == 0) {
//				printf("空表!\n");
//				break;
//			}
//			printf("请输入想要删除的位置(1-%d)#", SListLength(&mylist));
//			scanf("%d", &pos);
//			SListPopPos(&mylist, pos);
//			break;
//		case 15:SListClear(&mylist); break;
//		case 16:SListSort(&mylist); SListShow(&mylist); break;
//		case 0:printf("再见!\n");SlistDestroy(&mylist); quit = 1; break;
//		default:printf("输入错误!请重新输入#"); break;
//		}
//	system("pause");
//	system("cls");
//	}
//	return 0;
//}

