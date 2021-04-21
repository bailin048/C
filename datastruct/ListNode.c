//#include "ListNode.h"

//int main()
//{
//	ListNode* List = ListCreate();
//	LTDataType item = 0;
//	int choice = 0;
//	int quit = 1;
//	while (quit) {
//		ListMenu();
//		printf("请输入您的选择#\n");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			printf("请输入宁想插入的数据（-1结束输入）#");
//			while (scanf("%d", &item), item != -1) {
//				ListPushBack(List,item);
//			}
//			ListPrint(List);
//			break;
//		case 2:
//			printf("请输入宁想插入的数据（-1结束输入）#");
//			while (scanf("%d", &item), item != -1) {
//				ListPushFront(List, item);
//			}
//			ListPrint(List);
//			break;
//		case 3:ListPopBack(List); ListPrint(List); break;
//		case 4:ListPopFront(List); ListPrint(List); break;
//		case 5:
//			printf("请输入宁想插入在谁之前？（目前仅支持插在重复出现的第一个数字之前且该操作会使链表长度不能正常计数\n");
//			ListPrint(List);
//			printf("插在谁前面?#");
//			scanf("%d", &item);
//			ListNode* p = ListFind(List, item);
//			printf("宁想插入谁？#");
//			scanf("%d", &item);
//			ListInsert(p,item);
//			ListPrint(List);
//			break;
//		case 6:
//			printf("请输入宁想删除谁？（目前仅支持删除重复出现的第一个数字且该操作会使链表长度不能正常计数\n");
//			ListPrint(List);
//			printf("请输入数字#");
//			scanf("%d", &item);
//			p = ListFind(List, item);
//			ListErase(p);
//			ListPrint(List);
//			break;
//		case 7:ListPrint(List); break;
//		case 8: ListDestory(List); break;
//		case 0:printf("再见!\n"); quit = 0; break;
//		default:printf("宁的输入有误!请重新输入!\n");  break;
//		}
//		system("pause");
//		system("cls");
//	}
//}