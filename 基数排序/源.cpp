#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 获取数组中的最大值
int GetMax(int* a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

// 对数组按照某个位数进行计数排序
void CountingSortForRadix(int* a, int n, int exp) {
    int* output = (int*)malloc(n * sizeof(int));
    int count[10] = { 0 }; // 因为是按位排序，只有 0-9 共 10 个数字

    // 统计每个位上的出现次数
    for (int i = 0; i < n; i++) {
        int digit = (a[i] / exp) % 10;
        count[digit]++;
    }

    // 计算累积计数
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 按当前位排序，将数据放入输出数组
    for (int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }

    // 将排序结果复制回原数组
    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }

    free(output);
}

// 基数排序主函数
void RadixSort(int* a, int n) {
    int max = GetMax(a, n); // 找到数组中最大值
    for (int exp = 1; max / exp > 0; exp *= 10) {
        CountingSortForRadix(a, n, exp);
    }
}

// 测试函数
int main() {
    int a[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    RadixSort(a, n);

    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
