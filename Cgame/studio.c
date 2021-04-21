#include "studio.h"

void Login()
{
	int try_times = 3, fail_time = 0;//密码输入次数，登录失败次数
	int flag = 1;
	char user[64];
	char pwd[64];
	while (flag) {
		printf("请输入账号# ");
		scanf("%s", user);
		printf("请输入密码# ");
		scanf("%s", pwd);
		if (strcmp(user, User) == 0 && strcmp(pwd, Pwd) == 0) {
			printf("登录成功\n");
			flag = 0;
			Sleep(Delay_time / 3);
			system("cls"); //清屏
		}
		else {
			system("cls"); //清屏
			try_times--;
			printf("你的尝试机会还有%d次\n", try_times);
			if (!try_times) {
				Sleep(Delay_time / 3);
				system("cls"); //清屏
				fail_time++; //登录失败次数越多，等待时间越长
				CountDown(fail_time);
				try_times = 3;
			}
		}
	}
}

void menu()
{
	printf("################################\n");
	printf("######### 1.猜数字 #############\n");
	printf("######### 2.三子棋 #############\n");
	printf("######### 3.扫雷   #############\n");
	printf("######### 4.待续   #############\n");
	printf("######### 0.退出   #############\n");
	printf("################################\n");
	printf("请输入您的选择# ");
}

void CountDown(int fail_cnt)
{
	int i = (int)(Delay_time * pow(fail_cnt, 2.0)) / 1000;
	for (; i >= 0; i--) {
		if (i < 60) {
			printf("距离下次尝试还有%2dS\r", i);
		}
		else if (i < 3600) {
			printf("距离下次尝试还有%2dM%2dS\r", i / 60, i % 60);
		}
		else {
			printf("打扰了,别试了，我没想过你一小时还没想起账号及密码!\n");
			printf("等我学了数据库再给你设置重置密码的功能!\n");
		}
		Sleep(Delay_time / 3);//假象倒计时
		if (i == 0) {
			printf("\n");
		}
	}
}