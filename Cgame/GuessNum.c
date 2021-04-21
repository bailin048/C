#include "GuessNum.h"
void GuessNum()
{
	srand((unsigned int)time(NULL));//以时间为种子产生随机数
	int N = rand() % 100 + 1; // 控制随机数的范围在[0,100]
	int input = 0;
	int flag = 1;
	while (flag) {
		printf("请输入您猜的数字#");
		scanf("%d", &input);
		if (input > N) {
			printf("猜大啦!\n");
		}
		else if (input < N) {
			printf("猜小了哦!\n");
		}
		else {
			system("cls");
			flag = 0;
		}
	}
	printf("恭喜您猜对啦!真棒!\n");
	Sleep(1500);
}