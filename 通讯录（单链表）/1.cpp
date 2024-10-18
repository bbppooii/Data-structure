#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
struct SListNode {
	PeoInfo data;
	struct SListNode* next;
};
//初始化通讯录
void InitContact(contact** con) {
	*con = NULL;
}
//添加通讯录数据
void AddContact(contact** con) {
	contact* newNode = (contact*)malloc(sizeof(contact));
	if (!newNode) {
		printf("分配失败");
		return;
	}
    printf("请输入姓名: ");
    scanf("%s", newNode->data.name);
    printf("请输入性别: ");
    scanf("%s", newNode->data.sex);
    printf("请输入年龄: ");
    scanf("%d", &newNode->data.age);
    printf("请输入电话: ");
    scanf("%s", newNode->data.tel);
    printf("请输入地址: ");
    scanf("%s", newNode->data.addr);
    newNode->next = *con;
    *con = newNode;
    printf("联系人添加成功!\n");
}
//删除通讯录数据
void DelContact(contact** con) {
    if (*con == NULL) {
        printf("通讯录为空，无法删除\n");
        return;
    }
    char name[100];
    printf("请输入要删除的姓名: ");
    scanf("%s", name);
    contact* prev = NULL;
    contact* cur = *con;
    while (cur != NULL) {
        if (strcmp(cur->data.name, name) == 0) {
            if (prev == NULL) {
                *con = cur->next;
            }
            else {
                prev->next = cur->next;
            }
            free(cur);
            printf("联系人已删除!\n");
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    printf("未找到该联系人!\n");
}
//展示通讯录数据
void ShowContact(contact** con) {
    if (*con == NULL) {
        printf("通讯录为空\n");
        return;
    }
    contact* cur = *con;
    while (cur != NULL) {
        printf("姓名: %s, 性别: %s, 年龄: %d, 电话: %s, 地址: %s\n",
            cur->data.name, cur->data.sex, cur->data.age, cur->data.tel, cur->data.addr);
        cur = cur->next;
    }
}
//查找通讯录数据
void FindContact(contact** con) {
    if (*con == NULL) {
        printf("通讯录为空\n");
        return;
    }
    char name[100];
    printf("请输入要查找的姓名: ");
    scanf("%s", name);
    contact* cur = *con;
    while (cur != NULL) {
        if (strcmp(cur->data.name, name) == 0) {
            printf("姓名: %s, 性别: %s, 年龄: %d, 电话: %s, 地址: %s\n",
                cur->data.name, cur->data.sex, cur->data.age, cur->data.tel, cur->data.addr);
            return;
        }
        cur = cur->next;
    }
    printf("未找到该联系人!\n");
}
//修改通讯录数据
void ModifyContact(contact** con) {
    if (*con == NULL) {
        printf("通讯录为空\n");
        return;
    }
    char name[100];
    printf("请输入要修改的姓名: ");
    scanf("%s", name);
    contact* cur = *con;
    while (cur != NULL) {
        if (strcmp(cur->data.name, name) == 0) {
            printf("请输入新的姓名: ");
            scanf("%s", cur->data.name);
            printf("请输入新的性别: ");
            scanf("%s", cur->data.sex);
            printf("请输入新的年龄: ");
            scanf("%d", &cur->data.age);
            printf("请输入新的电话: ");
            scanf("%s", cur->data.tel);
            printf("请输入新的地址: ");
            scanf("%s", cur->data.addr);
            printf("联系人信息已修改!\n");
            return;
        }
        cur = cur->next;
    }
    printf("未找到该联系人!\n");
}
//销毁通讯录数据
void DestroyContact(contact** con) {
    contact* cur = *con;
    while (cur !=NULL){
        contact* next = cur->next;
        free(cur);
        cur = next;
    }
    *con = NULL;
    printf("通讯录已清空!\n");
}