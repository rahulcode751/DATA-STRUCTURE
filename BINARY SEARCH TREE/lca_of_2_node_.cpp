 /// qustion link -. https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1#
 /*
 Input:
              5
           /    \
         4       6
        /         \
       3           7
                    \
                     8
n1 = 7, n2 = 8
Output: 7
 */

 Node* LCA(Node* root ,int n1 ,int n2 )
    {

      if(root==NULL) return NULL;
      // if(root->data == n1 || root->data == n2) return root;
       if(root->data<n1 && root->data<n2){
          LCA(root->right,n1,n2);
       }
       else if(root->data>n2 && root->data>n1){
          LCA(root->left,n1,n2);
       }
       else{
          return root;
       }
     //  if(left->data == n1 || right->data == n2) return root;


     //  if(left && right) return root;
     //  if(left) return left;
     //  else return right;
    }

