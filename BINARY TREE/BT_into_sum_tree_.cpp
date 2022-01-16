/// qustion link -> https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node* root){
        if(root == NULL) return 0;

        int temp = root->data;
        root->data = solve(root->left) + solve(root->right);
        return root->data + temp;
    }
    void toSumTree(Node *node)
    {
        // Your code here
        solve(node);
    }
