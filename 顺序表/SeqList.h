#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//��̬˳���

//#define N 100
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};

//��̬˳���

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* arr; //�洢���ݵĵײ�ṹ
	int capacity;    //��¼˳���Ŀռ��С
	int size;        //��¼˳���ǰ��Ч�����ݸ���
}SL;

//typedef struct SeqList SL;

//��ʼ��������
void SLInit(SL* ps);
void SLDestroy(SL* ps);
void SLPrint(SL* ps); //���ֽӿ�һ����

//˳����ͷ��/β������
void SLPushBack(SL* ps, SLDataType x);
void SLPushFront(SL* ps, SLDataType x);

//˳����ͷ��/β��ɾ��
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

//ָ��λ��֮ǰ��������
//ɾ��ָ��λ������
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);
