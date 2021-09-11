#include "list.h"

static void SplitInfo(char*, StuInfo*);
static Node* BuyNode(char*);
static StuInfo* GetData(LNode*);
static LNode* QKSort(LNode*);

//�ָ����룬��ȡname��age
static void SplitInfo(char* info, StuInfo* q) {
    char* p = info;
    //Ѱ�Ҽ����
    while (*p != ',')
        ++p;
    *p = '\0';
    ++p;
    memcpy(q->name, info, strlen(info));
    q->age = atoi(p);
}

//����ڵ�
static Node* BuyNode(char* info) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        printf("����ڵ�ʧ��!\n");
        exit(1);
    }
    p->_data.name = (char*)malloc(DEFAULT_LEN / 2);
    memset(p->_data.name, '\0', DEFAULT_LEN / 2);
    SplitInfo(info, &(p->_data));
    p->_node.next = NULL;
    return p;
}

//��ȡ���ݽڵ�
static StuInfo* GetData(LNode* t) {
    Node* p = (Node*)t;
    return &(p->_data);
}

//����
static LNode* QKSort(LNode* head) {
    if (head == NULL)
        return head;
    StuInfo* x = GetData(head);
    int l = x->age;
    int r = l;
    double pivot;
    LNode* p = head, * q = NULL, * h1 = NULL, * h2 = NULL;
    while (p != NULL) {//�����ֵ����Сֵ
        l = min(GetData(p)->age, l);
        r = max(GetData(p)->age, r);
        p = p->next;
    }
    pivot = (l + r) / 2.0;//ȡpivotΪ�����ֵ+��Сֵ��/2
    p = head;
    while (p != NULL) {
        q = p->next;//�ݴ�p->next
        StuInfo* y = GetData(p);
        if (y->age > pivot) {//h1����С��mid�Ĳ���
            p->next = h1;
            h1 = p;
        }
        else if(y->age < pivot){
            p->next = h2;
            h2 = p;
        }
        else {//������ͬ,�����ֳ���
            int lenh1 = strlen(GetData(h1)->name);
            int lenh2 = strlen(GetData(h2)->name);
            if (lenh1 > lenh2) {//���ֳ�������
                p->next = h1;
                h1 = p;
            }
            else {
                p->next = h2;
                h2 = p;
            }
         }
        p = q;//�ƶ�
    }
    h1 = QKSort(h1);//��h1��������
    h2 = QKSort(h2);//��h2��������
    p = h1;
    while (p->next != NULL)//�����ν���
        p = p->next;
    p->next = h2;
    return h1;
}
//��ӽڵ�
void AddNode(List* L) {
    char buf[DEFAULT_LEN] = { '0' };
    gets(buf);//��ȡ����
    Node* p = BuyNode(buf);
    p->_node.next = NULL;
    //����ڵ�
    if (L->head == L->tail && L->head == NULL) 
        L->head = L->tail = p;
    else {
        Node* t = L->tail;
        t->_node.next = &(p->_node);
        L->tail = p;
    }
    ++L->list_cnt;//����������
}

//�ṹ��ʼ��
List* ListInit() {
    List* p = (List*)malloc(sizeof(List));
    p->head = p->tail = NULL;
    p->list_cnt = 0;
    return p;
}

//��ӡ����
void ShowList(List* L) {
    LNode* t = L->head;
    while (t != NULL) {
        StuInfo* r = GetData(t);
        printf("%s,%d\n", r->name, r->age);
        t = t->next;
    }
}

//�ͷŵ����ڵ�
static void FreeNode(LNode* t) {
    Node* p = (Node*)t;
    StuInfo* r = GetData(t);
    free(r->name);
    free(p);
    p = NULL;
}

//�������ݽṹ
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
    //������βָ��
    LNode* t = L->head;
    while (t->next != NULL)
        t = t->next;
    L->tail = t;
}

//��ת����
void Reverse(List* L){
    if (L->head == NULL || L->head->next == NULL)
        return;
    //�Ͽ���һ���ڵ���ڶ����ڵ�
    L->tail = L->head->next;
    L->head->next = NULL;
    //ͷ�巨��ת����
    LNode* t = L->tail;
    while (t != NULL) {
        L->tail = t->next;
        t->next = L->head;
        L->head = t;
        t = L->tail;
    }
    //βָ������
    L->tail = L->head;
    while (L->tail->next != NULL)
        L->tail = L->tail->next;
}
