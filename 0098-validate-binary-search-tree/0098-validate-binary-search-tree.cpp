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
    // helper function for checking is valid
    // bool isValid(TreeNode* root, TreeNode* max, TreeNode* min){
    //     if (root == NULL) return true;
    //     if ((min == NULL || root->val > min->val) && (max == NULL || root->val < max->val))
    //         return isValid(root->left, root, min) && isValid(root->right, max, root);
    //     return false;
    // }
    // // DFS, recursive method
    // bool isValidBST(TreeNode* root) {
    //     return isValid(root, NULL, NULL);
    // }

    // DFS, stack method
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        // initialize stack to store visited value
        stack<TreeNode*> S;
        TreeNode* pre = NULL;

        while (root != NULL || !S.empty()){
            while (root != NULL){
                S.push(root);
                root = root->left;
            }
            root = S.top();
            S.pop();
            if (pre != NULL && root->val <= pre->val) return false;
            pre = root;
            root = root->right;
        }
        return true;
    }
};