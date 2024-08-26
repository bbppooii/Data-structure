#include"SeqList.h"
//初始化和销毁
void SLInit(SL* ps) {
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

void SLCheckCapacity(SL* ps) {
	if (ps->size == ps->capacity) {
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));
		if (tmp == NULL) {
			perror("realloc fail!");
			exit(1);
		}
		//扩容成功
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
}

//顺序表的头部/尾部插入
void SLPushBack(SL* ps, SLDataType x) {
	//断言--粗暴的解决方式
	//assert(ps != NULL);
	assert(ps);

	//if判断--温柔的解决方式
	//if (ps == NULL) {
	//	return;
	//}

	//空间不够，扩容
	SLCheckCapacity(ps);

	//空间足够，直接插入
	ps->arr[ps->size++] = x;
	//ps->size++;
}
void SLPushFront(SL* ps, SLDataType x) {
	assert(ps);

	//判断是否扩容
	SLCheckCapacity(ps);

	//旧数据往后挪动一位
	for (int i = ps->size; i > 0; i--) //i = 1
	{
		ps->arr[i] = ps->arr[i - 1]; //ps->arr[1] = ps->arr[0]
	}
	ps->arr[0] = x;
	ps->size++;
}

//顺序表的头部/尾部删除
void SLPopBack(SL* ps) {
	assert(ps);
	assert(ps->size);

	//顺序表不为空
	//ps->arr[ps->size - 1] = -1;
	ps->size--;
}
void SLPopFront(SL* ps) {
	assert(ps);
	assert(ps->size);

	//不为空执行挪动操作
	for (int i = 0; i < ps->size-1 ;i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//指定位置之前插入数据
void SLInsert(SL* ps, int pos, SLDataType x) {
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	
	SLCheckCapacity(ps);

	//pos及之后的数据往后挪动一位，pos空出来
	for (int i = ps->size; i > pos ;i--)
	{
		ps->arr[i] = ps->arr[i - 1]; //ps->arr[pos+1] = ps->arr[pos]
	}
	ps->arr[pos] = x;
	ps->size++;
}
//删除指定位置数据
void SLErase(SL* ps, int pos) {
	assert(ps);
	assert(pos >= 0 && pos < ps->size); 

	//pos以后的数据往前挪动一位
	for (int i = pos;i < ps->size-1;i++)
	{
		ps->arr[i] = ps->arr[i + 1];//ps->arr[i-2] = ps->arr[i-1];
	}
	ps->size--;
}

void SLDestroy(SL* ps) {

}

void SLPrint(SL* ps) {
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}