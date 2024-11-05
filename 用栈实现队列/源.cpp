#define _CRT_SECURE_NO_WARNINGS 1
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;
void STInit(ST* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void STDestroy(ST* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

// Õ»¶¥
// 11:55
void STPush(ST* ps, STDataType x)
{
	assert(ps);

	// ÂúÁË£¬ À©ÈÝ
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}

		ps->a = tmp;
		ps->capacity = newcapacity;
	}

	ps->a[ps->top] = x;
	ps->top++;
}

void STPop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));
	ps->top--;
}

STDataType STTop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	return ps->a[ps->top - 1];
}

int STSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

int STEmpty(ST* ps)
{
	assert(ps);
	if (ps->top == 0) {
		return 1;
	}
	else {
		return 0;
	}
}


typedef struct {
	ST pushst;
	ST popst;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* obj = malloc(sizeof(MyQueue));
	STInit(&obj->pushst);
	STInit(&obj->popst);
	return obj;
}

void myQueuePush(MyQueue* obj, int x) {
	STPush(&obj->pushst, x);
}

int myQueuePop(MyQueue* obj) {
	int front = myQueuePeek(obj);
	STPop(&obj->popst);
	return front;
}

int myQueuePeek(MyQueue* obj) {
	if (STEmpty(&obj->popst)) {
		while (!STEmpty(&obj->pushst)) {
			int top = STTop(&obj->pushst);
			STPop(&obj->pushst);
			STPush(&obj->popst, top);
		}
	}
	return STTop(&obj->popst);
}

bool myQueueEmpty(MyQueue* obj) {
	return STEmpty(&obj->pushst) && STEmpty(&obj->popst);
}

void myQueueFree(MyQueue* obj) {
	STDestroy(&obj->pushst);
	STDestroy(&obj->popst);
	free(obj);
}