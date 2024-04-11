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
    TreeNode* invertTree(TreeNode* root) {
        // edge case
        if (root == NULL) return NULL;

        // Recursive method or DFS
        // invertTree(root->left);
        // invertTree(root->right);

        // // create a temp TreeNode and swap left&right tree
        // TreeNode* temp = root->left;
        // root->left = root->right;
        // root->right = temp;

        // Non-recursive or BFS
        queue<TreeNode*> q{{root}};
        
        while(!q.empty()){
            // Advance
            // auto node = q.front(); q.pop();
            // swap(node->left, node->right);
            // for (auto& e: {node->left, node->right}) if (e) q.push(e);

            // Beginner
            TreeNode* currentNode = q.front();
            q.pop();

            // create a temp TreeNode and swap left&right tree
            TreeNode* temp = currentNode->left;
            currentNode->left = currentNode->right;
            currentNode->right = temp;

            // if left child not equal to NULL, push it to queue
            if (currentNode->left != NULL) q.push(currentNode->left);
            // if right child not equal to NULL, push it to queue
            if (currentNode->right != NULL) q.push(currentNode->right);
        }

        return root;
    }
};