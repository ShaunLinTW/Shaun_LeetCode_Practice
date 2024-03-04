/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    // create the dumy node to store the merged list, and curr node for dynamic sotring
    struct ListNode *dumy = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *curr = dumy;

    // traverse through two list, if not empty, merge them into curr node
    
}
