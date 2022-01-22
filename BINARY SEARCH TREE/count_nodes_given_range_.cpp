/*
qustion link -> https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1#
Input:
      10
     /  \
    5    50
   /    /  \
  1    40  100
l = 5, h = 45
Output: 3
Explanation: 5 10 40 are the node in the
range

     5
    /  \
   4    6
  /      \
 3        7
l = 2, h = 8
Output: 5
Explanation: All the nodes are in the
given range.


*/

int getCount(Node *root, int L, int R)
{
  // your code goes here
        if(root == NULL) return 0;
        int count = 0;
        if(root->data >= L && root->data <= R){
            count++;
        }

        if(root->data > R){
            return getCount(root->left, L, R);
        }else if(root->data < L){
            return getCount(root->right, L, R);
        }else{
            count = count + getCount(root->left, L, R) + getCount(root->right, L, R);
        }

        return count;

}
