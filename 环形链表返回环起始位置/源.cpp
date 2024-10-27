#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}