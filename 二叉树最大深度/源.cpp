#define _CRT_SECURE_NO_WARNINGS 1
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    // 递归计算左子树的深度
    int leftDepth = maxDepth(root->left);
    // 递归计算右子树的深度
    int rightDepth = maxDepth(root->right);
    // 返回较大的深度，并加1（包含当前节点）
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}
