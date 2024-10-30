#define _CRT_SECURE_NO_WARNINGS 1
#include "t.h"
// ��ʼ��ջ 
void STInit(Stack* ps) {
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
// ��ջ 
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
// ��ջ 
void STPop(Stack* ps) {
	assert(ps);
	assert(!STEmpty(ps));
	ps->top--;
}
// ��ȡջ��Ԫ�� 
STDataType STTop(Stack* ps) {
	assert(ps);
	assert(!STEmpty(ps));
	return ps->a[ps->top - 1];
}
// ��ȡջ����ЧԪ�ظ��� 
int STSize(Stack* ps) {
	assert(ps);
	return ps->top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
bool STEmpty(Stack* ps){
	assert(ps);
	return ps->top == 0;
}
// ����ջ 
void STDestroy(Stack* ps) {
	assert(ps);
	free(ps->a);
	ps->capacity = ps->top = 0;
}