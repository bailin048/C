#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)


int main() 
{
    //打印金字塔
    /*int row = 0;
    while (scanf("%d", &row)!=EOF) {
        for (int i = 0; i < row; i++) {
            int k = 0;
            for (int j = 0; (j <= 2 * row - 1) && (k < i + 1); j++) {
                if (j < row - 1 - i) {
                    printf(" ");
                }
                else {
                    printf("* ");
                    k += 1;
                }
            }
            printf("\n");
        }*/
    //简单计算器
    /*double a = 0.0, b = 0.0;
    char sym = '0';
    while (scanf("%lf%c%lf", &a, &sym, &b) != EOF) {
        switch (sym) {
        case '+': printf("%.4f+%.4f=%.4f\n", a, b, a + b); break;
        case '-': printf("%.4f-%.4f=%.4f\n", a, b, a - b); break;
        case '*': printf("%.4f*%.4f=%.4f\n", a, b, a * b); break;
        case '/':
            if (b == 0.0) {
                printf("Wrong!Division by zero!\n");
                break;
            }
            printf("%.4f/%.4f=%.4f\n", a, b, a / b); break;
        default: printf("Invalid operation!\n"); break;
        }
    }*/
    //输出某年每月的天数
    /*int year, month;
    int daynum[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    while (scanf("%d %d", &year, &month) != EOF) {
        int leapyear = (!(year % 400)) || (year % 100 && !(year % 4));
        if (2 == month && 1 == leapyear) {
            printf("%d\n", daynum[month - 1] + 1);
        }
        else {
            printf("%d\n", daynum[month - 1]);
        }
    */}
    //计算二次方程根
    /*double a = 0.0, b = 0.0, c = 0.0, r = 0.0, i = 0.0;
    double delta = 0.0;
    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
        delta = b * b - 4 * a * c;
        r = -b / (2 * a);
        i = (delta < 0 ? sqrt(-delta) : sqrt(delta)) / (2 * a);
        if (0 == a) {
            printf("Not quadratic equation\n");
        }
        else {
            if (delta > 0) {
                printf("x1=%.2f;x2=%.2f\n", r - i, r + i);
            }
            else if (delta < 0) {
                if (b == 0.0) {
                    printf("x1=0.00-%.2fi;x2=0.00+%.2fi\n", i, i);
                }
                else {
                    printf("x1=%.2f-%.2fi;x2=%.2f+%.2fi\n", r, i, r, i);
                }
            }
            else {
                printf("x1=x2=%.2f\n", r);
            }
        }
    }*/
	//判断输入是否为字母
	//char c = '0';
	//while ((scanf("%c",&c)) != EOF) {
	//	getchar();
	//	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))) {
	//		printf("%c is an alphabet.\n",c);
	//	}
	//	else {
	//		printf("%c is not an alphabet.\n", c);
	//	}
	//}
	return 0;
}





























