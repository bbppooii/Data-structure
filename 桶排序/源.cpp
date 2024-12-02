#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 定义桶的结构
typedef struct Bucket {
    int* data;   // 动态数组
    int count;   // 当前存储的元素个数
    int capacity; // 桶的容量
} Bucket;

// 初始化桶
void InitBucket(Bucket* bucket) {
    bucket->capacity = 10; // 初始容量
    bucket->data = (int*)malloc(bucket->capacity * sizeof(int));
    bucket->count = 0;
}

// 向桶中添加元素
void AddToBucket(Bucket* bucket, int value) {
    if (bucket->count == bucket->capacity) {
        bucket->capacity *= 2;
        bucket->data = (int*)realloc(bucket->data, bucket->capacity * sizeof(int));
    }
    bucket->data[bucket->count++] = value;
}

// 桶内使用插入排序
void InsertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 桶排序函数
void BucketSort(int* arr, int n) {
    if (n <= 1) return;

    // 找到数组中的最大值和最小值
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int bucketCount = 10; // 默认分成10个桶
    int range = max - min + 1;
    int bucketRange = range / bucketCount + 1;

    // 初始化桶数组
    Bucket* buckets = (Bucket*)malloc(bucketCount * sizeof(Bucket));
    for (int i = 0; i < bucketCount; i++) {
        InitBucket(&buckets[i]);
    }

    // 将数据分配到桶中
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / bucketRange;
        AddToBucket(&buckets[bucketIndex], arr[i]);
    }

    // 对每个桶中的数据排序并合并结果
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (buckets[i].count > 0) {
            InsertionSort(buckets[i].data, buckets[i].count);
            for (int j = 0; j < buckets[i].count; j++) {
                arr[index++] = buckets[i].data[j];
            }
        }
        free(buckets[i].data);
    }

    // 释放桶数组
    free(buckets);
}

// 测试函数
int main() {
    int arr[] = { 42, 32, 33, 52, 37, 47, 51, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    BucketSort(arr, n);

    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
