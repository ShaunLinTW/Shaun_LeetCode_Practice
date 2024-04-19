/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// inOrderTraversal helper function
void inOrderTraversal(struct TreeNode* root, int* k, int* ans){
    // base case
    if ((*ans != -1) || root == NULL) return;
    // recursively call inOrderTraversal function for the left-subTree
    inOrderTraversal(root->left, k, ans);
    // drecrement k as we visited each node
    (*k)--;
    // Check if this node is the k-th smallest
    if (*k == 0){
        *ans = root->val; // store the node value in ans
        return; // return to stop further processing
    }
    // Continue to the right subtree if not found
    inOrderTraversal(root->right, k, ans);
}

int kthSmallest(struct TreeNode* root, int k) {
    int ans = -1; // initialize answer as -1
    inOrderTraversal(root, &k, &ans); // pass addresses of k and ans
    return ans; // return the found value
}