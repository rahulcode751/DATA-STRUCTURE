/*
qustion link -> https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1#

Input :
              8
            /   \
           7     10
         /      /   \
        2      9     13

Output : Yes
Explanation : We can't insert any element at
              node 9.

Input :
               8
             /   \
           5      9
         /  \
        2    7
       /
      1

Output : Yes
Explanation : Node "1" is the dead End because after that
              we cant insert any element.

*/
bool dead_or_not(Node* root,int l,int r){
    if(!root) return false;
    if(l == r) return true;
    return dead_or_not(root->left,l,root->data-1) || dead_or_not(root->right,root->data+1,r);
}
bool isDeadEnd(Node *root)
{
    return dead_or_not(root,1,INT_MAX);
    //Your code here
}
