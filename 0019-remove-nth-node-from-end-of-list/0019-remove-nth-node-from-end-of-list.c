/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // initialize slow pointer to store the node before nth node delete, and fast pointer for n step ahead
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    // Move fast pointer n step ahead
    for (int i = 0; i < n; i++){
        fast = fast->next;
    }

    // Empty case
    if (head->next == NULL) return NULL;

    // Corner case
    if (fast == NULL) return head->next;

    // Move slow and fast pointer forward until fast pointer reach the end
    while (fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the nth node from end of list
    slow->next = slow->next->next;

    // return the head of the list
    return head;
    
}