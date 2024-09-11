#pragma once
#define NAME_MAX 100
#define GENDER_MAX 10
#define TEL_MAX 11
#define ADDR_MAX 100
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//前置声明
typedef struct SeqList contact;
//用户数据
typedef struct PersonInfo{
	char name[NAME_MAX];
	int age;
	char gender[GENDER_MAX];
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}Info;
typedef Info SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;     // 有效数据个数
	int capacity; // 空间容量
}SL;
//初始化通讯录
void InitContact(contact* con);
//添加通讯录数据
void AddContact(contact* con);
//删除通讯录数据
void DelContact(contact* con);
//展示通讯录数据
void ShowContact(contact* con);
//查找通讯录数据
void FindContact(contact* con);
//修改通讯录数据
void ModifyContact(contact* con);
//销毁通讯录数据
void DestroyContact(contact* con);
//初始化和销毁
void SLInit(SL* ps);
void SLDestroy(SL* ps);
void SLPrint(SL* ps);
//扩容
void SLCheckCapacity(SL* ps);
//头部插入删除 / 尾部插入删除
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);
//指定位置之前插入/删除数据
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);
void SLFind(SL* ps, int x);