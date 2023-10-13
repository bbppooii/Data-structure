#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREATEMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int status;
typedef struct {
	int* base;
	int* top;
	int stacksize;
}sqstack;
status initstack(sqstack& s)
{
	s.base = new int[STACK_INIT_SIZE];
	if (!s.base)
		exit(OVERFLOW);
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
	return OK;
}
status push(sqstack& s, char e) {
	if (s.top - s.base >= s.stacksize)
		return ERROR;
	*s.top++ = e;
	return OK;
}
status pop(sqstack& s, int& e) {
	if (s.base == s.top)
		return ERROR;
	e = *--s.top;
	return OK;
}

status gettop(sqstack& s, int& e) {
	if (s.base == s.top)
		return ERROR;
	e = *(s.top - 1);
	return OK;

}
status printstack(sqstack& s) {
	if (s.base == s.top) {
		printf("空栈\n");
		return ERROR;
	}
	else
		printf("出栈：");
	for (; s.base != s.top; s.base++) {
		printf("%c  ", *s.base);
	}
	return OK;
}
int main() {
	sqstack s;
	int e;
	int x = 0;
	if (initstack(s))
		printf("初始化成功 !");
	push(s, 'a');
	push(s, 'b');
	push(s, 'c');
	push(s, 'd');
	push(s, 'e');
	if (gettop(s, e))
		printf("栈顶元素是 : %c\n", e);
	else
		printf("获得栈顶元素失败\n");
	printstack(s);
	return 0;
}
