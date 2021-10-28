Node* reverse_kth(Node* head,int k) {
        Node *curr = head;
        Node *prev = NULL;
        int c = 0;
        Node *n;
        while(curr != NULL && c<k){
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
            c++;
        }
        if(n != NULL){
            head->next = reverse_kth(n,k);
        }
        return prev;
    }
