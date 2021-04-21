#include "Threechess.h"

void Board(char arr[][COL])
{
	printf("  | 1 | 2 | 3 |\n");
	for (int i = 0; i < ROW; i++) {
		printf("%d |", i + 1);
		for (int j = 0; j < COL; j++) {
			printf(" %c |", arr[i][j]);
		}
		printf("\n");
	}
}
void Player(char arr[][COL])
{
	int x = 1;
	int y = 1;
	printf("请输入落子位置# ");
	scanf("%d %d", &x, &y);
	while (x > ROW || x < 1 || \
		y > COL || y < 1 || \
		arr[x - 1][y - 1] != ' ') {
		printf("落子位置错误！请重新输入落子位置# ");
		scanf("%d %d", &x, &y);
	}
	system("cls");
	arr[x - 1][y - 1] = Perchess;
}
void Comp(char arr[][COL])
{
	int x = 0;
	int y = 0;
	do {
		x = rand() % ROW;
		y = rand() % COL;
	} while (arr[x][y] != ' ');
	arr[x][y] = Comchess;
}
char Judge(char arr[][COL])
{
	for (int i = 0; i < ROW; i++) {
		if (arr[i][0] == arr[i][1] && \
			arr[i][1] == arr[i][2] && \
			arr[i][0] != ' ') {
			return arr[i][0];
		}
	}
	for (int i = 0; i < COL; i++) {
		if (arr[0][i] == arr[1][i] && \
			arr[1][i] == arr[2][i] && \
			arr[0][i] != ' ') {
			return arr[0][i];
		}
	}
	//斜线判决没有自适应，改变棋盘大小会出错！待改——循环解决
	if (arr[0][0] == arr[1][1] && \
		arr[1][1] == arr[2][2] && \
		arr[0][0] != ' ') {
		return arr[0][0];
	}
	if (arr[0][2] == arr[1][1] && \
		arr[1][1] == arr[2][0] && \
		arr[1][1] != ' ') {
		return arr[1][1];
	}
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (arr[i][j] == ' ') {
				return 'N';
			}
		}
	}
	return Peace;
}
int GuessFist()
{

	int numP = 0;
	int numC = 0;
	printf("说明：输入(1-5)的数字决定谁先下，谁大谁先下，一样大则重新输入\n");
	while (numC == numP) {
		printf("请输入你的数字#");
		scanf("%d", &numP);
		numC = rand() % 5 + 1;
		printf("你的数字：%d,电脑的数字：%d\n", numP, numC);
		if (numP > numC) {
			printf("你赢了，你先走\n");
		}
		else if (numC > numP) {
			printf("电脑赢了，电脑先走\n");
		}
		else {}
		if (numC != numP) {
			return numP - numC;
		}
	}
}
void ThreeChess()
{
	srand((unsigned long)time(NULL));
	char chessboard[ROW][COL];
	memset(chessboard, ' ', sizeof(chessboard));
	char win = '\0';
	int seq = 0;
	seq = GuessFist();
	Sleep(1500);
	system("cls");
	if (seq < 0) {
		goto Start;
	}
	while (1) {
		Board(chessboard);
		Player(chessboard);
		win = Judge(chessboard);
		if (win != 'N') {
			break;
		}
	Start:	Comp(chessboard);
		win = Judge(chessboard);
		if (win != 'N') {
			break;
		}
	}
	switch (win) {
	case Perchess:
		printf("恭喜你赢啦！\n");
		break;
	case Comchess:
		printf("很遗憾！你输了！\n");
		break;
	case Peace:
		printf("平局！\n");
		break;
	default:break;
	}
	Board(chessboard);
	Sleep(2000);
	system("cls");
}