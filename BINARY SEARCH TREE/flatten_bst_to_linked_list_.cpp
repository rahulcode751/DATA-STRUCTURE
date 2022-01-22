/*
 qustion link  -> https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
 Input :
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
1 2 3 4 5 6
Explanation:
After flattening, the tree looks
like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6
Here, left of each node points
to NULL and right contains the
next node in preorder.The inorder
traversal of this flattened tree
is 1 2 3 4 5 6.

*/
  Node* prev=NULL;
    void flatten(Node *root)
    {
        if(root==NULL)
        return;

        flatten(root->right);
        flatten(root->left);

        root->right=prev;
        root->left=NULL;
        prev=root;
    }
