 /*
 qustion link -> https://practice.geeksforgeeks.org/problems/largest-bst/1#
 Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.

Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2
Output: 2
Explanation: The following sub-tree is a
BST of size 2:
       2
    /    \
   N      8
 */
 vector<int> solve(Node* root){
        if(!root) return {1,0,INT_MAX,INT_MIN};
        if(!root->left && !root->right) return {1,1,root->data,root->data};

        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);
        if(l[0] && r[0]){
            if(root->data>l[3] && root->data<r[2]){
                int x = l[2];
                int y = r[3];
                if(x == INT_MAX) x = root->data;
                if(y == INT_MIN) y = root->data;
                return {1,l[1]+r[1]+1,x,y};
            }
        }
        return {0,max(l[1],r[1]),0,0};
    }

    int largestBst(Node *root)
    {
        vector<int> ans = solve(root);
        return ans[1];
    	//Your code here
    }
