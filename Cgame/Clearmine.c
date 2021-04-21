#include "Clearmine.h"

void SetMine(char arr[][Size + 2])
{
	int cnt = DeathNum;  
	while (cnt) {
		int x = rand() % Size + 1;
		int y = rand() % Size + 1;
		if (arr[x][y] == ' ') {  //当前位置可以布雷
			arr[x][y] = '#';
		}
		cnt--;
	}
}

void table(char arr[][Size + 2])
{	//要好看的面板：试or计算
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
				k++;   //发现雷则自增1
			}
		}
	}
	arr1[x][y] = k + '0';  //将雷的数目填入面板相应位置
}

void ClearMine()
{
	srand((unsigned long)time(NULL));  //设置随机种子
	char showboard[Size + 2][Size + 2];  //面板：展示的数组
	char mineboard[Size + 2][Size + 2];  //布雷/检雷的面板
	memset(showboard, '*', sizeof(showboard));  //面板数组初始化
	memset(mineboard, ' ', sizeof(mineboard));  //雷板数组初始化
	SetMine(mineboard);    //布雷
	int cnt = Size * Size - DeathNum;    //设置安全位置的数目，控制游戏循环
	int x = 0,y = 0;
	do {
		system("cls");     //清空显示界面
		table(showboard);  //展示面板
		printf("请输入清扫位置# ");
		scanf("%d %d", &x, &y);
		if (x < 1 || x > Size || y < 1 || y > Size) {
			printf("输入位置越界，请重新输入!\n");
			continue;
		}
		if (showboard[x][y] != '*') {
			printf("该位置已经被排除!\n");
			continue;
		}
		if (mineboard[x][y] == '#') {  //踩雷即跳出
			break;
		}
		CountD(mineboard, showboard, x, y);  //计算输入位置附近雷的数目，并填入面板
		cnt--;  //安全位置减1
	} while (cnt >= 0);
	if (cnt > 0) {   //cnt>0则说明跳出循环时安全位置并没有被找完，只有一个原因：踩雷
		system("cls");
		printf("你被炸死了!你刚才输入的位置为（%d,%d）\n",x,y);
		table(mineboard);
	}
	else {
		printf("恭喜，你通过游戏!\n");
	}
	Sleep(1000);  
}

