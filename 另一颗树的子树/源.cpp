#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL || q == NULL) {
        return false;
    }
    if (p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL) {
        return false;
    }
    if (root->val == subRoot->val && isSameTree(root, subRoot)) {
        return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}