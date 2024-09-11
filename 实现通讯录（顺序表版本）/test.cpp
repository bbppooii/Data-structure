#define _CRT_SECURE_NO_WARNINGS 1
#include "qwe.h"
void menu() {
	printf("*****************通讯录***************\n");
	printf("*******1.添加联系人  2.删除联系人*****\n");//ctrl+d
	printf("*******3.修改联系人  4.查找联系人*****\n");//ctrl+d
	printf("*******5.查看通讯录  0.  退 出  ******\n");//ctrl+d
	printf("**************************************\n");
}
int main() {
	SL con;
	int qwe = 0;
	menu();
	InitContact(&con);

	
	do {
		scanf("%d",&qwe);
		switch (qwe)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			ModifyContact(&con);
			break;
		case 4:
			FindContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		default:
			break;
		}
	} while (qwe != 0);
	DestroyContact(&con);
	return 0;
}