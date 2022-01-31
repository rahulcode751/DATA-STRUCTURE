class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        //Check for null linked list and single node linked list
       if(head==NULL || head->next==NULL)
       {
           return head;
       }


       ListNode *curr = head;

       while(curr!=NULL && curr->next != NULL)
       {
           //value of current node == value of adjacent node to current
           if(curr->val == curr->next->val)
           {
               curr->next = curr->next->next;
           }
           else
           {
               curr = curr->next;
           }

       }
        return head;
    }
};
