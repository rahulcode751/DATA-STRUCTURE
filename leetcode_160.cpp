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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* slow = headA;
        ListNode* fast = headB;
        int c1=0,c2=0;
        while(slow!=nullptr)
        {
            c1++;
            slow=slow->next;
        }
        while(fast!=nullptr)
        {
            c2++;
            fast=fast->next;
        }
        if(c1>c2)
        {
            int d= c1-c2;
            while(d>0)
            {
                headA=headA->next;
                d--;
            }
        }
        else
        {
            int d= c2-c1;
            while(d>0)
            {
                headB=headB->next;
                d--;
            }
        }
        while(headA!=nullptr && headB!=nullptr)
        {
            if(headA==headB)
            {
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return nullptr;

    }
};
