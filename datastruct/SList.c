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
//		printf("请输入您的选择#\n");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			printf("请输入宁想插入的数据（-1结束输入）#");
//			while (scanf("%d", &item), item != -1) {
//				PSListPushBack(phead, item);
//			}
//			PSListPrint(List);
//			break;
//		case 2:
//			printf("请输入宁想插入的数据（-1结束输入）#");
//			while (scanf("%d", &item), item != -1) {
//				PSListPushFront(phead, item);
//			}
//			PSListPrint(List);
//			break;
//		case 3:PSListPopBack(phead); PSListPrint(List); break;
//		case 4:PSListPopFront(phead); PSListPrint(List); break;
//		case 5:
//			printf("请输入宁想插入在谁之后？（目前仅支持插在重复出现的第一个数字之后\n");
//			PSListPrint(List);
//			printf("插在谁后面?#");
//			scanf("%d", &item);
//			SListNode* p = PSListFind(List, item);
//			printf("宁想插入谁？#");
//			scanf("%d", &item);
//			PSListInsertAfter(p, item);
//			PSListPrint(List);
//			break;
//		case 6:
//			printf("请输入宁想删除谁之后的元素？(删首尾请选择其他方式)\n");
//			PSListPrint(List);
//			printf("请输入数字#");
//			scanf("%d", &item);
//			p = PSListFind(List, item);
//			PSListEraseAfter(p);
//			PSListPrint(List);
//			break;
//		case 7:PSListPrint(List); break;
//		case 8:PSListDestory(List); break;
//		case 0:printf("再见!\n"); quit = 0; break;
//		default:printf("宁的输入有误!请重新输入!\n");  break;
//		}
//		system("pause");
//		system("cls");
//	}
//}