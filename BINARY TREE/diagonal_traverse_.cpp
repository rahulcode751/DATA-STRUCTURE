Qustion link -> https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

vector<int> diagonal(Node *root)
{
    queue<Node*> my_queue;
    vector<int> my_vect;
    if(root == NULL){
        return my_vect;
    }
    my_queue.push(root);
    while(!my_queue.empty()){
        Node* my_root = my_queue.front();
        my_queue.pop();
        while(my_root){
            if(my_root->left){
                my_queue.push(my_root->left);
            }
            my_vect.push_back(my_root->data);
            my_root = my_root->right;

        }

    }
    return my_vect;
   // your code here
}
