#define _CRT_SECURE_NO_WARNINGS 1
#include "t.h"
// 插入排序实现
void InsertSort(int* a, int n) {
    if (a == NULL || n <= 1) {
        return; // 如果数组为空或元素个数不足1，则直接返回
    }
    // 遍历每个元素，将其插入到已经排好序的部分
    for (int i = 0; i < n - 1; i++) {
        int end = i;               // 已排序部分的最后一个位置
        int tmp = a[end + 1];      // 待插入的元素
        // 从后往前遍历，找到插入位置
        while (end >= 0 && a[end] > tmp) {
            a[end + 1] = a[end];   // 数据后移，为插入腾出位置
            end--;
        }
        a[end + 1] = tmp;          // 插入到正确位置
    }
}
// 打印数组
void PrintArray(int* a, int n) {
    if (a == NULL || n <= 0) {
        return; // 如果数组为空或无元素，则直接返回
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n"); // 输出换行符，保持格式整齐
}