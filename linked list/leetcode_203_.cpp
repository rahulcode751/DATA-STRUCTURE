class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
       if(head==NULL)
         {
           return head;
         }

       ListNode* A=head;

       while(A!=NULL && A->next!=NULL)
         {

           if(A->next->val==val)
              {
                 A->next=A->next->next;
              }
           else
              {
                 A=A->next;
              }
          }

       if(head->val==val)
          {
             head=head->next;
          }
     return head;
    }
};
