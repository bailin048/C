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
//		printf("请输入选择#");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:LengthofList(&mylist); break;
//		case 2:CapacityofList(&mylist); break;
//		case 3:
//			printf("请输入想要插入的数据(-1结束)#");
//			while (scanf("%d", &item), item != -1) {
//				SeqListHeadInsert(&mylist, item);
//			}
//			SeqListShow(&mylist);
//			break;
//		case 4:
//			printf("请输入想要插入的数据(-1结束)#");
//			while (scanf("%d", &item), item != -1) {
//				SeqListTailInsert(&mylist, item);
//			}
//			SeqListShow(&mylist);
//			break;
//		case 5:
//			printf("请输入插入位置及元素#");
//			scanf("%d %d", &pos, &item);
//			SeqListInsertPos(&mylist, pos, item);
//			SeqListShow(&mylist);
//			break;
//		case 6:
//			printf("请输入插入的元素#");
//			scanf("%d", &item);
//			SeqListInsertValue(&mylist, item);
//			SeqListShow(&mylist);
//			break; break;
//		case 7:SeqListShow(&mylist); break;
//		case 8:SeqListHeadPop(&mylist); SeqListShow(&mylist); break;
//		case 9:SeqListTailPop(&mylist); SeqListShow(&mylist); break;
//		case 10:
//			printf("请输入想要删除的值#");
//			scanf("%d", &item);
//			SeqListDelValue(&mylist, item);
//			SeqListShow(&mylist);
//			break;
//		case 11:
//			printf("请输入想要删除的索引#");
//			scanf("%d", &pos);
//			SeqListDelPos(&mylist, pos);
//			break;
//		case 12:
//			printf("请输入想要查看的索引#");
//			scanf("%d", &pos);
//			SeqListCheekPos(&mylist, pos);
//			break;
//		case 13:
//			printf("请输入想要查找的值#");
//			scanf("%d", &item);
//			int index = SeqListSeekValue(&mylist, item);
//			if (index == -1) {
//				printf("[%d]不存在于SeqList\n", item);
//			}
//			else {
//				printf("[%d]在SeqList中索引为[%d]\n", item, index);
//			}
//			break;
//		case 14:SeqListSort(&mylist); SeqListShow(&mylist); break;
//		case 15:SeqListReverse(&mylist); SeqListShow(&mylist); break;
//		case 16:
//			printf("请输入想要删除的元素#");
//			scanf("%d", &item);
//			SeqListDelAllSame(&mylist, item);
//			SeqListShow(&mylist);
//			break;
//		case 17:SeqListClear(&mylist); break;
//		case 18:SeqListDestroy(&mylist); break;
//		case 19:
//			printf("请输入想要查找的值#");
//			scanf("%d", &item);
//			index = SeqListBiSeekValue(&mylist, item);
//			if (index == -1) {
//				printf("[%d]不存在于SeqList\n", item);
//			}
//			else {
//				printf("[%d]在SeqList中索引为[%d]\n", item, index);
//			}
//			SeqListShow(&mylist);
//			break;
//		case 0:SeqListDestroy(&mylist); printf("再见!\n"); exit = 0; break;//退出释放动态空间
//		default:printf("输入错误!请重新输入#"); break;
//		}
//		system("pause");
//		system("cls");
//	}
//	return 0;
//}
