#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 合并两个有序子数组
void Merge(int* a, int left, int mid, int right, int* tmp) {
    int i = left;      // 左子数组起点
    int j = mid + 1;   // 右子数组起点
    int k = 0;         // 临时数组索引

    // 合并两个有序数组
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        }
        else {
            tmp[k++] = a[j++];
        }
    }

    // 如果左子数组有剩余，直接拷贝
    while (i <= mid) {
        tmp[k++] = a[i++];
    }

    // 如果右子数组有剩余，直接拷贝
    while (j <= right) {
        tmp[k++] = a[j++];
    }

    // 将临时数组中的元素拷贝回原数组
    for (i = 0; i < k; ++i) {
        a[left + i] = tmp[i];
    }
}

// 归并排序主函数
void MergeSort(int* a, int left, int right, int* tmp) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // 对左半部分排序
        MergeSort(a, left, mid, tmp);

        // 对右半部分排序
        MergeSort(a, mid + 1, right, tmp);

        // 合并两部分
        Merge(a, left, mid, right, tmp);
    }
}

// 辅助函数
void MergeSortWrapper(int* a, int n) {
    int* tmp = (int*)malloc(n * sizeof(int));  // 分配辅助空间
    if (tmp == NULL) {
        perror("Memory allocation failed");
        return;
    }

    MergeSort(a, 0, n - 1, tmp);
    free(tmp);  // 释放辅助空间
}

void PrintArray(int* a, int n) {
    if (a == NULL || n <= 0) {
        return; // 如果数组为空或无元素，则直接返回
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n"); // 输出换行符，保持格式整齐
}
 int main() {
        int a[] = { 1,5,9,8,7,4,6,2,3,44,55,11,23,58 };
        PrintArray(a, sizeof(a) / sizeof(int));
        MergeSortWrapper(a, sizeof(a) / sizeof(int));
        PrintArray(a, sizeof(a) / sizeof(int));
        return 0;
    }