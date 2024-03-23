/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // simplist way to delete a node is to copy the value of the next node to the current node and delete the next node
        // node->val = node->next->val;
        // node->next = node->next->next;

        // avoid memory leak:
        if (node->next == NULL) {
            delete (node);
            return;
        }
        node->val = node->next->val;
        ListNode *temp = node->next->next;
        delete (node->next);
        node->next = temp;
    }
};