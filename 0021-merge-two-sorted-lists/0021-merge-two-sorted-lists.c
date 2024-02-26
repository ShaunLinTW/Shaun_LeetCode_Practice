/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    // create the dumy node to store the merged list, and curr node for dynamic storing
    struct ListNode *dumy = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *curr = dumy;

    // traverse through two list, if not empty, merge them into curr node
    while (list1 && list2){
        // if list1 val bigger then list2, make curr next node equal to list2
        if (list1->val > list2->val){
            curr->next = list2;
            // move list2 to next node
            list2 = list2->next;
        }
        // if list1 val smaller then list2, make curr next node equal to list1
        else {
            curr->next = list1;
            // move list1 to next node
            list1 = list1->next;
        }
        // move curr to next node
        curr = curr->next;
    }
    // append the rest of the list to the merged list
    if (list1 != NULL){
        curr->next = list1;
    }
    else {
        curr->next = list2;
    }
    
    // return next node of dumy node, which is the head of merged linked list
    return dumy->next;
}