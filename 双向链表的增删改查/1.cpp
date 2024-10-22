#define _CRT_SECURE_NO_WARNINGS 1
#include "s.h"
// 初始化双向链表，返回头结点指针
LTNode* LTInit() {
    LTNode* head = (LTNode*)malloc(sizeof(LTNode));
    if (head == NULL) {
        perror("malloc failed");
        exit(-1);
    }
    head->next = head;
    head->prev = head;
    return head;
}

// 销毁双向链表，释放所有节点
void LTDestroy(LTNode* phead) {
    LTNode* cur = phead->next;
    while (cur != phead) {
        LTNode* next = cur->next;
        free(cur);
        cur = next;
    }
    free(phead);
}

// 打印双向链表
void LTPrint(LTNode* phead) {
    LTNode* cur = phead->next;
    while (cur != phead) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

// 判断链表是否为空
bool LTEmpty(LTNode* phead) {
    return phead->next == phead;
}

// 尾插
void LTPushBack(LTNode* phead, LTDataType x) {
    LTNode* new_node = (LTNode*)malloc(sizeof(LTNode));
    new_node->data = x;

    // 插入到尾部
    new_node->prev = phead->prev;
    new_node->next = phead;
    phead->prev->next = new_node;
    phead->prev = new_node;
}

// 尾删
void LTPopBack(LTNode* phead) {
    if (LTEmpty(phead)) return;
    LTNode* tail = phead->prev;
    tail->prev->next = phead;
    phead->prev = tail->prev;
    free(tail);
}

// 头插
void LTPushFront(LTNode* phead, LTDataType x) {
    LTNode* new_node = (LTNode*)malloc(sizeof(LTNode));
    new_node->data = x;

    // 插入到头部
    new_node->next = phead->next;
    new_node->prev = phead;
    phead->next->prev = new_node;
    phead->next = new_node;
}

// 头删
void LTPopFront(LTNode* phead) {
    if (LTEmpty(phead)) return;

    LTNode* first = phead->next;
    phead->next = first->next;
    first->next->prev = phead;
    free(first);
}

// 在 pos 位置之后插入数据
void LTInsert(LTNode* pos, LTDataType x) {
    LTNode* new_node = (LTNode*)malloc(sizeof(LTNode));
    new_node->data = x;

    new_node->next = pos->next;
    new_node->prev = pos;
    pos->next->prev = new_node;
    pos->next = new_node;
}

// 删除 pos 位置的节点
void LTErase(LTNode* pos) {
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    free(pos);
}

// 查找数据 x，返回对应节点的指针
LTNode* LTFind(LTNode* phead, LTDataType x) {
    LTNode* cur = phead->next;
    while (cur != phead) {
        if (cur->data == x) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
