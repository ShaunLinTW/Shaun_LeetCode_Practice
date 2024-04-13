/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // using isSameTree helper function
    bool isSameTree (TreeNode* p, TreeNode* q){
        // base case
        if (p == NULL && p == NULL) return true;
        if (p == NULL || q == NULL || p->val != q->val) return false;
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // base case
        if (root == NULL) return false;
        // check if current Tree and sub-Tree are identical
        if (isSameTree(root, subRoot)) return true;
        // recursive call isSubtree to check all child node of the Tree
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};