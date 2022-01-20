void gst(TreeNode*root,int &sum)
    {
        if(root==NULL)
            return ;
        gst(root->right,sum);
            root->val=root->val+sum;
            sum=root->val;
        gst(root->left,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL)
            return NULL;
        int s=0;
        gst(root,s);
        return root;
    }