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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head;
        ListNode *prev = NULL;
        int c = 1;
        ListNode *n;
        ListNode *nexthead = head;
        for(int i=0;i<k;i++){
        if(nexthead==NULL){
            return head;
        }
        nexthead=nexthead->next;
        }
        while(curr != NULL && c<=k){
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
            c++;
        }
        if(n != NULL){
            head->next = reverseKGroup(n,k);
        }
        return prev;
    }
};
