class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next)       // As fast is increased by 2 the slow will be in middle when the fast is at end giving us the middle of Linked list
          {                             // eg- [1,2,2,1]
            slow=slow->next;
            fast=fast->next->next;
          }                             // slow will be at 2 giving us the middle

        ListNode* mid=slow;             //  We assign slow as the middle and reverse the list after middle of the list
        ListNode* prev=NULL;
        ListNode* next=NULL;

        while(mid)
          {
            next=mid->next;
            mid->next=prev;
            prev=mid;
            mid=next;
          }

        ListNode* start=prev;                  // prev is the reversed list  i.e the list will become [1,2,1,2] where prev starts from 1 at index 2.

        while(head && start)    //now we compare the linked list from start and middle
          {
            if(head->val!=start->val)
             {
                return false;
             }
            head=head->next;
            start=start->next;
          }

       return true;
    }
};
