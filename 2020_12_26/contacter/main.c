#include "contact.h"

int main()
{
    contact_t* ct = NULL;
    InitContact(&ct);
    int exit = 1;//退出标志，为0退出
    while (exit) {
        menu();
        int choice = 0;
        printf("请输入宁的目的# ");
        scanf("%d", &choice);
        system("cls");
        switch (choice) {
        case Add:system("cls"); AddPerson(&ct); break;
        case Del:system("cls"); DelPerson(ct); break;
        case Seek:system("cls"); SeekPerson(ct); break;
        case Show:system("cls"); PrintAll(ct, -1); break;
        case Sort:system("cls"); SortName(ct);break;
        case Cls:system("cls"); ClearContact(ct);break;
        case Mod:system("cls"); ModPerson(ct); break;
        case EXT:system("cls"); exit = 0; SaveFile(ct);break;
        default:system("cls"); printf("输入错误！请重新输入# "); break;
        }
    }
    return 0;
}