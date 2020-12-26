#include "contact.h"

int main()
{
    contact_t* ct = NULL;
    InitContact(&ct);
    int exit = 1;//�˳���־��Ϊ0�˳�
    while (exit) {
        menu();
        int choice = 0;
        printf("����������Ŀ��# ");
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
        default:system("cls"); printf("�����������������# "); break;
        }
    }
    return 0;
}