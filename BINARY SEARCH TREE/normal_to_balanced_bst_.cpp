 void tree_traversal(Node*root,vector<int> &v){
        if(root == NULL) return;
        tree_traversal(root->left,v);
        v.push_back(root);
        tree_traversal(root->right,v);
    }
 Node* make_balanced_bst(int s,int e,vector<Node*> &v){
 if(s>e) return NULL;
 int mid = (s+e)/2;
 Node* root = v[mid];
 root->left = make_balanced_bst(root,s,mid-1,v);
 root-right = make_balanced_bst(root,mid+1,end,v);
 return root;
 }

 Node* normal_bst_tobalanced_bst(Node* root){
 if(root == NULL) return NULL;
 vector<Node*> v;
 tree_traversal(root,v)
 int i = 0;
 int e = v.size() - 1;
 root = make_balanced_bst(i,e,v);
 return root;

 }
