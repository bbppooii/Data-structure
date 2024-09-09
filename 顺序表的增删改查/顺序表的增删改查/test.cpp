#define _CRT_SECURE_NO_WARNINGS 1
#include "s.h"
int main() {
	SL sl;
	SLInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushBack(&sl, 3);
	SLPopBack(&sl);
	SLPopFront(&sl);
	SLInsert(&sl, 0, 100);
	SLPrint(&sl);
}