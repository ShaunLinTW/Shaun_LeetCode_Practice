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
    bool hasCycle(ListNode *head) {
        // special case
        if (head == NULL) {
            return false;
        }
        
        // initialize two pointers
        ListNode* slow = head;
        ListNode* fast = head;
        
        // move pointers
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // if two pointers meet, there is a cycle
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};