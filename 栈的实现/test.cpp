#define _CRT_SECURE_NO_WARNINGS 1
#include"t.h"

int main()
{
	Stack s;
	STInit(&s);
	STPush(&s, 1);
	STPush(&s, 2);
	STPush(&s, 3);

	int top = STTop(&s);
	printf("%d ", top);
	STPop(&s);

	STPush(&s, 4);
	STPush(&s, 5);

	while (!STEmpty(&s))
	{
		int top = STTop(&s);
		printf("%d ", top);
		STPop(&s);
	}

	STDestroy(&s);

	return 0;
}