#include "contact.h"


int main()
{
    contact_t ct;
    memset(&ct,0, sizeof(ct));
    ct.cap = Num;
    int exit = 1;//退出标志，为0退出
    while (exit) {
        menu();
        int choice = 0;
        printf("请输入宁的目的# ");
        scanf("%d",&choice);
        system("cls");
        switch (choice) {
            case Add:AddPerson(&ct); break;
            case Del:DelPerson(&ct); break;
            case Seek:SeekPerson(&ct); break;
            case Show:PrintAll(&ct,-1); break;
            case Sort:SortName(&ct); break;
            case Cls:ClearContact(&ct); break;
            case Mod:ModPerson(&ct); break;
            case EXT:exit = 0; break;
            default:printf("输入错误！请重新输入# "); break;
        }
    }
    return 0;
}