#include "GuessNum.h"
void GuessNum()
{
	srand((unsigned int)time(NULL));//��ʱ��Ϊ���Ӳ��������
	int N = rand() % 100 + 1; // ����������ķ�Χ��[0,100]
	int input = 0;
	int flag = 1;
	while (flag) {
		printf("���������µ�����#");
		scanf("%d", &input);
		if (input > N) {
			printf("�´���!\n");
		}
		else if (input < N) {
			printf("��С��Ŷ!\n");
		}
		else {
			system("cls");
			flag = 0;
		}
	}
	printf("��ϲ���¶���!���!\n");
	Sleep(1500);
}