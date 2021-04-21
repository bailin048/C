#include "studio.h"

int main()
{
	Login(); //登录函数
	int flag = 1;
	while (flag) {
		menu();
		int choice = 1;
		scanf("%d", &choice);
		system("cls");
		switch (choice) {
			case 0: {
				flag = 0;
				printf("再见!\n");
				break;
			}
			case 1: {
				GuessNum();
				system("cls");
				break;
			}
			case 2: {
				ThreeChess();
				system("cls");
				break;
			}
			case 3: {
				ClearMine();
				Sleep(5000);
				system("cls");
				break;
			}
			case 4: {
				printf("待续\n");
				break;
			}
			default: {
				printf("三子棋\n");
				break;
			}
		}
	}
	return 0;
}