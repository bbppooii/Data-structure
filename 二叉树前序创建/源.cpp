#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
int treesize(struct TreeNode* root) {
    return root == NULL ? 0 : treesize(root->left) + treesize(root->right) + 1;
}
void order(struct TreeNode* root, int* a, int* pi) {
    if (root == NULL) {
        return;
    }
    a[(*pi)++] = root->val;
    order(root->left, a, pi);
    order(root->right, a, pi);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = treesize(root);
    int* a = malloc(sizeof(int) * (*returnSize));
    int i = 0;
    order(root, a, &i);
    return a;
}