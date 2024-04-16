/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isValid(struct TreeNode* root, struct TreeNode* max, struct TreeNode* min){
    if (root == NULL) return true;
    if ((min == NULL || root->val > min->val) && (max == NULL || root->val < max->val))
        return isValid(root->left, root, min) && isValid(root->right, max, root);
    return false;
}

bool isValidBST(struct TreeNode* root) {
    return isValid(root, NULL, NULL);
}
