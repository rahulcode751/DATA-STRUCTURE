https://leetcode.com/problems/merge-two-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       if(l1==NULL) return l2;
       if(l2==NULL) return l1;
        
       ListNode* finalHead = NULL;   /// head of the list to return
        
       if(l1->val < l2->val){
           finalHead = l1;
           l1 = l1->next;
       }else{
           finalHead = l2;
           l2 = l2->next;
       }
        ListNode *p = finalHead;   /// pointer to form new list
        
        while(l1 && l2){
            if(l1->val < l2->val){
                p->next = l1;   /// inseting at tail
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1){
            p->next = l1;
        }else{
            p->next = l2;
        }
        return finalHead;
    }
};
