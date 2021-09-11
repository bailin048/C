#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vld.h>
#include <math.h>
#pragma warning(disable:4996)

#define DEFAULT_LEN 128 //�ַ����洢����������

struct node {
    struct node* next;
};

struct list {
    struct node* head;
    struct node* tail;
    int list_cnt;
};

struct student_info {
    char* name;
    int age;
};

typedef struct node LNode;
typedef struct student_info StuInfo;
typedef struct list List;

//��װ�ڵ�������
typedef struct Node {
    LNode _node;
    StuInfo _data;
}Node;


List* ListInit();
void AddNode(List*);
void ShowList(List*);
void DestoryData(List*);
void Sort(List*);
void Reverse(List*);