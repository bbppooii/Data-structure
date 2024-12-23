#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 计数排序函数
void CountingSort(int* a, int n) {
    if (n <= 1) return; // 数组长度不足时直接返回

    // 找到数组中的最大值和最小值
    int max = a[0], min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }

    // 创建计数数组并初始化
    int range = max - min + 1; // 元素范围
    int* count = (int*)calloc(range, sizeof(int));
    if (count == NULL) {
        perror("Memory allocation failed");
        return;
    }

    // 统计每个元素的出现次数
    for (int i = 0; i < n; i++) {
        count[a[i] - min]++;
    }

    // 累积计数，用于计算每个元素的最终位置
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // 创建目标数组
    int* output = (int*)malloc(n * sizeof(int));
    if (output == NULL) {
        perror("Memory allocation failed");
        free(count);
        return;
    }

    // 倒序遍历原数组，将元素放置到正确位置
    for (int i = n - 1; i >= 0; i--) {
        int index = count[a[i] - min] - 1;
        output[index] = a[i];
        count[a[i] - min]--;
    }

    // 将排序结果写回到原数组
    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }

    // 释放内存
    free(count);
    free(output);
}

int main() {
    int a[] = { 4, 2, 2, 8, 3, 3, 1 };
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    CountingSort(a, n);

    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
