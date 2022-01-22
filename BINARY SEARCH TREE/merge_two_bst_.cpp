*
Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7   */

void inorder(Node*root,vector<int>&v)
{
    if(root==NULL)
    return ;
    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v);
}

 Node* make_balanced_bst(int s,int e,vector<Node*> &v){
     if(s>e) return NULL;
     int mid = (s+e)/2;
     Node* root = v[mid];
     root->left = make_balanced_bst(root,s,mid-1,v);
     root-right = make_balanced_bst(root,mid+1,end,v);
     return root;
 }

Node* merge(Node *root1, Node *root2)
{
    vector<Node*>v1;
    if(root1==NULL && root2==NULL)
       return v1;
    vector<int>v1;
    inorder(root1,v1);
    inorder(root2,v1);
    sort(v1.begin(),v1.end());
    Node* node = make_balaned_bst(0,v1.size()-1,v);
    return node;
}
