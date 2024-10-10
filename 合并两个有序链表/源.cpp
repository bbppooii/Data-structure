#define _CRT_SECURE_NO_WARNINGS 1
typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    ListNode* l1, * l2;
    l1 = list1, l2 = list2;
    ListNode* head, * tail;
    head = tail = NULL;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            if (head == NULL) {
                head = tail = l1;
            }
            else {
                tail->next = l1;
                tail = tail->next;
            }
            l1 = l1->next;
        }
        else {
            if (head == NULL) {
                head = tail = l2;
            }
            else {
                tail->next = l2;
                tail = tail->next;
            }
            l2 = l2->next;
        }
    }
    if (l1) {
        tail->next = l1;
    }
    if (l2) {
        tail->next = l2;
    }
    return head;
}