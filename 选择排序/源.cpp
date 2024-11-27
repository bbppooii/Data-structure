#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void Print(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
void ShellSort(int* a, int n) {
	int gap = n;
	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0) {
				if (a[end] > tmp) {
					a[end] = tmp;
					end -= gap;
				}else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
void SelectSort(int* a, int n) {
	int begin = 0;
	int end = n - 1;
	while (begin < end) {
		int min = begin, max = begin;
		for (int i = begin + 1; i <= end; i++) {
			if (a[i] > a[max]) {
				max = i;
			}
			if (a[i] < a[min]) {
				min = i;
			}
		}
		Swap(&a[begin], &a[min]);
		if (max == begin) {
			max = min;
		}
		Swap(&a[end], &a[max]);
		end--;
		max++;
	}
}
int main() {
	int a[] = { 1,5,9,8,7,4,6,2,3 };
	Print(a, sizeof(a) / sizeof(int));
	SelectSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
	return 0;
}