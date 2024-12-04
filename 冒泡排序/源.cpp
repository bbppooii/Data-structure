#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void _printf(int*a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}
void BubbleSort(int* a, int n) {
	bool swapped = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				Swap(&a[j], &a[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	}
}
int main() {
	int a[] = { 1,2,3,7,8,9,4,5,6 };
	_printf(a, sizeof(a) / sizeof(a[0]));
	printf("\n");
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	_printf(a, sizeof(a) / sizeof(a[0]));
}