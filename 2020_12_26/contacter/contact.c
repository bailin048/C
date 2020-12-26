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
    //contact_t 的大小（不包括柔性数组大小）+扩充后的柔性数组大小
    contact_t* p = (contact_t*)realloc(*ct, sizeof(contact_t) + sizeof(person_t) * ((*ct)->cap + INC_SIZE));
    if (NULL != p) {
        printf("realloc success!\n");
        *ct = p;
        (*ct)->cap = (*ct)->cap + INC_SIZE; //容量更新
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
void InitContact(contact_t** ct) 
{   //初始化通讯录
    FILE* fp = fopen(FILE_S, "rb");
    if (NULL == fp) {
        *ct = (contact_t*)malloc(sizeof(contact_t) + sizeof(person_t) * INIT);//申请具有INIT个结构体的通讯录
        if (NULL == *ct) {//申请失败
            printf("malloc failed!\n");
            exit(1);//终止程序
        }
        (*ct)->size = 0;
        (*ct)->cap = INIT;
    }
    else {
        printf("文件读取成功！\n");//读取成功，下面应该创建通讯录
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
    printf("请输入添加联系人的电话# ");
    scanf(" %s", tel);
    if (IsExist(*ct, tel) != -1) {
        return;
    }
    if (!IsFull(*ct) || Inc(ct)) {//满则扩充，不满直接添加
        person_t* p = (*ct)->per + (*ct)->size;
        printf("请输入姓名# ");
        scanf(" %s",p->name);
        printf("请输入电话# ");
        scanf(" %s", p->tel);
        printf("请输入性别# ");
        scanf(" %c", &(p->sex));
        printf("请输入年龄# ");
        scanf(" %d", &(p->age));
        printf("请输入地址# ");
        scanf(" %s", p->addr);
        (*ct)->size += 1;
        printf("添加成功！\n");
    }
    else{
        printf("realloc failed!\n");
    }
}
void SeekPerson(contact_t* ct)
{
    char tel_t[Num / 8];
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
void PrintAll(contact_t* ct, int index)
{
    assert(ct);
    if (-1 == index) {
        person_t* end = ct->per + ct->size; //获取通讯录最后一个联系人结构体地址
        printf("统计: %d/%d\n", ct->size, ct->cap);
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
    printf("请输入被删联系人电话# ");
    scanf("%s", tel);
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
    char tel_t[Num / 8];
    printf("请输入想要修改的联系人(电话索引)#");
    scanf(" %s", tel_t);
    int index = 0;
    if ((index = IsExist(ct, tel_t)) >= 0) { //用最后一个代替被删数据即可
        menu_s();
        int select = 0;
        printf("请输入想要修改的属性# ");
        scanf("%d", &select);
        switch (select) {
        case 1:
            printf("请输入姓名# ");
            scanf(" %s", ct->per[index].name);
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
void SaveFile(contact_t* ct)
{
    FILE* fp = fopen(FILE_S, "wb");
    if (NULL == fp) {
        printf("fopen failed!\n");
        return;
    }
    person_t* p = ct->per;
    fwrite(ct, sizeof(contact_t), 1, fp);//通讯录头部写入文件
    fwrite(p, sizeof(person_t), ct->size, fp);//通讯录联系人信息写入
    fclose(fp);
    printf("文件写入成功\n");
}