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
private:
    // helper function to merge two lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        // Create a dumy node to store the merged list, and set the current pointer to the dumy node
        ListNode *dumy = new ListNode(0);
        ListNode *curr = dumy;

        // while both lists are not empty
        while (list1 != NULL && list2 != NULL){
            if (list1->val > list2->val){
                curr->next = list2;
                list2 = list2->next;
            }
            else{
                curr->next = list1;
                list1 = list1->next;
            }
            curr = curr->next;
        }

        // Append the remaining nodes in either list to the merged list
        if (list1 != NULL){
            curr->next = list1;
        }
        else {
            curr->next = list2;
        }
        return dumy->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // If the list is empty, return NULL
        if (lists.size() == 0){
            return NULL;
        }
        // if the list has only one element, return the list
        else if (lists.size() == 1){
            return lists[0];
        }

        // if the list has more than one element, merge the lists using the mergeTwoLists function
        else {
            for (int i = 1; i < lists.size(); i++){
                lists[i] = mergeTwoLists(lists[i-1], lists[i]);
            }
        }
        return lists[lists.size()-1];
    }
};