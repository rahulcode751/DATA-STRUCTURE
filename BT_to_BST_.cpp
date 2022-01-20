
 /*
 Input:
          1
       /    \
     2       3
   /
 4
Output: 1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1
 */
 void tree_traversal(Node*root,vector<int> &v){
        if(root == NULL) return;
        tree_traversal(root->left,v);
        v.push_back(root->data);
        tree_traversal(root->right,v);
    }
    void BT_to_BST(Node*root,vector<int> v,int &i){
        if(root == NULL) return;
        BT_to_BST(root->left,v,i);
        root->data = v[i];
        i++;
        BT_to_BST(root->right,v,i);
    }
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> v;
        tree_traversal(root,v);
        sort(v.begin(),v.end());
        int i = 0;
        BT_to_BST(root,v,i);
        return root;

        //Your code goes here
    }
