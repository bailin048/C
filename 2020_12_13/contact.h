#ifndef __CONTACT__H__
#define __CONTACT__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <assert.h>
#pragma warning(disable:4996)

#define Size_char 128
#define Num 1000

enum { //ö�ٲ���
    EXT,
    Add,
    Del,
    Seek,
    Show,
    Sort,
    Cls,
    Mod,
};

typedef struct person //���Է�װ
{
    char name[Size_char / 4];
    char sex;
    int age;
    char tel[Size_char / 8];
    char addr[Size_char];
}person_t;

typedef struct contact 
{
    int size;  //��ǰ����
    int cap;//�������
    person_t per[Num];  //����ָ��
}contact_t;

void menu();
void AddPerson(contact_t* ct);
void PrintAll(contact_t* ct, int index);
void SeekPerson(contact_t* ct);
void DelPerson(contact_t* ct);
void SortName(contact_t* ct);
void ClearContact(contact_t* ct);
void ModPerson(contact_t* ct);
#endif
