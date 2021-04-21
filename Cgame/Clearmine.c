#include "Clearmine.h"

void SetMine(char arr[][Size + 2])
{
	int cnt = DeathNum;  
	while (cnt) {
		int x = rand() % Size + 1;
		int y = rand() % Size + 1;
		if (arr[x][y] == ' ') {  //��ǰλ�ÿ��Բ���
			arr[x][y] = '#';
		}
		cnt--;
	}
}

void table(char arr[][Size + 2])
{	//Ҫ�ÿ�����壺��or����
	printf("   |");
	for (int i = 0; i < Size; i++) {
		printf("%2d |", i + 1);
	}
	printf("\n--------------------------------------------\n");
	for (int i = 1; i <= Size; i++) {
		printf("%2d |", i);
		for (int j = 1; j <= Size; j++) {
			printf(" %c |", arr[i][j]);
		}
		printf("\n--------------------------------------------\n");
	}
}

void CountD(char arr[][Size + 2], char arr1[][Size + 2], int x, int y)
{
	int k = 0;  
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (arr[i][j] == '#') {  
				k++;   //������������1
			}
		}
	}
	arr1[x][y] = k + '0';  //���׵���Ŀ���������Ӧλ��
}

void ClearMine()
{
	srand((unsigned long)time(NULL));  //�����������
	char showboard[Size + 2][Size + 2];  //��壺չʾ������
	char mineboard[Size + 2][Size + 2];  //����/���׵����
	memset(showboard, '*', sizeof(showboard));  //��������ʼ��
	memset(mineboard, ' ', sizeof(mineboard));  //�װ������ʼ��
	SetMine(mineboard);    //����
	int cnt = Size * Size - DeathNum;    //���ð�ȫλ�õ���Ŀ��������Ϸѭ��
	int x = 0,y = 0;
	do {
		system("cls");     //�����ʾ����
		table(showboard);  //չʾ���
		printf("��������ɨλ��# ");
		scanf("%d %d", &x, &y);
		if (x < 1 || x > Size || y < 1 || y > Size) {
			printf("����λ��Խ�磬����������!\n");
			continue;
		}
		if (showboard[x][y] != '*') {
			printf("��λ���Ѿ����ų�!\n");
			continue;
		}
		if (mineboard[x][y] == '#') {  //���׼�����
			break;
		}
		CountD(mineboard, showboard, x, y);  //��������λ�ø����׵���Ŀ�����������
		cnt--;  //��ȫλ�ü�1
	} while (cnt >= 0);
	if (cnt > 0) {   //cnt>0��˵������ѭ��ʱ��ȫλ�ò�û�б����ֻ꣬��һ��ԭ�򣺲���
		system("cls");
		printf("�㱻ը����!��ղ������λ��Ϊ��%d,%d��\n",x,y);
		table(mineboard);
	}
	else {
		printf("��ϲ����ͨ����Ϸ!\n");
	}
	Sleep(1000);  
}

