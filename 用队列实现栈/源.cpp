#define _CRT_SECURE_NO_WARNINGS 1
typedef int QDataType;
typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

void QueueInit(Queue* q) {
	assert(q);
	q->phead = NULL;
	q->ptail = NULL;
	q->size = 0;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data) {
	assert(q);
	QNode* Newnode = (QNode*)malloc(sizeof(QNode));
	if (Newnode == NULL) {
		perror("malloc fail");
		return;
	}
	Newnode->val = data;
	Newnode->next = NULL;
	if (q->ptail) {
		q->ptail->next = Newnode;
		q->ptail = Newnode;
	}
	else {
		q->phead = q->ptail = Newnode;
	}
	q->size++;
}
// 队头出队列 
void QueuePop(Queue* q) {
	assert(q);
	assert(q->phead != NULL); // 队列为空则不能出队
	QNode* next = q->phead->next;
	free(q->phead);          // 释放头节点
	q->phead = next;         // 更新队头
	if (q->phead == NULL) {  // 队列为空时，更新尾指针
		q->ptail = NULL;
	}
	q->size--;
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q) {
	assert(q);
	assert(q->phead != NULL);
	return q->phead->val;
}
// 获取队列队尾元素		
QDataType QueueBack(Queue* q) {
	assert(q);
	assert(q->ptail != NULL);
	return q->ptail->val;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q) {
	assert(q);
	return q->size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q) {
	assert(q);
	if (q->size == 0) {
		return 1;
	}
	return 0;
}
// 销毁队列 
void QueueDestroy(Queue* q) {
	assert(q);
	QNode* cur = q->phead;
	while (cur) {
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->ptail = q->phead = NULL;
	q->size = 0;
}



typedef struct {
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);
	return pst;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1)) {
		QueuePush(&obj->q1, x);
	}
	else {
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	Queue* pEmptyQ = &obj->q1;
	Queue* pNonEmptyQ = &obj->q2;
	if (!QueueEmpty(&obj->q1)) {
		pEmptyQ = &obj->q2;
		pNonEmptyQ = &obj->q1;
	}
	while (QueueSize(pNonEmptyQ) > 1) {
		int front = QueueFront(pNonEmptyQ);
		QueuePush(pEmptyQ, front);
		QueuePop(pNonEmptyQ);
	}
	int front = QueueFront(pNonEmptyQ);
	QueuePop(pNonEmptyQ);
	return front;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1)) {
		return QueueBack(&obj->q1);
	}
	else {
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}