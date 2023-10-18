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
    void reorderList(ListNode* head) {
        // Special case
        if(head->next == NULL){
            return;
        }
        // Initialize
        ListNode *prev = NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        // Find the middle node
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
            /*
            case 1: 1->2->3->4->5->6
                    ^  ^        ^
                    |  |        |
                    p  s        f
            */
        }

        // Split the list
        prev->next = NULL;

        // head: 1->2->3
        // slow: 4->5->6
        ListNode *L1 = head;
        // Reverse the second half
        ListNode *L2 = reverse(slow);
        // L2: 6->5->4

        // Merge two lists
        merge(L1, L2);
    }
private:
    ListNode *reverse(ListNode * head){
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = curr->next;

        while(curr != NULL){
            // Save the next node
            next = curr-> next;
            // Reverse the link
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // return the new head
        return prev;
    }

    void merge(ListNode *L1, ListNode *L2){
        while(L1 != NULL){
            // Save the next node
            ListNode *p1 = L1->next;
            ListNode *p2 = L2->next;

            // Link the two nodes
            L1->next = L2;
            // Special case
            if(p1 == NULL){
                break;
            }

            // Link the two nodes
            L2->next = p1;
            // Move to the next pair
            L1 = p1;
            L2 = p2;
        }
    }
};