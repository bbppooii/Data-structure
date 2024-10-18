#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void menu() {
	printf("*****************通讯录***************\n");
	printf("*******1.添加联系人  2.删除联系人*****\n");//ctrl+d
	printf("*******3.查看通讯录  4.查找联系人*****\n");//ctrl+d
	printf("*******5.修改联系人  0.  退 出  ******\n");//ctrl+d
	printf("**************************************\n");
}
int main() {
    contact* con; // 定义通讯录链表头指针
    InitContact(&con); // 初始化通讯录
    menu();
    int choice;
    do {
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            AddContact(&con); // 添加联系人
            break;
        case 2:
            DelContact(&con); // 删除联系人
            break;
        case 3:
            ShowContact(&con); // 展示通讯录
            break;
        case 4:
            FindContact(&con); // 查找联系人
            break;
        case 5:
            ModifyContact(&con); // 修改联系人
            break;
        case 0:
            DestroyContact(&con); // 退出系统时清空通讯录
            printf("退出系统\n");
            break;
        default:
            printf("无效的选择\n");
        }
    } while (choice != 0);

    return 0;
}