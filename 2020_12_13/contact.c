#include "contact.h"

void menu()
{
    printf("###############################\n");
    printf("#########1 添加联系人 #########\n");
    printf("#########2 删除联系人 #########\n");
    printf("#########3 查找联系人 #########\n");
    printf("#########4 显示所有人 #########\n");
    printf("#########5 按名字排序 #########\n");
    printf("#########6 清空通讯簿 #########\n");
    printf("#########7 修改联系人 #########\n");
    printf("#########0 退出电话簿 #########\n");
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
    person_t* end = ct->per + ct->size;//获取最后一一个联系人的内存地址
    int index = 0;
    for (person_t* p = ct->per; p < end; p++, index++) { //寻找
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
        printf("通讯录已满，不能添加！\n");
        return;
    } 
    char choice = 'Y';
    while (choice=='Y'|| choice == 'y') {
        person_t* p = ct->per + ct->size; //获取需要写入信息数组元素的地址
        printf("请输入姓名# ");
        scanf(" %s", p->name);
        printf("请输入电话# ");
        scanf(" %s", p->tel);
        if (IsExist(ct, p->tel) >= 0) {
            printf("该联系人已存在！\n");
            return;
        }
        printf("请输入性别# ");
        scanf(" %c", &(p->sex));
        printf("请输入年龄# ");
        scanf(" %d", &(p->age));
        printf("请输入地址# ");
        scanf(" %s", p->addr);
        ct->size += 1;
        printf("该联系人已添加成功！是否继续添加？(Y/N)\n");
        scanf(" %c",&choice);
    }
    Sleep(500);
    system("cls");
}

void SeekPerson(contact_t *ct)
{
    char tel_t[Size_char / 8];
    printf("请输入想要查找的联系人电话# ");
    scanf(" %s", tel_t);
    int index = IsExist(ct, tel_t);
    if (-1 == index) {
        printf("你要找的人[%s]不存在!\n", tel_t);
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
        person_t* end = ct->per + ct->size; //获取通讯录最后一个联系人结构体地址
        printf("统计: %d/%d\n", ct->size, ct->cap);
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
    printf("请输入被删联系人电话# ");
    scanf("%s",tel);
    int index = 0;
    if ((index = IsExist(ct, tel)) >= 0) { //用最后一个代替被删数据即可
        ct->per[index] = ct->per[ct->size - 1];
        ct->size -= 1;
        printf("删除成功！\n");
        Sleep(500);
        system("cls");
    }
    else {
        printf("你要删除的用户 [ %s ]， 是不存在的!\n", tel);
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
    printf("通讯录使用情况: %d/%d\n", ct->size, ct->cap);
    printf("请仔细考虑！确定清空通讯簿？(Y/N)");
    scanf(" %c", &c);
    if ((c == 'Y') || (c == 'y')) {
        ct->size = 0;
        printf("清空成功\n");
    }
    else {
        printf("宁放弃清空！\n");
    }
}

static void menu_s()
{
    printf("##########################\n");
    printf("######### 修改属性 #######\n");
    printf("######### 1 姓名 #########\n");
    printf("######### 2 年龄 #########\n");
    printf("######### 3 性别 #########\n");
    printf("######### 4 电话 #########\n");
    printf("######### 5 地址 #########\n");
    printf("##########################\n");
}

void ModPerson(contact_t* ct)
{
    assert(ct);
    menu_s();
    char tel_t[Size_char / 8];
    printf("请输入想要修改的联系人(电话索引)#");
    scanf(" %s",tel_t);
    int index = 0;
    if ((index = IsExist(ct, tel_t)) >= 0) { //用最后一个代替被删数据即可
        menu_s();
        int select = 0;
        printf("请输入想要修改的属性# ");
        scanf("%d", &select);
        switch (select) {
            case 1: 
                printf("请输入姓名# ");
                scanf(" %s",ct->per[index].name); 
                printf("修改成功！\n");
                break;
            case 2:
                printf("请输入性别# ");
                scanf(" %c", &(ct->per[index].sex));
                printf("修改成功！\n");
                break;
            case 3:
                printf("请输入年龄# ");
                scanf(" %d", &(ct->per[index].age));
                printf("修改成功！\n");
                break;
            case 4:
                printf("请输入姓电话#");
                scanf(" %s", ct->per[index].tel);
                printf("修改成功！\n");
                break;
            case 5:
                printf("请输入地址# ");
                scanf(" %s", ct->per[index].addr);
                printf("修改成功！\n");
                break;
            default:
                printf("输入错误！\n ");
                break;
        }
        PrintAll(ct, index);
    }
    else {
        printf("你要删除的用户 [ %s ]， 是不存在的!\n", tel_t);
    }
}