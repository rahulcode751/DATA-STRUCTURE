https://leetcode.com/problems/validate-binary-search-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool helper(TreeNode* root,long long minV =INT_MIN-1LL , long long maxV = INT_MAX+1LL){
        if(root==NULL) return true;
        
        bool left = helper(root->left, minV , root->val);
        bool right = helper(root->right, root->val, maxV);
        
        if(left && right && root->val>minV && root->val<maxV) return true;
        else return false;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool helper(TreeNode* root,long long minV = -10000000000 , long long maxV = 10000000000){
        if(root==NULL) return true;
        
        bool left = helper(root->left, minV , root->val);
        bool right = helper(root->right, root->val, maxV);
        
        if(left && right && root->val>minV && root->val<maxV) return true;
        else return false;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
};
