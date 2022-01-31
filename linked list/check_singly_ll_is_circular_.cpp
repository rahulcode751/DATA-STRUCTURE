/*
/// qustion link -> https://practice.geeksforgeeks.org/problems/circular-linked-list/1#
Example 1:

Input:
LinkedList: 1->2->3->4->5
(the first and last node is connected,
i.e. 5 --> 1)
Output: 1
Example 2:

Input:
LinkedList: 2->4->6->7->5->1
Output: 0
*/

bool isCircular(Node *head)
{
   // Your code here
   if(head == NULL) return false;
   Node* temp = head->next;
   while(temp != NULL){
       if(temp == head){
           return true;
       }
       temp = temp->next;
   }
   return false;
}
