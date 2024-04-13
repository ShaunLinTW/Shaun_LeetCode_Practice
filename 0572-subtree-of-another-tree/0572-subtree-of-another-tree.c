/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// isSameTree helper function
bool isSameTree (struct TreeNode* p, struct TreeNode* q){
    // base case
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL || p->val != q->val) return false;
    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    // base case
    if (root == NULL) return false;
    // call isSameTree to check is current root and subRoot are identical
    if (isSameTree(root, subRoot)) return true;
    // recursive method
    return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
}
