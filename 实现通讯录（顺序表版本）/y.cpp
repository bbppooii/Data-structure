#define _CRT_SECURE_NO_WARNINGS 1
#include "qwe.h"
void SLInit(SL* ps) {
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
//销毁
void SLDestroy(SL* ps) {
	assert(ps);
	if (ps->a) {
		free(ps->a);
	}
	ps->a = NULL;
	ps->size = ps->capacity - 0;
}
//打印
void SLPrint(SL* ps) {
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//扩容
void SLCheckCapacity(SL* ps) {
	if (ps->size == ps->capacity) {
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* qwe = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (qwe == NULL) {
			perror("reacoll fail!");
			exit(0);
		}
		ps->a = qwe;
		ps->capacity = newcapacity;
	}
}
//尾插
void SLPushBack(SL* ps, SLDataType x) {
	assert(ps);
	SLCheckCapacity(ps);
	ps->a[ps->size++] = x;
}
//尾删
void SLPopBack(SL* ps) {
	assert(ps);
	assert(ps->size);
	ps->size--;
}
//头插
void SLPushFront(SL* ps, SLDataType x) {
	assert(ps);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > 0; i--) {
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}
//头删
void SLPopFront(SL* ps) {
	assert(ps);
	assert(ps->size);
	for (int i = 0; i < ps->size - 1; i++) {
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
//指定位置之前插入
void SLInsert(SL* ps, int pos, SLDataType x) {
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > pos; i--) {
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}
//删除指定位置数据
void SLErase(SL* ps, int pos) {
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	for (int i = pos; i < ps->size - 1; i++) {
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
//查找
void SLFind(SL* ps, int x) {
	assert(ps);
	assert(x >= 0 && x <= ps->size);
	printf("%d", ps->a[x]);
}
int FindByName(SL* con, char name[]) {
	for (int i = 0; i < con->size; i++) {
		if (strcmp(con->a[i].name, name) == 0)
			return i;
	}
	return -1;
}
//初始化通讯录
void InitContact(contact* con) {
	SLInit(con);
}
//添加通讯录数据
void AddContact(contact* con) {
	Info info;
	printf("姓名");
	scanf("%s", info.name);
	printf("住址");
	scanf("%s", info.addr);
	printf("年龄");
	scanf("%d", &info.age);
	printf("性别");
	scanf("%s", info.gender);
	printf("电话");
	scanf("%s", info.tel);
	SLPushBack(con, info);
}
//删除通讯录数据
void DelContact(contact* con) {
	char name[NAME_MAX];
	printf("输入要删除的用户名");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0) {
		printf("错误");
		return;
	}
	SLErase(con, find);
	printf("删除成功\n");
}
//展示通讯录数据
void ShowContact(contact* con) {
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "住址");

	for (int i = 0; i < con->size; i++)
	{
		printf("%s %s %d %s %s\n",
			con->a[i].name,
			con->a[i].gender,
			con->a[i].age,
			con->a[i].tel,
			con->a[i].addr
		);
	}
}
//查找通讯录数据
void FindContact(contact* con) {
	char name[NAME_MAX];
	printf("输入要查找的用户名");
	scanf("%s",name);
	int find = FindByName(con,name);
	if (find < 0) {
		printf("错误");
		return;
	}
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "住址");
	printf("%s %s %d %s %s\n",
		con->a[find].name,
		con->a[find].gender,
		con->a[find].age,
		con->a[find].tel,
		con->a[find].addr);
}
//修改通讯录数据
void ModifyContact(contact* con) {
	char name[NAME_MAX];
	printf("输入要修改的用户名");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0) {
		printf("错误");
		return;
	}
	printf("请输入姓名：\n");
	scanf("%s", con->a[find].name);
	printf("请输入年龄：\n");
	scanf("%d", &con->a[find].age);
	printf("请输入性别：\n");
	scanf("%s", con->a[find].gender);
	printf("请输入电话：\n");
	scanf("%s", con->a[find].tel);
	printf("请输入地址：\n");
	scanf("%s", con->a[find].addr);
	printf("联系人修改成功！\n");
}
//销毁通讯录数据
void DestroyContact(contact* con) {
	SLDestroy(con);
}