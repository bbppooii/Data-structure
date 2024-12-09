#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;		// 栈顶
	int capacity;  // 容量 
}Stack,ST;
// 初始化栈 
void STInit(Stack* ps);
// 入栈 
void STPush(Stack* ps, STDataType data);
// 出栈 
void STPop(Stack* ps);
// 获取栈顶元素 
STDataType STTop(Stack* ps);
// 获取栈中有效元素个数 
int STSize(Stack* ps);
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
bool STEmpty(Stack* ps);
// 销毁栈 
void STDestroy(Stack* ps);
//交换
void Swap(int* p1, int* p2);
//打印
void _printf(int* a, int n);
//快排
void QuickSortNonR(int* a, int left, int right);