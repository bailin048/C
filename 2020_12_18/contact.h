#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <windows.h>

#pragma warning(disable:4996)

#define Num 128
#define INIT 5
#define INC_SIZE 3
enum { //枚举操作
	EXT,
	Add,
	Del,
	Seek,
	Show,
	Sort,
	Cls,
	Mod,
};
typedef struct person
{
	char name[Num / 4];
	char sex;
	int age;
	char tel[Num / 8];
	char addr[Num];
}person_t;

typedef struct contact
{
	int cap;
	int size;
	person_t per[0];//柔性数组
}contact_t;

void menu();
void InitContact(contact_t** ct);
void AddPerson(contact_t** ct);
void PrintAll(contact_t* ct, int index);
void SeekPerson(contact_t* ct);
void DelPerson(contact_t* ct);
void SortName(contact_t* ct);
void ClearContact(contact_t* ct);
void ModPerson(contact_t* ct);

#endif
