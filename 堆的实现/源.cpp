#define _CRT_SECURE_NO_WARNINGS 1
#include "t.h"
// 堆的初始化
void HeapInit(Heap* hp) {
	assert(hp);
	hp->a = NULL;
	hp->size = 0;
	hp->capacity = 0;
}
// 堆的销毁
void HeapDestory(Heap* hp) {
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->size = 0;
	hp->capacity = 0; 
}
void swap(HPDataType* px, HPDataType* py) {
	HPDataType newdata = *px;
	*px = *py;
	*py = newdata;
}
void AdjustUp(HPDataType* a,int child){
	int parent = (child - 1) / 2;
	while (child > 0){
		if (a[child] < a[parent]) {
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}else {
			break;
		}
	}
}
void AdjustDown(HPDataType* a, int n, int parent) {
	int child = parent * 2 + 1;
	while (child < n){
		if (child + 1 < n && a[child] > a[child + 1]) {
			++child;
		}
		if (a[child] < a[parent]) {
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}else {
			break;
		}
	}
	
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x) {
	assert(hp);
	if (hp->size == hp->capacity) {
		int newcapaity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* tmp =(HPDataType*) realloc(hp->a, sizeof(HPDataType) * newcapaity);
		if (tmp == NULL) {
			perror("realloc fail");
			return;
		}
		hp->a = tmp;
		hp->capacity = newcapaity;
	}
	hp->a[hp->size] = x;
	hp->size++;
	AdjustUp(hp->a, hp->size - 1);
}
// 堆的删除
void HeapPop(Heap* hp) {
	assert(hp);
	assert(hp->size > 0);
	swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->a, hp->size, 0);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp) {
	assert(hp);
	return hp->a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp){
	assert(hp);
	return hp->size;
}
// 堆的判空
bool HeapEmpty(Heap* hp) {
	assert(hp);	
	return hp->size == 0;
}