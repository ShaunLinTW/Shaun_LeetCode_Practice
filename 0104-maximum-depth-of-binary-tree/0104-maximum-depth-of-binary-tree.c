/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root) {
    // edge case
    if (root == NULL) return 0;
    // C don't have stack and queue, so here we use recursive method
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    if (left_depth > right_depth) return left_depth + 1;
    else return right_depth + 1;
}
