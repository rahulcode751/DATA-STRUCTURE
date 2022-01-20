 /* Input:
      4
    /   \
   2     9
k = 2
Output: 4
*/
 void find_largest(Node* root,int k,int &counter,int &ans){
        if(root == NULL) return;

        find_largest(root->right,k,counter,ans);
        if(k == counter){
           ans = root->data;
           counter++;
           return;
        }
        else{
            counter++;
        }
        find_largest(root->left,k,counter,ans);
    }
    int kthLargest(Node *root, int K)
    {
            // add code here.
     if(root == NULL) return -1;
     int counter = 1;
     int ans = -1;
     find_largest(root,K,counter,ans);
     return ans;
        //Your code here
    }
