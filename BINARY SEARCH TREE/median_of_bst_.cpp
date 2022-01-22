/*
qustion link -> https://practice.geeksforgeeks.org/problems/median-of-bst/1#
Input:
       6
     /   \
   3      8
 /   \    /
1    4   7
Output: 5
Explanation:Inorder of Given BST will be:
1, 3, 4, 6, 7, 8. So, here median will
(4 + 6)/2 = 10/2 = 5.

Input:
       6
     /   \
   3      8
 /  \    /  \
1    4  7    9
Output: 6
Explanation: Inorder of Given BST will be:
1, 3, 4, 6, 7, 8, 9. So, here median will 6.

*/

void inorder(struct Node*root,vector<float>&v)
{
    if(root==NULL)
    return ;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

float findMedian(struct Node *root)
{
    vector<float> v;
    if(root == NULL) return -1;
    inorder(root,v);
    int a = v.size();
    if(a%2 != 0){
        return v[(a-1)/2];
    }
    else{

        return (v[(a/2)]/2 + v[(a/2)-1]/2);
    }
      //Code here
}
