int countNodes(TreeNode<int>* root){
	if(root == NULL){
		return 0;    //// its a edge case base case is leaf node itself 
	}
	int ans = 1;
	for(int i=0; i<root->children.size(); i++){
		ans += countNodes(root->children[i]);
	}
	return ans;
}