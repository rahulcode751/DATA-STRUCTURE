/// qustion link https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
/// check if the tree is balanced or not
/// if differnce of left height and right height is 1 the tree is balanced
   int f = 1;
    int solve(Node* root){
        if(root == NULL) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        if(abs(l-r)>1) f = 0;
        return max(l,r)+1;
    }
    bool isBalanced(Node *root)
    {
        f = 1;
        solve(root);
        return f;
        //  Your Code here

    }
