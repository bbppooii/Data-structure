#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void Tree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    Tree(root->left);
    Tree(root->right);
}
struct TreeNode* invertTree(struct TreeNode* root) {
    Tree(root);
    return root;
}