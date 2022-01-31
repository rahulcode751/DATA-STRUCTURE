/*
Example 1:

Input: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 , P = 2
Output: 3 <-> 4 <-> 5 <-> 6 <-> 1 <-> 2
Explanation: Doubly linked list after rotating
2 nodes is: 3 4 5 6 1 2.

Example 2:

Input: 3 <-> 4 <-> 5 <-> 1 ,P = 4
Output: 3 <-> 4 <-> 5 <-> 1

*/
  int length(Node *start){
        if(start == NULL) return 0;
        Node *temp = start;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    Node *update(Node *start,int p)
    {
        int len = length(start);
        if(start == NULL || p == len) return start;
        Node *temp = start;
        Node *end = start;
        int i = 1;
        while(temp && i<p){
            temp = temp->next;
            i++;
        }
        while(end->next != NULL) end = end->next;
        end->next = start;
        start->prev = end;
        start = temp->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        return start;
        //Add your code here
    }
