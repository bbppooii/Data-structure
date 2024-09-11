#define _CRT_SECURE_NO_WARNINGS 1
#include "qwe.h"
void SLInit(SL* ps) {
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
//����
void SLDestroy(SL* ps) {
	assert(ps);
	if (ps->a) {
		free(ps->a);
	}
	ps->a = NULL;
	ps->size = ps->capacity - 0;
}
//��ӡ
void SLPrint(SL* ps) {
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//����
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
//β��
void SLPushBack(SL* ps, SLDataType x) {
	assert(ps);
	SLCheckCapacity(ps);
	ps->a[ps->size++] = x;
}
//βɾ
void SLPopBack(SL* ps) {
	assert(ps);
	assert(ps->size);
	ps->size--;
}
//ͷ��
void SLPushFront(SL* ps, SLDataType x) {
	assert(ps);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > 0; i--) {
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}
//ͷɾ
void SLPopFront(SL* ps) {
	assert(ps);
	assert(ps->size);
	for (int i = 0; i < ps->size - 1; i++) {
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
//ָ��λ��֮ǰ����
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
//ɾ��ָ��λ������
void SLErase(SL* ps, int pos) {
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	for (int i = pos; i < ps->size - 1; i++) {
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
//����
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
//��ʼ��ͨѶ¼
void InitContact(contact* con) {
	SLInit(con);
}
//���ͨѶ¼����
void AddContact(contact* con) {
	Info info;
	printf("����");
	scanf("%s", info.name);
	printf("סַ");
	scanf("%s", info.addr);
	printf("����");
	scanf("%d", &info.age);
	printf("�Ա�");
	scanf("%s", info.gender);
	printf("�绰");
	scanf("%s", info.tel);
	SLPushBack(con, info);
}
//ɾ��ͨѶ¼����
void DelContact(contact* con) {
	char name[NAME_MAX];
	printf("����Ҫɾ�����û���");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0) {
		printf("����");
		return;
	}
	SLErase(con, find);
	printf("ɾ���ɹ�\n");
}
//չʾͨѶ¼����
void ShowContact(contact* con) {
	printf("%s %s %s %s %s\n", "����", "�Ա�", "����", "�绰", "סַ");

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
//����ͨѶ¼����
void FindContact(contact* con) {
	char name[NAME_MAX];
	printf("����Ҫ���ҵ��û���");
	scanf("%s",name);
	int find = FindByName(con,name);
	if (find < 0) {
		printf("����");
		return;
	}
	printf("%s %s %s %s %s\n", "����", "�Ա�", "����", "�绰", "סַ");
	printf("%s %s %d %s %s\n",
		con->a[find].name,
		con->a[find].gender,
		con->a[find].age,
		con->a[find].tel,
		con->a[find].addr);
}
//�޸�ͨѶ¼����
void ModifyContact(contact* con) {
	char name[NAME_MAX];
	printf("����Ҫ�޸ĵ��û���");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0) {
		printf("����");
		return;
	}
	printf("������������\n");
	scanf("%s", con->a[find].name);
	printf("���������䣺\n");
	scanf("%d", &con->a[find].age);
	printf("�������Ա�\n");
	scanf("%s", con->a[find].gender);
	printf("������绰��\n");
	scanf("%s", con->a[find].tel);
	printf("�������ַ��\n");
	scanf("%s", con->a[find].addr);
	printf("��ϵ���޸ĳɹ���\n");
}
//����ͨѶ¼����
void DestroyContact(contact* con) {
	SLDestroy(con);
}