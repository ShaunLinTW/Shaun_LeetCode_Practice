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
    // inOrderTraversal helper function
    void inOrderTraversal (TreeNode* root, vector<int> &v){
        if (root == NULL) return;
        inOrderTraversal(root->left, v);
        v.push_back(root->val);
        inOrderTraversal(root->right, v);
    }
    int kthSmallest(TreeNode* root, int k) {
        // initialize a vector to store the inorder traversal of the BST
        vector<int> v;
        inOrderTraversal(root, v);
        // because it's BST, so after inordertraversal will get a vector sorted in ascending order.
        return v[k-1]; // vector's index start from 0, therefore k-1 to get Kth smallest value
    }
};