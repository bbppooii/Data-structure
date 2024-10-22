#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int LTDataType;
typedef struct ListNode {
    LTDataType data;
    struct ListNode* prev;
    struct ListNode* next;
} LTNode;
//void LTInit(LTNode** pphead);
// 初始化双向链表，返回头结点指针
LTNode* LTInit();
// 销毁双向链表，释放所有节点
void LTDestroy(LTNode* phead);
// 打印双向链表
void LTPrint(LTNode* phead);
// 判断链表是否为空
bool LTEmpty(LTNode* phead);
// 尾插
void LTPushBack(LTNode* phead, LTDataType x);
// 尾删
void LTPopBack(LTNode* phead);
// 头插
void LTPushFront(LTNode* phead, LTDataType x);
// 头删
void LTPopFront(LTNode* phead);
//在pos位置之后插入数据
void LTInsert(LTNode* pos, LTDataType x);
// 删除 pos 位置的节点
void LTErase(LTNode* pos);
// 查找数据 x，返回对应节点的指针
LTNode* LTFind(LTNode* phead, LTDataType x);