//#include "ListNode.h"

//int main()
//{
//	ListNode* List = ListCreate();
//	LTDataType item = 0;
//	int choice = 0;
//	int quit = 1;
//	while (quit) {
//		ListMenu();
//		printf("����������ѡ��#\n");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			printf("�����������������ݣ�-1�������룩#");
//			while (scanf("%d", &item), item != -1) {
//				ListPushBack(List,item);
//			}
//			ListPrint(List);
//			break;
//		case 2:
//			printf("�����������������ݣ�-1�������룩#");
//			while (scanf("%d", &item), item != -1) {
//				ListPushFront(List, item);
//			}
//			ListPrint(List);
//			break;
//		case 3:ListPopBack(List); ListPrint(List); break;
//		case 4:ListPopFront(List); ListPrint(List); break;
//		case 5:
//			printf("���������������˭֮ǰ����Ŀǰ��֧�ֲ����ظ����ֵĵ�һ������֮ǰ�Ҹò�����ʹ�����Ȳ�����������\n");
//			ListPrint(List);
//			printf("����˭ǰ��?#");
//			scanf("%d", &item);
//			ListNode* p = ListFind(List, item);
//			printf("�������˭��#");
//			scanf("%d", &item);
//			ListInsert(p,item);
//			ListPrint(List);
//			break;
//		case 6:
//			printf("����������ɾ��˭����Ŀǰ��֧��ɾ���ظ����ֵĵ�һ�������Ҹò�����ʹ�����Ȳ�����������\n");
//			ListPrint(List);
//			printf("����������#");
//			scanf("%d", &item);
//			p = ListFind(List, item);
//			ListErase(p);
//			ListPrint(List);
//			break;
//		case 7:ListPrint(List); break;
//		case 8: ListDestory(List); break;
//		case 0:printf("�ټ�!\n"); quit = 0; break;
//		default:printf("������������!����������!\n");  break;
//		}
//		system("pause");
//		system("cls");
//	}
//}