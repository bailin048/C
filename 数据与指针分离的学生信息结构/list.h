#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vld.h>
#include <math.h>
#pragma warning(disable:4996)

#define DEFAULT_LEN 128 //字符串存储缓冲区长度

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

//封装节点与数据
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