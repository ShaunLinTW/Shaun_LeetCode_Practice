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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // empty case
        if (root == NULL){
            return {};
        }
        // initialize results vector
        vector<vector<int>> results;
        // initialize queue as a vector of TreeNode pointers
        queue<TreeNode*> q;
        q.push(root);

        // create a temorary TreeNode pointer
        TreeNode * temp_tree;
        // initialize length of the queue
        int length;

        // iterate through queue until queue empty
        while(!q.empty()){
            // initialize vector and queue's length
            length = q.size();
            vector<int> v;
            // iterate through queue using breadth-first search
            for (int i = 0; i < length; i++){
                temp_tree = q.front(); // get front of queue to temporary TreeNode
                q.pop(); // pop front of queue
                // add temporary TreeNode's value to vector
                v.push_back(temp_tree->val);

                // if tree's left child have value, push it to queue
                if (temp_tree->left != NULL) q.push(temp_tree->left);
                // if tree's right child have value, push it to queue
                if (temp_tree->right != NULL) q.push(temp_tree->right);
            }
            results.push_back(v);
        }
        return results;
    }
};