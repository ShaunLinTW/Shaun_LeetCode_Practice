/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Iterative Approach
struct ListNode* reverseList(struct ListNode* head){
    // Special case
    if (head == NULL || head->next == NULL) return head;
    
    // Initialize prev, curr, next
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = head->next;

    while (curr != NULL) {
        // Save the next node, before we overwrite curr->next
        next = curr->next;

        // Reverse the link
        curr->next = prev;
        
        // Move to next node
        prev = curr;
        curr = next;
    }
    return prev;
}

/* Visualization
case 1: 1->2->3->4->5->NULL
step1: 1->NULL, 2->3->4->5->NULL
step2: 2->1->NULL, 3->4->5->NULL
step3: 3->2->1->NULL, 4->5->NULL
step4: 4->3->2->1->NULL, 5->NULL
step5: 5->4->3->2->1->NULL, NULL
return: 5->4->3->2->1->NULL
*/