#pragma once
#define NAME_MAX 100
#define GENDER_MAX 10
#define TEL_MAX 11
#define ADDR_MAX 100
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//ǰ������
typedef struct SeqList contact;
//�û�����
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
	int size;     // ��Ч���ݸ���
	int capacity; // �ռ�����
}SL;
//��ʼ��ͨѶ¼
void InitContact(contact* con);
//���ͨѶ¼����
void AddContact(contact* con);
//ɾ��ͨѶ¼����
void DelContact(contact* con);
//չʾͨѶ¼����
void ShowContact(contact* con);
//����ͨѶ¼����
void FindContact(contact* con);
//�޸�ͨѶ¼����
void ModifyContact(contact* con);
//����ͨѶ¼����
void DestroyContact(contact* con);
//��ʼ��������
void SLInit(SL* ps);
void SLDestroy(SL* ps);
void SLPrint(SL* ps);
//����
void SLCheckCapacity(SL* ps);
//ͷ������ɾ�� / β������ɾ��
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);
//ָ��λ��֮ǰ����/ɾ������
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);
void SLFind(SL* ps, int x);