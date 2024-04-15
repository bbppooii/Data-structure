
#include<stdlib.h>
#include <iostream>
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREATEMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int status;
typedef int SElemType;
typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}sqstack;
status initstack(sqstack& s){
	s.base = new SElemType[STACK_INIT_SIZE];
	if (!s.base)
		exit(OVERFLOW);
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
	return OK;
}
status push(sqstack& s, SElemType e) {
	if (s.top - s.base >= s.stacksize)
		return ERROR;
	*s.top++ = e;
	return OK;
}
status pop(sqstack& s, SElemType& e) {
	if (s.base == s.top)
		return ERROR;
	e = *--s.top;
	return OK;
}
status gettop(sqstack& s, SElemType& e) {
	if (s.base == s.top)
		return ERROR;
	e = *(s.top - 1);
	return OK;
}
status printstack(sqstack& s) {
	char e;
	if (s.base == s.top) {
		printf("��ջ\n");
		return ERROR;
	}
	else
		printf("��ǰΪ��");
	for (; s.base != s.top; s.base++) {
		e = *s.base;
		printf("%d  ", e);
	}
	return OK;
}
int main() {
	sqstack s;
	SElemType e;
	int x = 0;
	if (initstack(s))
		printf("��ʼ���ɹ� !\n");
	for (; x < 5;) {
		push(s, x);
		x++;
	}
	if (gettop(s, e))
		printf("ջ��Ԫ���� : %d\n", e);
	else
		printf("���ջ��Ԫ��ʧ��\n");
	pop(s, e);
	printf("��ջ%d\n", e);
	printstack(s);
	return 0;
}