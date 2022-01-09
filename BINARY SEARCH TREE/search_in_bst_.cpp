/* RECURSIVE VERSION */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        if(root->val == val) return root;
        
        if(val > root->val){
            return searchBST(root->right, val);
        }else if(val < root->val){
            return searchBST(root->left, val);
        }
        return NULL;
       
        
    }
};

          
/* ITRATIVE VERSION */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL){
           if(root->val == val) return root;
            else if(val > root->val){
                root = root->right;
            }else{
                root = root->left;
            }
        }
        return NULL; 
    }
};
