#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int kthToLast(struct ListNode* head, int k) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (k--) {
        if (fast == NULL) {
            return NULL;
        }
        fast = fast->next;
    }
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->val;
}