/*
Input:
BST1:
       5
     /   \
    3     7
   / \   / \
  2   4 6   8

BST2:
       10
     /    \
    6      15
   / \    /  \
  3   8  11   18

x = 16
Output:
3
Explanation:
The pairs are: (5, 11), (6, 10) and (8, 8)
*/
 void tree_traversal(Node*root,vector<int> &v){
        if(root == NULL) return;
        tree_traversal(root->left,v);
        v.push_back(root->data);
        tree_traversal(root->right,v);
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        int c = 0;
        if(root1 == NULL && root2 == NULL) return 0;
        vector<int> a;
        vector<int> b;
        tree_traversal(root1,a);
        tree_traversal(root2,b);
        int i = 0,j= b.size()-1;
        while(i<=a.size()-1 && j>=0){
            if(a[i]+b[j] == x){
                i++;
                j--;
                c++;
            }
            else if(a[i]+b[j] < x){
                i++;
            }
            else{
                j--;
            }

        }
        return c;

    }
