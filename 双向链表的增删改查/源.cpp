#define _CRT_SECURE_NO_WARNINGS 1
#include "s.h"
int main() {
    LTNode* list = LTInit();

    LTPushBack(list, 10);
    LTPushBack(list, 20);
    LTPushBack(list, 30);

    LTPrint(list);

    LTNode* pos = LTFind(list, 20);
    if (pos) {
        LTInsert(pos, 25);
    }
    LTPrint(list);

    LTPopBack(list);
    LTPrint(list);

    LTDestroy(list);
    return 0;
}
