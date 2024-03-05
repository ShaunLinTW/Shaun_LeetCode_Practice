/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
// helper function to merge two lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    // create the dumy node to store the merged list, and curr node for dynamic storing
    struct ListNode* dumy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* curr = dumy;

    // traverse through two list, if not empty, merge them into curr node
    while (list1 != NULL && list2 != NULL){
        // if list1 val bigger then list2, make curr node equal to list2
        if (list1->val > list2->val){
            curr->next = list2;
            list2 = list2->next;
        }
        else{
            curr->next = list1;
            list1 = list1->next;
        }
        // move curr node to next
        curr = curr->next;
    }
    // append the rest of the list to the merged list
    if (list1 != NULL) {
        curr->next = list1;
    }
    else {
        curr->next = list2;
    }

    return dumy->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    // if the list is empty, return NULL
    if (listsSize == 0){
        return NULL;
    }
    // if the list only has one element, return the list
    else if (listsSize == 1){
        return lists[0];
    }
    // if the list has more than one element, merge the first half and the second half
    // return mergeTwoLists(mergeKLists(lists, listsSize / 2), mergeKLists(lists + listsSize / 2, listsSize - listsSize / 2));

    // if the list has more than one element, merge the first half and the second half
    else {
        for (int i = 1; i < listsSize; i ++){
            lists[i] = mergeTwoLists(lists[i-1], lists[i]);
        }
    }
    // return the merged list
    return lists[listsSize-1];
}
