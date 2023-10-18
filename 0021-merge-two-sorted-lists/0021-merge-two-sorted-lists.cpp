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
#include <iostream>
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dumy = new ListNode(0); // Create a dumy node to store the merged list
        ListNode* curr = dumy; // Set the current pointer to the dumy node

        // While both lists are not empty
        while(list1 && list2){
            // Compare the values of the nodes in both lists
            if(list1->val <= list2->val){
                // If the value in list1 is smaller or equal, append the node to the merged list
                curr->next = list1;
                list1 = list1->next;
            }
            else{
                // If the value in list2 is smaller, append the node to the merged list
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next; // Move the current pointer to the last node in the merged list
        }
        //Append the remaining nodes in wither list to the merged list
        if(list1){
            curr->next = list1;
        }
        else{
            curr->next = list2;
        }
        return dumy->next; // Return the merged list, skipping the dumy node
    }
};