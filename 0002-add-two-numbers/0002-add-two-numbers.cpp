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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // create dumy node to store result list, and curr node for dynamic linked list operation
        ListNode* dumy = new ListNode(0);
        ListNode* curr = dumy;

        // initialize carry value for add operation
        int carry = 0;

        // iterate through list1 and list2 until no remaining value, and no remaining carry value
        while(l1 != NULL || l2 != NULL || carry != 0){
            // initialize digit1, digit2 for assign not exists purpose
            int digit1, digit2;
            // check if list1 or list2 exists, if not exist assign it's value to 0
            if (l1 != NULL) digit1 = l1->val;
            if (l1 == NULL) digit1 = 0;
            if (l2 != NULL) digit2 = l2->val;
            if (l2 == NULL) digit2 = 0;

            // Ternary operator methods
            // int digit1 = (l1 != nullptr) ? l1->val : 0;
            // int digit2 = (l2 != nullptr) ? l2->val : 0;

            // calculate sum of the two numbers along with the carry value
            int sum = digit1 + digit2 + carry;
            // extract sum's value and update carry value
            int extract_sum = sum % 10;
            carry = sum / 10;

            // create a temp node with extracted sum value
            ListNode* temp = new ListNode(extract_sum);
            // update curr node by temp node
            curr->next = temp;
            // move curr node
            curr = curr->next;

            // move list1 and list2, if they exists
            if (l1 != NULL) {
                l1 = l1->next;
            }
            else {
                l1 = NULL;
            }
            if (l2 != NULL) {
                l2 = l2->next;
            }
            else {
                l2 = NULL;
            }

            // Ternary operator methods
            // l1 = (l1 != nullptr) ? l1->next : nullptr;
            // l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        return dumy->next; // this might have memory leak issues
    }
};