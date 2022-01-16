 /// qustion link = https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
  //Function to convert binary tree to doubly linked list and return it.
    void doubly(Node* root,Node* &head,Node* &tail,int &f){
        if(root == NULL){
            return;
        }
        doubly(root->left,head,tail,f);
        if(f == 0){
            f = 1;
            head = root;
            tail = root;
        }
        else{
            tail->right = root;
            tail->right->left = tail;
            tail = tail->right;
        }
        doubly(root->right,head,tail,f);
    }
    Node * bToDLL(Node *root)
    {
        int f = 0;
        Node* head = NULL;
        Node* tail = NULL;
        doubly(root,head,tail,f);
        return head;
        // your code here
    }
};
