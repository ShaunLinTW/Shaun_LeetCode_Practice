/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    // special case
    if (head == NULL || head->next == NULL){
        return false;
    }

    // initialize two pointers for slow and fast
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // loop until slow and fast meet
    while (fast->next != NULL && fast->next->next != NULL){
        // move slow pointer one step
        slow = slow->next;
        // move fast pointer two steps
        fast = fast->next->next;

        // if slow and fast meet, return true
        if (slow == fast){
            return true;
        }
    }
    return false;
}