#define _CRT_SECURE_NO_WARNINGS 1
#include "t.h"
// 初始化栈
void STInit(Stack* ps) {
    assert(ps);  // 确保栈指针不为空
    ps->a = NULL;  // 初始化栈底指针为空
    ps->top = 0;  // 栈顶索引初始化为0
    ps->capacity = 0;  // 初始容量为0
}
// 入栈
void STPush(Stack* ps, STDataType data) {
    assert(ps);  // 确保栈指针不为空
    // 如果栈满了，则扩容
    if (ps->top == ps->capacity) {
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;  // 初始化容量为4，之后容量翻倍
        STDataType* tmp = (STDataType*)realloc(ps->a, newcapacity * sizeof(STDataType));  // 重新分配内存
        if (tmp == NULL) {
            perror("realloc fail");  // 内存分配失败，打印错误信息
        }
        ps->a = tmp;  // 更新栈底指针
        ps->capacity = newcapacity;  // 更新栈容量
    }
    ps->a[ps->top] = data;  // 将数据压入栈顶
    ps->top++;  // 栈顶指针加1
}
// 出栈
void STPop(Stack* ps) {
    assert(ps);  // 确保栈指针不为空
    assert(!STEmpty(ps));  // 确保栈不为空
    ps->top--;  // 栈顶指针减1
}
// 获取栈顶元素
STDataType STTop(Stack* ps) {
    assert(ps);  // 确保栈指针不为空
    assert(!STEmpty(ps));  // 确保栈不为空
    return ps->a[ps->top - 1];  // 返回栈顶元素
}
// 获取栈中有效元素个数
int STSize(Stack* ps) {
    assert(ps);  // 确保栈指针不为空
    return ps->top;  // 返回栈顶指针，即栈中有效元素个数
}
// 检测栈是否为空
// 如果为空返回非零结果，如果不为空返回0
bool STEmpty(Stack* ps) {
    assert(ps);  // 确保栈指针不为空
    return ps->top == 0;  // 栈为空时返回1，否则返回0
}
// 销毁栈
void STDestroy(Stack* ps) {
    assert(ps);  // 确保栈指针不为空
    free(ps->a);  // 释放栈底指针的内存
    ps->capacity = ps->top = 0;  // 重置栈容量和栈顶指针
}
// 交换两个整数
void Swap(int* p1, int* p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
// 打印数组
void _printf(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);  // 打印数组元素
    }
}
// 非递归快速排序
void QuickSortNonR(int* a, int left, int right) {
    ST st;
    STInit(&st);  // 初始化栈
    STPush(&st, right);  // 将右边界入栈
    STPush(&st, left);  // 将左边界入栈
    // 循环栈中的区间进行排序
    while (!STEmpty(&st)) {
        int begin = STTop(&st);  // 获取当前区间的左边界
        STPop(&st);  // 弹出左边界
        int end = STTop(&st);  // 获取当前区间的右边界
        STPop(&st);  // 弹出右边界
        int keyi = begin;  // 选择基准元素的初始位置
        int cur = begin + 1;  // 当前元素指针
        int prev = begin;  // 上一个小于基准元素的位置
        // 对区间内的元素进行排序
        while (cur <= end) {
            if (a[cur] < a[keyi] && ++prev != cur)  // 如果当前元素小于基准元素，则交换
                Swap(&a[prev], &a[cur]);
            ++cur;
        }
        // 将基准元素放到正确的位置
        Swap(&a[keyi], &a[prev]);
        keyi = prev;  // 更新基准元素位置
        // 如果基准元素右边还有元素，继续排序右边区间
        if (keyi + 1 < end) {
            STPush(&st, end);
            STPush(&st, keyi + 1);
        }
        // 如果基准元素左边还有元素，继续排序左边区间
        if (keyi - 1 > begin) {
            STPush(&st, keyi - 1);
            STPush(&st, begin);
        }
    }
    STDestroy(&st);  // 销毁栈
}
