#include "contact.h"

static int IsFull(contact_t* ct)
{
    assert(ct);
    return ct->size == ct->cap;
}
static int Inc(contact_t** ct) 
{
    assert(*ct);
    int flag = 0;
    //contact_t �Ĵ�С�����������������С��+���������������С
    contact_t* p = (contact_t*)realloc(*ct, sizeof(contact_t) + sizeof(person_t) * ((*ct)->cap + INC_SIZE));
    if (NULL != p) {
        printf("realloc success!\n");
        *ct = p;
        (*ct)->cap = (*ct)->cap + INC_SIZE; //��������
        flag = 1;
    }
    else {
        printf("realloc failed!\n");
    }
    return flag;
}
static int IsExist(contact_t* ct,const char* tel) 
{
    assert(ct);
    assert(tel);
    person_t* end = ct->per + ct->size;
    int index = 0;
    for (person_t* p = ct->per; p < end; p++,index++) {
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
    return strcmp(p1, q1);
}
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
void InitContact(contact_t** ct) 
{   //��ʼ��ͨѶ¼
    FILE* fp = fopen(FILE_S, "rb");
    if (NULL == fp) {
        *ct = (contact_t*)malloc(sizeof(contact_t) + sizeof(person_t) * INIT);//�������INIT���ṹ���ͨѶ¼
        if (NULL == *ct) {//����ʧ��
            printf("malloc failed!\n");
            exit(1);//��ֹ����
        }
        (*ct)->size = 0;
        (*ct)->cap = INIT;
    }
    else {
        printf("�ļ���ȡ�ɹ���\n");//��ȡ�ɹ�������Ӧ�ô���ͨѶ¼
        contact_t old = { 0 };
        fread(&old, sizeof(contact_t), 1, fp);
        *ct = (contact_t*)malloc(sizeof(contact_t) + old.cap * sizeof(person_t));
        if (NULL == *ct) {
            printf("malloc error!\n");
            exit(2);
        }
        person_t* p = (*ct)->per;
        fread(p, sizeof(person_t), old.size, fp);
        (*ct)->size = old.size;
        (*ct)->cap = old.cap;
        fclose(fp);
    }
}
void AddPerson(contact_t** ct)
{
    assert(*ct);
    char tel[Num / 8];
    printf("�����������ϵ�˵ĵ绰# ");
    scanf(" %s", tel);
    if (IsExist(*ct, tel) != -1) {
        return;
    }
    if (!IsFull(*ct) || Inc(ct)) {//�������䣬����ֱ�����
        person_t* p = (*ct)->per + (*ct)->size;
        printf("����������# ");
        scanf(" %s",p->name);
        printf("������绰# ");
        scanf(" %s", p->tel);
        printf("�������Ա�# ");
        scanf(" %c", &(p->sex));
        printf("����������# ");
        scanf(" %d", &(p->age));
        printf("�������ַ# ");
        scanf(" %s", p->addr);
        (*ct)->size += 1;
        printf("��ӳɹ���\n");
    }
    else{
        printf("realloc failed!\n");
    }
}
void SeekPerson(contact_t* ct)
{
    char tel_t[Num / 8];
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
void PrintAll(contact_t* ct, int index)
{
    assert(ct);
    if (-1 == index) {
        person_t* end = ct->per + ct->size; //��ȡͨѶ¼���һ����ϵ�˽ṹ���ַ
        printf("ͳ��: %d/%d\n", ct->size, ct->cap);
        printf("-------------------------------------------------\n");
        for (person_t* p = ct->per; p < end; p++) {
            printf("%-12s|%-3c|%-3d|%-11s|%-15s|\n", \
                p->name, p->sex, p->age, p->tel, p->addr);
        }
        printf("-------------------------------------------------\n");
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
    char tel[Num / 8];
    printf("�����뱻ɾ��ϵ�˵绰# ");
    scanf("%s", tel);
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
    char tel_t[Num / 8];
    printf("��������Ҫ�޸ĵ���ϵ��(�绰����)#");
    scanf(" %s", tel_t);
    int index = 0;
    if ((index = IsExist(ct, tel_t)) >= 0) { //�����һ�����汻ɾ���ݼ���
        menu_s();
        int select = 0;
        printf("��������Ҫ�޸ĵ�����# ");
        scanf("%d", &select);
        switch (select) {
        case 1:
            printf("����������# ");
            scanf(" %s", ct->per[index].name);
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
void SaveFile(contact_t* ct)
{
    FILE* fp = fopen(FILE_S, "wb");
    if (NULL == fp) {
        printf("fopen failed!\n");
        return;
    }
    person_t* p = ct->per;
    fwrite(ct, sizeof(contact_t), 1, fp);//ͨѶ¼ͷ��д���ļ�
    fwrite(p, sizeof(person_t), ct->size, fp);//ͨѶ¼��ϵ����Ϣд��
    fclose(fp);
    printf("�ļ�д��ɹ�\n");
}