#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* cureA = headA, * cureB = headB;
    int lena = 1, lenb = 1;
    while (cureA->next) {
        lena++;
        cureA = cureA->next;
    }
    while (cureB->next) {
        lenb++;
        cureB = cureB->next;
    }
    if (cureA != cureB) {
        return NULL;
    }
    int gap = abs(lena - lenb);
    struct ListNode* longs = headA;
    struct ListNode* shorts = headB;
    if (lenb > lena) {
        longs = headB;
        shorts = headA;
    }
    while (gap--) {
        longs = longs->next;
    }
    while (longs != shorts) {
        longs = longs->next;
        shorts = shorts->next;
    }
    return longs;
}