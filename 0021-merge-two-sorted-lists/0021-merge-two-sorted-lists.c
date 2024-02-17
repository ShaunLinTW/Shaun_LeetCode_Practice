/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    // Create a dumy node to store the merged list
    struct ListNode *dumy = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *cur = dumy; // Create a pointer to the dumy node, so the dumy->next will be the head of the merged list

    // While both lists are not empty
    while(list1 && list2) {
        if(list1->val < list2->val) {
            cur->next = list1; // add list1 to current list
            list1 = list1->next; // move list1 to the next node
        } else {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }
    // append the rest of the list to the merged list
    if(list1) {
        cur->next = list1;
    } else {
        cur->next = list2;
    }
    return dumy->next; // return the next node of dumy, which is the head of the merged list
}