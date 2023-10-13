#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef int ElementType;
typedef struct node {
    ElementType data;
    struct node* next;
}StackNode, * LinkStack;
void InitStack(LinkStack top) {
    top->next = NULL;
}
int IsEmpty(LinkStack top) {
    if (top->next == NULL)
        return TRUE;
    return FALSE;
}
int Push(LinkStack top, ElementType element) {
    LinkStack temp;
    temp = (LinkStack)malloc(sizeof(StackNode));
    if (temp == NULL)
        return FALSE;
    temp->data = element;
    temp->next = top->next;
    top->next = temp;
    return TRUE;
}
int Pop(LinkStack top, ElementType* element) {
    if (IsEmpty(top))
        return FALSE;
    StackNode* temp = top->next;
    *element = temp->data;
    top->next = temp->next;
    free(temp);
    return TRUE;
}
int GetTop(LinkStack top, ElementType* element) {
    if (top->next == NULL)
        return FALSE;
    *element = top->next->data;
    return TRUE;
}
int main(){
    LinkStack s;
    int i;
    int result;
    s = (LinkStack)malloc(sizeof(StackNode));
    InitStack(s);
        Push(s, 'e');
        Push(s, 'f');
        Push(s, 'g');
        Push(s, 'h');
        Push(s, 'i');
    GetTop(s, &result);
    printf("栈顶元素为：%c\n", result);
    printf("元素依次出栈:\n");
    while (!IsEmpty(s))
    {
        Pop(s, &result);
        printf("%c\n", result);
    }
}