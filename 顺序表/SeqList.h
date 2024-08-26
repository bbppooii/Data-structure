#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//静态顺序表

//#define N 100
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};

//动态顺序表

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* arr; //存储数据的底层结构
	int capacity;    //记录顺序表的空间大小
	int size;        //记录顺序表当前有效的数据个数
}SL;

//typedef struct SeqList SL;

//初始化和销毁
void SLInit(SL* ps);
void SLDestroy(SL* ps);
void SLPrint(SL* ps); //保持接口一致性

//顺序表的头部/尾部插入
void SLPushBack(SL* ps, SLDataType x);
void SLPushFront(SL* ps, SLDataType x);

//顺序表的头部/尾部删除
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

//指定位置之前插入数据
//删除指定位置数据
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);
