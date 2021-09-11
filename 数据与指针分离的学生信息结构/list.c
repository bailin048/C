#include "list.h"

static void SplitInfo(char*, StuInfo*);
static Node* BuyNode(char*);
static StuInfo* GetData(LNode*);
static LNode* QKSort(LNode*);

//分割输入，获取name与age
static void SplitInfo(char* info, StuInfo* q) {
    char* p = info;
    //寻找间隔符
    while (*p != ',')
        ++p;
    *p = '\0';
    ++p;
    memcpy(q->name, info, strlen(info));
    q->age = atoi(p);
}

//申请节点
static Node* BuyNode(char* info) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        printf("申请节点失败!\n");
        exit(1);
    }
    p->_data.name = (char*)malloc(DEFAULT_LEN / 2);
    memset(p->_data.name, '\0', DEFAULT_LEN / 2);
    SplitInfo(info, &(p->_data));
    p->_node.next = NULL;
    return p;
}

//获取数据节点
static StuInfo* GetData(LNode* t) {
    Node* p = (Node*)t;
    return &(p->_data);
}

//快排
static LNode* QKSort(LNode* head) {
    if (head == NULL)
        return head;
    StuInfo* x = GetData(head);
    int l = x->age;
    int r = l;
    double pivot;
    LNode* p = head, * q = NULL, * h1 = NULL, * h2 = NULL;
    while (p != NULL) {//求最大值和最小值
        l = min(GetData(p)->age, l);
        r = max(GetData(p)->age, r);
        p = p->next;
    }
    pivot = (l + r) / 2.0;//取pivot为（最大值+最小值）/2
    p = head;
    while (p != NULL) {
        q = p->next;//暂存p->next
        StuInfo* y = GetData(p);
        if (y->age > pivot) {//h1代表小于mid的部分
            p->next = h1;
            h1 = p;
        }
        else if(y->age < pivot){
            p->next = h2;
            h2 = p;
        }
        else {//年龄相同,看名字长度
            int lenh1 = strlen(GetData(h1)->name);
            int lenh2 = strlen(GetData(h2)->name);
            if (lenh1 > lenh2) {//名字长的先排
                p->next = h1;
                h1 = p;
            }
            else {
                p->next = h2;
                h2 = p;
            }
         }
        p = q;//移动
    }
    h1 = QKSort(h1);//对h1部分排序
    h2 = QKSort(h2);//对h2部分排序
    p = h1;
    while (p->next != NULL)//把两段接上
        p = p->next;
    p->next = h2;
    return h1;
}
//添加节点
void AddNode(List* L) {
    char buf[DEFAULT_LEN] = { '0' };
    gets(buf);//获取输入
    Node* p = BuyNode(buf);
    p->_node.next = NULL;
    //插入节点
    if (L->head == L->tail && L->head == NULL) 
        L->head = L->tail = p;
    else {
        Node* t = L->tail;
        t->_node.next = &(p->_node);
        L->tail = p;
    }
    ++L->list_cnt;//计数器自增
}

//结构初始化
List* ListInit() {
    List* p = (List*)malloc(sizeof(List));
    p->head = p->tail = NULL;
    p->list_cnt = 0;
    return p;
}

//打印数据
void ShowList(List* L) {
    LNode* t = L->head;
    while (t != NULL) {
        StuInfo* r = GetData(t);
        printf("%s,%d\n", r->name, r->age);
        t = t->next;
    }
}

//释放单个节点
static void FreeNode(LNode* t) {
    Node* p = (Node*)t;
    StuInfo* r = GetData(t);
    free(r->name);
    free(p);
    p = NULL;
}

//销毁数据结构
void DestoryData(List* L) {
    LNode* t = L->head;
    while (t != NULL) {
        LNode* tmp = t;
        t = t->next;
        FreeNode(tmp);
        L->head = t;
        --L->list_cnt;
    }
    free(L);
}

void Sort(List* L) {
    L->head = QKSort(L->head);
    //重置首尾指针
    LNode* t = L->head;
    while (t->next != NULL)
        t = t->next;
    L->tail = t;
}

//翻转链表
void Reverse(List* L){
    if (L->head == NULL || L->head->next == NULL)
        return;
    //断开第一个节点与第二个节点
    L->tail = L->head->next;
    L->head->next = NULL;
    //头插法翻转链表
    LNode* t = L->tail;
    while (t != NULL) {
        L->tail = t->next;
        t->next = L->head;
        L->head = t;
        t = L->tail;
    }
    //尾指针重置
    L->tail = L->head;
    while (L->tail->next != NULL)
        L->tail = L->tail->next;
}
