/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
        // simplist way to delete a node is to copy the value of the next node to the current node and delete the next node
        // node->val = node->next->val;
        // node->next = node->next->next;

        // avoid memory leak:
        // corner case
        if (node->next == NULL){
            free(node);
            return;
        }
        // copy next val to current val
        node->val = node->next->val;
        // use a temp node to store next next node
        struct ListNode* temp = node->next->next;
        // free next node to avoid memory leak issues
        free (node->next);
        // copy temp after current next node
        node->next = temp;
}