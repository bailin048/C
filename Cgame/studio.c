#include "studio.h"

void Login()
{
	int try_times = 3, fail_time = 0;//���������������¼ʧ�ܴ���
	int flag = 1;
	char user[64];
	char pwd[64];
	while (flag) {
		printf("�������˺�# ");
		scanf("%s", user);
		printf("����������# ");
		scanf("%s", pwd);
		if (strcmp(user, User) == 0 && strcmp(pwd, Pwd) == 0) {
			printf("��¼�ɹ�\n");
			flag = 0;
			Sleep(Delay_time / 3);
			system("cls"); //����
		}
		else {
			system("cls"); //����
			try_times--;
			printf("��ĳ��Ի��ỹ��%d��\n", try_times);
			if (!try_times) {
				Sleep(Delay_time / 3);
				system("cls"); //����
				fail_time++; //��¼ʧ�ܴ���Խ�࣬�ȴ�ʱ��Խ��
				CountDown(fail_time);
				try_times = 3;
			}
		}
	}
}

void menu()
{
	printf("################################\n");
	printf("######### 1.������ #############\n");
	printf("######### 2.������ #############\n");
	printf("######### 3.ɨ��   #############\n");
	printf("######### 4.����   #############\n");
	printf("######### 0.�˳�   #############\n");
	printf("################################\n");
	printf("����������ѡ��# ");
}

void CountDown(int fail_cnt)
{
	int i = (int)(Delay_time * pow(fail_cnt, 2.0)) / 1000;
	for (; i >= 0; i--) {
		if (i < 60) {
			printf("�����´γ��Ի���%2dS\r", i);
		}
		else if (i < 3600) {
			printf("�����´γ��Ի���%2dM%2dS\r", i / 60, i % 60);
		}
		else {
			printf("������,�����ˣ���û�����һСʱ��û�����˺ż�����!\n");
			printf("����ѧ�����ݿ��ٸ���������������Ĺ���!\n");
		}
		Sleep(Delay_time / 3);//���󵹼�ʱ
		if (i == 0) {
			printf("\n");
		}
	}
}