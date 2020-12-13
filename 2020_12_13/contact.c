#include "contact.h"

void menu()
{
    printf("###############################\n");
    printf("#########1 �����ϵ�� #########\n");
    printf("#########2 ɾ����ϵ�� #########\n");
    printf("#########3 ������ϵ�� #########\n");
    printf("#########4 ��ʾ������ #########\n");
    printf("#########5 ���������� #########\n");
    printf("#########6 ���ͨѶ�� #########\n");
    printf("#########7 �޸���ϵ�� #########\n");
    printf("#########0 �˳��绰�� #########\n");
    printf("###############################\n");
}

static int IsFull(contact_t* ct)
{
    assert(ct);
    return ct->size == ct->cap;
}

static int IsExist(contact_t* ct, const char* tel) 
{
    assert(ct);
    assert(tel);
    person_t* end = ct->per + ct->size;//��ȡ���һһ����ϵ�˵��ڴ��ַ
    int index = 0;
    for (person_t* p = ct->per; p < end; p++, index++) { //Ѱ��
        if (0 == strcmp(p->tel, tel)) {
            return index;
        }
    }
    return -1;
}

static int CompName(const void* p, const void* q) 
{
    person_t* p1 = (person_t*)p;
    person_t* q1 = (person_t*)q;
    return strcmp(p1,q1);
}

void AddPerson(contact_t* ct)
{
    assert(ct); 
    if(IsFull(ct)){
        printf("ͨѶ¼������������ӣ�\n");
        return;
    } 
    char choice = 'Y';
    while (choice=='Y'|| choice == 'y') {
        person_t* p = ct->per + ct->size; //��ȡ��Ҫд����Ϣ����Ԫ�صĵ�ַ
        printf("����������# ");
        scanf(" %s", p->name);
        printf("������绰# ");
        scanf(" %s", p->tel);
        if (IsExist(ct, p->tel) >= 0) {
            printf("����ϵ���Ѵ��ڣ�\n");
            return;
        }
        printf("�������Ա�# ");
        scanf(" %c", &(p->sex));
        printf("����������# ");
        scanf(" %d", &(p->age));
        printf("�������ַ# ");
        scanf(" %s", p->addr);
        ct->size += 1;
        printf("����ϵ������ӳɹ����Ƿ������ӣ�(Y/N)\n");
        scanf(" %c",&choice);
    }
    Sleep(500);
    system("cls");
}

void SeekPerson(contact_t *ct)
{
    char tel_t[Size_char / 8];
    printf("��������Ҫ���ҵ���ϵ�˵绰# ");
    scanf(" %s", tel_t);
    int index = IsExist(ct, tel_t);
    if (-1 == index) {
        printf("��Ҫ�ҵ���[%s]������!\n", tel_t);
        return;
    }
    else {
        PrintAll(ct, index);
    }
}

void PrintAll(contact_t* ct,int index)
{
    assert(ct);
    if (-1 == index) {
        person_t* end = ct->per + ct->size; //��ȡͨѶ¼���һ����ϵ�˽ṹ���ַ
        printf("ͳ��: %d/%d\n", ct->size, ct->cap);
        printf("----------------------------------------\n");
        for (person_t* p = ct->per; p < end; p++) {
            printf("|%-8s|%-2c|%-3d|%-11s|%-10s|\n", \
                p->name, p->sex, p->age, p->tel, p->addr);
        }
        printf("----------------------------------------\n");
    }
    else {
        person_t* p = ct->per + index;
        printf("|%-8s|%-2c|%-3d|%-11s|%-10s|\n", \
            p->name, p->sex, p->age, p->tel, p->addr);
    }
}

void DelPerson(contact_t* ct) 
{
    assert(ct);
    person_t* end = ct->size + ct->per;
    char tel[Size_char / 8];
    printf("�����뱻ɾ��ϵ�˵绰# ");
    scanf("%s",tel);
    int index = 0;
    if ((index = IsExist(ct, tel)) >= 0) { //�����һ�����汻ɾ���ݼ���
        ct->per[index] = ct->per[ct->size - 1];
        ct->size -= 1;
        printf("ɾ���ɹ���\n");
        Sleep(500);
        system("cls");
    }
    else {
        printf("��Ҫɾ�����û� [ %s ]�� �ǲ����ڵ�!\n", tel);
    }
}

void SortName(contact_t* ct)
{
    assert(ct);
    assert(ct);
    qsort(ct->per, ct->size, sizeof(person_t), CompName);
}

void ClearContact(contact_t* ct)
{
    assert(ct);
    char c = 'N';
    printf("ͨѶ¼ʹ�����: %d/%d\n", ct->size, ct->cap);
    printf("����ϸ���ǣ�ȷ�����ͨѶ����(Y/N)");
    scanf(" %c", &c);
    if ((c == 'Y') || (c == 'y')) {
        ct->size = 0;
        printf("��ճɹ�\n");
    }
    else {
        printf("��������գ�\n");
    }
}

static void menu_s()
{
    printf("##########################\n");
    printf("######### �޸����� #######\n");
    printf("######### 1 ���� #########\n");
    printf("######### 2 ���� #########\n");
    printf("######### 3 �Ա� #########\n");
    printf("######### 4 �绰 #########\n");
    printf("######### 5 ��ַ #########\n");
    printf("##########################\n");
}

void ModPerson(contact_t* ct)
{
    assert(ct);
    menu_s();
    char tel_t[Size_char / 8];
    printf("��������Ҫ�޸ĵ���ϵ��(�绰����)#");
    scanf(" %s",tel_t);
    int index = 0;
    if ((index = IsExist(ct, tel_t)) >= 0) { //�����һ�����汻ɾ���ݼ���
        menu_s();
        int select = 0;
        printf("��������Ҫ�޸ĵ�����# ");
        scanf("%d", &select);
        switch (select) {
            case 1: 
                printf("����������# ");
                scanf(" %s",ct->per[index].name); 
                printf("�޸ĳɹ���\n");
                break;
            case 2:
                printf("�������Ա�# ");
                scanf(" %c", &(ct->per[index].sex));
                printf("�޸ĳɹ���\n");
                break;
            case 3:
                printf("����������# ");
                scanf(" %d", &(ct->per[index].age));
                printf("�޸ĳɹ���\n");
                break;
            case 4:
                printf("�������յ绰#");
                scanf(" %s", ct->per[index].tel);
                printf("�޸ĳɹ���\n");
                break;
            case 5:
                printf("�������ַ# ");
                scanf(" %s", ct->per[index].addr);
                printf("�޸ĳɹ���\n");
                break;
            default:
                printf("�������\n ");
                break;
        }
        PrintAll(ct, index);
    }
    else {
        printf("��Ҫɾ�����û� [ %s ]�� �ǲ����ڵ�!\n", tel_t);
    }
}