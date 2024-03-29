/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // create dumy node to store result, and curr node for dynamic linked list operation
    struct ListNode* dumy = malloc(sizeof(struct ListNode));
    struct ListNode* curr = dumy;

    // initialize dumy node
    dumy->val = 0;
    dumy->next = NULL;

    // initialize carry value
    int carry = 0;
    
    // iterate through list1 and list2 until no remaining value, and no remaining carry value
    while (l1 != NULL || l2 != NULL || carry != 0){
        // (using Ternary Operator) check if list1 or list2 exists, if not exists assign it's value to 0
        int digit1 = (l1 != NULL) ? (l1->val) : 0;
        int digit2 = (l2 != NULL) ? (l2->val) : 0;

        // calculate sum of digit1 + digit2 + carry value
        int sum = digit1 + digit2 + carry;
        // extract sum's value
        int extract_sum = sum % 10;
        // update carry value
        carry = sum / 10;

        // create temp node with extracted sum value
        struct ListNode* temp = malloc(sizeof(struct ListNode));
        // initialize temp node
        temp->val = extract_sum;
        temp->next = NULL;
        // update curr node by temp node
        curr->next = temp;
        curr = curr->next;

        // (using Ternary Operator) move list1 and list2
        l1 = (l1 != NULL) ? (l1->next) : NULL;
        l2 = (l2 != NULL) ? (l2->next) : NULL;
    }
    return dumy->next;
}