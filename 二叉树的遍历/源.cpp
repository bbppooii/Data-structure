#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct BinTreeNode {
    struct BinTreeNode* left;
    struct BinTreeNode* right;
    char val;
}BTNode;
BTNode* createtree(char* a, int* pi) {
    if ((a[*pi]) == '#') {
        (*pi)++;
        return NULL;
    }
    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
    root->val = a[(*pi)++];
    root->left = createtree(a, pi);
    root->right = createtree(a, pi);
    return root;
}
void order(BTNode* root) {
    if (root == NULL) {
        return;
    }
    order(root->left);
    printf("%c ", root->val);
    order(root->right);
}
int main() {
    char a[100];
    scanf("%s", a);
    int i = 0;
    BTNode* root = createtree(a, &i);
    order(root);
    return 0;
}