#define _CRT_SECURE_NO_WARNINGS 1
#include "t.h"
void ShellSort(int* a, int n) {
    // 初始化步长（gap）为数组长度
    int gap = n;
    // 使用缩减增量的方式逐步排序
    while (gap > 1) {
        // 缩小增量，使用更小的分组
        gap = gap / 3 + 1; // 希尔增量序列的一种选择方式
        // 对每组数据进行插入排序
        for (int i = 0; i < n - gap; i++) {
            // 当前分组的最后一个已排序元素
            int end = i;
            // 待插入的元素
            int tmp = a[end + gap];
            // 将 tmp 插入到当前分组的正确位置
            while (end >= 0 && a[end] > tmp) {
                // 如果当前元素大于待插入元素，则向后移动
                a[end + gap] = a[end];
                end -= gap; // 移动到上一个分组位置
            }
            // 插入元素到正确位置
            a[end + gap] = tmp;
        }
    }
}
void Print(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}