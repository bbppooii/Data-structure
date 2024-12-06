#define _CRT_SECURE_NO_WARNINGS 1
#include "t.h"

int main() {
	int a[] = { 1,5,9,8,7,4,6,2,3 };
	PrintArray(a, sizeof(a) / sizeof(int));
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	return 0;
}