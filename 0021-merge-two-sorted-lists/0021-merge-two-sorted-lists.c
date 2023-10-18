/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *dumy = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *cur = dumy;

    // While both lists are not empty
    while(list1 && list2) {
        if(list1->val < list2->val) {
            cur->next = list1;
            list1 = list1->next;
        } else {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }
    if(list1) {
        cur->next = list1;
    } else {
        cur->next = list2;
    }
    return dumy->next;
}