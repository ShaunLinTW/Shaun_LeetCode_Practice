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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // DFS recursion method
        // if (p == NULL && q == NULL) return true; // base case, if both threes are empty, they are identical
        // if (p == NULL || q == NULL) return false;
        // if (p->val != q->val) return false; // check the value of current nodes
        // return (isSameTree(p->right, q->right) && isSameTree(p->left, q->left));
        
        // BFS using Queues
        // create queues for both trees
        queue<TreeNode*> Q_p;
        queue<TreeNode*> Q_q;

        // push current trees to each queue
        Q_p.push(p);
        Q_q.push(q);

        while(!Q_p.empty() && !Q_q.empty()){
            TreeNode* node_p = Q_p.front();
            TreeNode* node_q = Q_q.front();
            Q_p.pop();
            Q_q.pop();

            // if current node are equal, means they are identical, move on to next node
            if (node_p == NULL && node_q == NULL) continue;
            // if current node and value are not equal, return false
            if (node_p == NULL || node_q == NULL || node_p->val != node_q->val) return false;

            // push left and right child of both nodes to their queue
            Q_p.push(node_p->left);
            Q_p.push(node_p->right);
            Q_q.push(node_q->left);
            Q_q.push(node_q->right);
        }
        // if both queues are empty, means both trees are identical, return true
        if (Q_p.empty() && Q_q.empty()) return true;
        return false;
    }
};