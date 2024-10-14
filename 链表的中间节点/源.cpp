#define _CRT_SECURE_NO_WARNINGS 1
typedef struct ListNode ListNode;
struct ListNode* middleNode(struct ListNode* head) {
    ListNode* slow, * fast;
    slow = fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}