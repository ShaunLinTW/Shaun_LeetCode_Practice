/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // empty case
        // if (root == NULL) return NULL;
        if (!root) return NULL;
        // if p's value and q's value greater than current root's value, search right child of root
        if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
        // if p's value and q's value less than current root's value, search left child of root
        else if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        // if p's value and q's value not greater or less than current root's value, means it's the split point, which means we found the lowest common ancestor (LCA) value
        else return root;
    }
};