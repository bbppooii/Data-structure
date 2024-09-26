#define _CRT_SECURE_NO_WARNINGS 1
#include"to.h"
int main(){
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPopBack(&plist);
	SLTPrint(plist);
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);
	return 0;
}