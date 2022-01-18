Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(!root) return NULL;

       if(root->data==n1||root->data==n2) return root;

       Node*left=lca(root->left,n1,n2);
       Node*right=lca(root->right,n1,n2);

       if(left && right)
       return root;

       if(left) return left;
       if(right) return right;

    }

    void findlevel(Node* root,int k, int level,int &d){
        if(!root) return ;

        if(root->data==k) d=level;

        if(!d)
        findlevel(root->left,k,level+1,d);
        if(!d)
         findlevel(root->right,k,level+1,d);
    }

    int findDist(Node* root, int a, int b) {

        Node* lc=lca(root,a,b);
        int d1=0,d2=0;

        findlevel(lc,a,0,d1);

       findlevel(lc,b,0,d2);

        return d1+d2;


    }
