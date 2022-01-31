/*
/// Split a Circular Linked List into two halves
Example 1:

Input:
Circular LinkedList: 1->5->7
Output:
1 5
7


Example 2:

Input:
Circular LinkedList: 2->6->1->5
Output:
2 6
1 5
*/
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    if(head == NULL || head->next ==  NULL){
       return;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast->next != head && fast != head){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast->next ==  head){
        *head1_ref = head;
        *head2_ref = slow->next;
        fast->next = *head2_ref;
        slow->next = *head1_ref;
    }
    else{
        *head1_ref = head;
        Node* temp = slow->next;
        *head2_ref = slow->next;
        while(temp->next != head) temp = temp->next;
        temp->next = *head2_ref;
        slow->next = *head1_ref;
    }
}
