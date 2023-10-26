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
    // Function to find the inorder successor of a given node in BST
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // Edge case: if the tree is empty or the target node is not provided
        if (root == NULL || p == NULL) return NULL;
        
        // Initialize the successor as NULL
        TreeNode *suc = NULL;
        
        // Traverse the tree to find the inorder successor
        while (root != NULL) {
            // If the current node's value is less than or equal to the target node's value
            // The successor must be on the right side of the current node
            if (root->val <= p->val) {
                root = root->right;
            } 
            // If the current node's value is greater than the target node's value
            // Update the successor to the current node and move to the left subtree
            else {
                suc = root;
                root = root->left;
            }
        }
        
        // Return the successor node
        return suc;
    }
};