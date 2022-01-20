 /*
 Input:
      2
    /   \
   1     3
K = 2
Output: 2

 */
  void find_smallest(Node* root,int k,int &counter,int &ans){
        if(root == NULL) return;

        find_smallest(root->left,k,counter,ans);
        if(k == counter){
           ans = root->data;
           counter++;
           return;
        }
        else{
            counter++;
        }
        find_smallest(root->right,k,counter,ans);
    }
    int KthSmallestElement(Node *root, int K) {
        // add code here.
     if(root == NULL) return -1;
     int counter = 1;
     int ans = -1;
     find_smallest(root,K,counter,ans);
     return ans;
    }
