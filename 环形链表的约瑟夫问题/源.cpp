#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
typedef struct ListNode ListNode;
ListNode* BuyNode(int x) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}
ListNode* CREATE(int n) {
    ListNode* phead = BuyNode(1);
    ListNode* ptail = phead;
    for (int i = 2; i <= n; i++) {
        ptail->next = BuyNode(i);
        ptail = ptail->next;
    }
    ptail->next = phead;
    return ptail;
}
int ysf(int n, int m) {
    ListNode* prev = CREATE(n);
    ListNode* pcur = prev->next;
    int qwe = 1;
    while (pcur->next != pcur) {
        if (qwe == m) {
            prev->next = pcur->next;
            free(pcur);
            pcur = prev->next;
            qwe = 1;
        }
        else {
            prev = pcur;
            pcur = pcur->next;
            qwe++;
        }
    }
    return pcur->val;
}