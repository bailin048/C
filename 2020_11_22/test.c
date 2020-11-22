#include <stdio.h>
#pragma warning(disable:4996)

//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
void SortChampion()
{
    int a, b, c, d, e;
    for (a = 1; a <= 5; a++)
    {
        for (b = 1; b <= 5; b++)
        {
            for (c = 1; c <= 5; c++)
            {
                for (d = 1; d <= 5; d++)
                {
                    for (e = 1; e <= 5; e++)
                    {
                        if ((b == 3) + (a == 3) == 1 &&
                            (b == 2) + (e == 4) == 1 &&
                            (c == 1) + (d == 2) == 1 &&
                            (c == 5) + (d == 3) == 1 &&
                            (e == 4) + (a == 1) == 1){
                            printf("A=%d, B=%d, C=%d, D=%d, E=%d\n",a, b, c, d, e);
                        }
                    }
                }
            }
        }
    }
}

/// <summary>
/// 判断计算机大小端模式
/// </summary>
/// <returns></returns  1:小端 0:大端>
int Check_Sys()
{
    int i = 1;
    //1的补码： 0000 0000   0000 0000   0000 0000   0000 0001
    //字节划分：0000 0000 | 0000 0000 | 0000 0000 | 0000 0001
    //             高位 ----------------------------> 低位
    return (*(char*)&i); 
    //(*(char*)&i) :  将i的地址强转char *,再解引用，实现返回变量低地址空间中的内容
    // 如果大端存储，应该返回0，否则返回1
}

int Add(int x, int y)
{   
    return x + y;
}
int Sub(int x,int y)
{
    return x - y;
}
int Mul(int x, int y)
{
    return x * y;
}
int Div(int x, int y)
{
    return x / y;
}
int main()
{
    int x, y;
    int input = 1;
    int ret = 0;
    int (*p[5])(int x, int y) = { 0,Add,Sub,Mul,Div };//转移表
    while (input) {
        printf("*************************\n");
        printf("***  1:add     2.sub  ***\n");
        printf("***  3:mul     4.div  ***\n");
        printf("请选择# ");
        scanf("%d",&input);
        if (input <= 4 && input >= 1) {
            printf("请输入操作数# ");
            scanf("%d %d",&x,&y);
            ret = (*p[input])(x, y);
        }
        else{
            printf("输入错误\n");
        }
        printf("ret = %d\n",ret);
    }
    return 0;
}