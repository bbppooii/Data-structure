#define _CRT_SECURE_NO_WARNINGS 1
#include "t.h"
// 初始化栈 
void STInit(Stack* ps) {
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
// 入栈 
void STPush(Stack* ps, STDataType data) {
	assert(ps);
	if (ps->top == ps->capacity) {
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL) {
			perror("realloc fail");
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = data;
	ps->top++;
}
// 出栈 
void STPop(Stack* ps) {
	assert(ps);
	assert(!STEmpty(ps));
	ps->top--;
}
// 获取栈顶元素 
STDataType STTop(Stack* ps) {
	assert(ps);
	assert(!STEmpty(ps));
	return ps->a[ps->top - 1];
}
// 获取栈中有效元素个数 
int STSize(Stack* ps) {
	assert(ps);
	return ps->top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
bool STEmpty(Stack* ps){
	assert(ps);
	return ps->top == 0;
}
// 销毁栈 
void STDestroy(Stack* ps) {
	assert(ps);
	free(ps->a);
	ps->capacity = ps->top = 0;
}