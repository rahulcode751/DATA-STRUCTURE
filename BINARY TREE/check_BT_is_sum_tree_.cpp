/// qustion link https://practice.geeksforgeeks.org/problems/sum-tree/1
int f = 1;
    int solve(Node* root){
        if(root == NULL) return 0;
        if(!root->left && !root->right) return root->data;
        if(f == 0) return 0;
        int a = solve(root->left);
        int b = solve(root->right);
        if(a + b != root->data) f = 0;
        return a + b+ root->data;
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         f = 1;
         solve(root);
         return f;
    }

