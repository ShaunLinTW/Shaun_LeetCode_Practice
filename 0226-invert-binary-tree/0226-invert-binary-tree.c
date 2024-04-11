/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    // edge case
    if (root == NULL) return NULL;
    // DFS
    invertTree(root->left);
    invertTree(root->right);

    // create a temp treenode and swap left&right tree
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    return root;
}