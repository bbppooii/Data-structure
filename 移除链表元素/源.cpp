#define _CRT_SECURE_NO_WARNINGS 1
typedef struct ListNode ListNode;
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    struct ListNode* s = NULL;
    while (head != NULL && head->val == val) {
        head = head->next;
    }
    while (cur != NULL) {
        //¿ìÂıÖ¸Õë
        s = cur->next;
        while (s != NULL && s->val == val) {
            cur->next = cur->next->next;
            free(s);
            s = cur->next;
        }
        cur = cur->next;
    }
    return head;
}
