#include"SeqList.h"

void slTest01() {
	SL sl;
	SLInit(&sl);

	//测试尾插
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);//ctrl+d快速复制
	SLPushBack(&sl, 4);
	SLPrint(&sl);      //1 2 3 4
	//SLPushBack(&sl, 5);
	//SLPrint(&sl);
	//
	////头插
	//SLPushFront(&sl, 5);
	//SLPushFront(&sl, 6);
	//SLPushFront(&sl, 7);
	//SLPrint(&sl);       //7 6 5 1 2 3 4
	//
	//尾删
	//SLPopBack(&sl);
	//SLPopBack(&sl);
	//SLPopBack(&sl);
	//SLPopBack(&sl);
	//SLPrint(&sl);   //1 2
	//
	//SLPopFront(&sl);
	//SLPopFront(&sl);
	//SLPopFront(&sl);
	//SLPopFront(&sl);
	//SLPopFront(&sl);
	//SLPrint(&sl);   //3 4
	//
	////指定位置插入
	//SLInsert(&sl, 0, 100);
	//SLPrint(&sl); //100 1 2 3 4
	//SLInsert(&sl, sl.size, 200);
	//SLPrint(&sl); //100 1 2 3 4 200
	//
	//SLInsert(&sl, 100, 300);
	//SLPrint(&sl);

	//SLErase(&sl, 0);
	//SLPrint(&sl);  //2 3 4
	//SLErase(&sl, sl.size - 1);
	SLErase(&sl, 1);
	SLPrint(&sl);//1 3 4
}

int main()
{
	slTest01();
	return 0;
}
