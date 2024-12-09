#define _CRT_SECURE_NO_WARNINGS 1
#include "t.h"
int main() {
	int a[] = { 7,5,6,4,8,9,2,1,3,0 };
	_printf(a, sizeof(a) / sizeof(a[0]));
	printf("\n");
	QuickSortNonR(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	_printf(a, sizeof(a) / sizeof(a[0]));
}
