#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
// 交换两个元素的位置
void Swap(int* p1, int* p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
// 打印数组
void PrintArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
// 快速排序函数
void QuickSort(int* a, int left, int right) {
    // 如果区间无效或只剩一个元素，直接返回
    if (left >= right) {
        return;
    }
    // 设置初始基准值的位置（选取左边的元素作为基准值）
    int prev = left;  // prev 用于标记小于基准值的区域的末尾位置
    int cur = prev + 1;  // cur 用于遍历数组
    int pivotIndex = left;  // 基准值的位置（初始化为左边界）
    // 遍历整个区间，进行分区
    while (cur <= right) {
        // 如果当前元素小于基准值并且 prev 位置还没有与 cur 交换
        if (a[cur] < a[pivotIndex] && ++prev != cur) {
            // 如果符合条件，则交换 a[prev] 和 a[cur]
            Swap(&a[prev], &a[cur]);
        }
        ++cur;  // 继续向右移动 cur 指针
    }
    // 最后将基准值与 prev 位置的元素交换，将基准值放到正确的位置
    Swap(&a[prev], &a[pivotIndex]);
    pivotIndex = prev;  // 更新基准值位置
    // 递归处理左右两个子区间
    QuickSort(a, left, pivotIndex - 1);  // 处理左区间
    QuickSort(a, pivotIndex + 1, right);  // 处理右区间
}
int main() {
    // 初始化一个数组
    int a[] = { 7, 5, 6, 4, 8, 9, 2, 1, 3, 0 };
    int n = sizeof(a) / sizeof(a[0]);  // 数组的元素个数
    // 输出排序前的数组
    printf("Before sorting:\n");
    PrintArray(a, n);
    // 调用快速排序
    QuickSort(a, 0, n - 1);
    // 输出排序后的数组
    printf("After sorting:\n");
    PrintArray(a, n);
    return 0;
}
