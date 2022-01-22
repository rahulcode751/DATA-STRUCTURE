/// quation link https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1
unordered_map<string,int> m;
    string solve(Node* root){
        if(root == NULL) return "@";
        string s = "";
        if(!root->left && !root->right){
            s = to_string(root->data);
            return s;
        }
        s = s + to_string(root->data);
        s = s + solve(root->left);
        s = s + solve(root->right);
        m[s]++;
        return s;
    }
    int dupSub(Node *root) {
         // code here
         m.clear();
         solve(root);
         for(auto i:m){
             if(i.second>=2) return 1;
         }
         return 0;
    }
