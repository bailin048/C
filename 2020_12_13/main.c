#include "contact.h"


int main()
{
    contact_t ct;
    memset(&ct,0, sizeof(ct));
    ct.cap = Num;
    int exit = 1;//�˳���־��Ϊ0�˳�
    while (exit) {
        menu();
        int choice = 0;
        printf("����������Ŀ��# ");
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
            default:printf("�����������������# "); break;
        }
    }
    return 0;
}