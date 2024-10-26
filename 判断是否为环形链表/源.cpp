#define _CRT_SECURE_NO_WARNINGS 1
bool hasCycle(struct ListNode* head) {
    struct ListNode* fast = head, * slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return true;
        }
    }
    return false;
}