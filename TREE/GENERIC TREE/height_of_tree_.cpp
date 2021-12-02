int height(TreeNode<int>* root){
     if(root==NULL){  /// edge case
        return 0;
    }
   int mx = 0;   /// maximum height
   for(int i=0;i<root->children.size();i++){
   /*  int childHeight = height(root->children[i]);
     if(childHeight > mx){
        mx = childHeight;
     }  */
     mx = max(mx, height(root->children[i]));   
   }
   return mx + 1;
}