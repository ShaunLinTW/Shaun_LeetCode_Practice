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
    int maxDepth(TreeNode* root) {
        // edge case
        if (root == NULL) return 0;

        // DFS
        // int left_hight = maxDepth(root->left);
        // int right_hight = maxDepth(root->right);
        // return max(left_hight, right_hight) + 1;

        // DFS using stack
        // initialize stack and depth as 1
        // stack<pair<TreeNode*, int>> S;
        // int depth = 1;
        // S.push({root, depth});

        // while(!S.empty()){
        //     pair<TreeNode*, int> front = S.top(); S.pop();
        //     depth = max(depth, front.second);
        //     if (front.first->left) S.push({front.first->left, front.second + 1});
        //     if (front.first->right) S.push({front.first->right, front.second + 1});
        // }
        // return depth;

        // BFS
        // initialize queue and depth as 0
        queue<TreeNode*> Q;
        int depth = 0;
        // push root into queue
        Q.push(root);

        while(!Q.empty()){
            depth++;
            // get size of the queue
            int queue_size = Q.size();
            for (int i = 0; i < queue_size; i++){
                TreeNode* currentNode = Q.front();
                Q.pop();
                if (currentNode->left != NULL) Q.push(currentNode->left);
                if(currentNode->right != NULL) Q.push(currentNode->right);
            }
        }
        return depth;
    }
};