#define _CRT_SECURE_NO_WARNINGS 1
#include "t.h"

int main() {
	int a[] = { 1,5,9,8,7,4,6,2,3 };
	Print(a, sizeof(a) / sizeof(int));
	ShellSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
	return 0;
}