#define _CRT_SECURE_NO_WARNINGS 1
#include "qwe.h"
void menu() {
	printf("*****************ͨѶ¼***************\n");
	printf("*******1.�����ϵ��  2.ɾ����ϵ��*****\n");//ctrl+d
	printf("*******3.�޸���ϵ��  4.������ϵ��*****\n");//ctrl+d
	printf("*******5.�鿴ͨѶ¼  0.  �� ��  ******\n");//ctrl+d
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