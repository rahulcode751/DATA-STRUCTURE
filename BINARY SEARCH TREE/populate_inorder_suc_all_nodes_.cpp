/// qustion link -? https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1#
void inorder(Node* root,queue<Node*> &q){
        if(!root){
            return;
        }
        inorder(root->left,q);
        q.push(root);
        inorder(root->right,q);
    }

    void populateNext(Node *root)
    {
        //code here
        if(!root){
            return;
        }
        queue<Node*>q;
        inorder(root,q);

        Node* t;

        while(!q.empty()){
             t=q.front();
            q.pop();
            if(q.empty()){
               return;
            }
            else{

            t->next=q.front();
            }
        }
        }
