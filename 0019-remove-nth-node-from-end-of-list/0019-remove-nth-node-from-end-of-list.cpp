/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Empty case
        if (head->next == NULL) return NULL;

        // initialize slow pointer to store the node before nth delete node, and a fast pointer which n step ahead slow pointer
        ListNode *slow = head;
        ListNode *fast = head;

        // move fast pointer n step forward
        for (int i = 0; i < n; i++){
            fast = fast->next;
        }

        // Corner case
        if (fast == NULL){
            return head->next;
        }

        // move fast, slow node forward together to the end of the list
        while (fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        // remove the next node of slow pointer
        slow->next = slow->next->next;

        // return removed nth node list
        return head;
    }
};