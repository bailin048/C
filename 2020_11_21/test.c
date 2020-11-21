#include <stdio.h>
/// <function>打印杨辉三角前n行（目前）
/// 1
/// 1 1
/// 1 2 1
/// 1 3 3 1
/// ……
/// <param name="n"></int打印行数> warnong：n不得大于100，否则需要调整数组元素数目
void YHTriangle(int n)
{ 
	int old[100] = { 0,1 }; //定义两个100元素整型，用于杨辉三角两行的存储与计算
	int new[100] = { 0 }; // 两个数组0索引值保持0永远不变，易于使任意位置的元素计算方法一样
	int i = 0, j = 1;
	printf("1\n"); //打印第一行 1
	for (i = 2; i <= n; i++) { //从第二行再开始计算
		for (j = 1; j <= i ; j++) { 
			new[j] = old[j] + old[j - 1]; //new的第j个由old[j]+old[j-1]计算得来
			printf("%d ", new[j]);  //打印当前数字
		}
		printf("\n"); //当前行已打印完，换行
		for (j = 1; j <= i; j++) { //更新old，为下一行计算做准备
			old[j] = new[j];
		}
	}
}

int main()
{
	for (char killer = 'A'; killer <= 'D'; killer++) {
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3) {
			printf("%c\n",killer);
		}
	}
}