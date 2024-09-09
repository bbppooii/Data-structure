#define _CRT_SECURE_NO_WARNINGS 1
#include "s.h"
//初始化
void SLInit(SL* ps) {
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
//销毁
void SLDestroy(SL* ps) {
	assert(ps);
	if (ps->a) {
		free(ps->a);
	}
	ps->a = NULL;
	ps->size = ps->capacity - 0;
}
//打印
void SLPrint(SL* ps) {
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//扩容
void SLCheckCapacity(SL* ps) {
	if (ps->size == ps->capacity) {
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* qwe = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (qwe == NULL) {
			perror("reacoll fail!");
			exit(0);
		}
		ps->a = qwe;
		ps->capacity = newcapacity;
	}
}
//尾插
void SLPushBack(SL* ps, SLDataType x) {
	assert(ps);
	SLCheckCapacity(ps);
	ps->a[ps->size++] = x;
}
//尾删
void SLPopBack(SL* ps) {
	assert(ps);
	assert(ps->size);
	ps->size--;
}
//头插
void SLPushFront(SL* ps, SLDataType x) {
	assert(ps);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > 0; i--) {
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}
//头删
void SLPopFront(SL* ps) {
	assert(ps);
	assert(ps->size);
	for (int i = 0; i < ps->size - 1; i++) {
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
//指定位置之前插入
void SLInsert(SL* ps, int pos, SLDataType x) {
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > pos; i--) {
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}
//删除指定位置数据
void SLErase(SL* ps, int pos) {
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	for (int i = pos; i < ps->size - 1; i++) {
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
//查找
void SLFind(SL* ps, SLDataType x) {
	assert(ps);
	assert(x >= 0 && x <= ps->size);
	printf("%d",ps->a[x]);
}