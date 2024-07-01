/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// gcd helper function
 int gcd(int a, int b){
    int i = 2;
    int result = 1;
    while (i <= a && i <= b){
        if (a % i == 0 && b % i == 0) result = i;
        i++;
    }
    return result;
 }
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    struct ListNode* h = head;
    while (head != NULL && head->next != NULL){
        int r = gcd(head->val, head->next->val);
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = r;
        struct ListNode* temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        head = newNode->next;
    }
    return h;
}