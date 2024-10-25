#define _CRT_SECURE_NO_WARNINGS 1
struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node* pcur = head;
    while (pcur) {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->val = pcur->val;
        newnode->next = pcur->next;
        pcur->next = newnode;
        pcur = newnode->next;
    }
    pcur = head;
    while (pcur) {
        if (pcur->random) {
            pcur->next->random = pcur->random->next;
        }
        else {
            pcur->next->random = pcur->random;
        }
        pcur = pcur->next->next;
    }
    pcur = head;
    struct Node* newhead = head->next;
    struct Node* newpcur = newhead;
    while (pcur) {
        pcur->next = newpcur->next;
        pcur = pcur->next;
        if (pcur) {
            newpcur->next = pcur->next;
            newpcur = newpcur->next;
        }
    }
    return newhead;
}
