#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class TreeNode{
   public:
       T data;
       vector<TreeNode<T>*> children;
       TreeNode(T data){
          this->data = data;
       }
};

void printTree(TreeNode<int>* root){
	if(root == NULL){
		return;      /// its a edge case not a base case
	}
	cout<<root->data<<": ";
	
	for(int i = 0; i<root->children.size(); i++){
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	
	for(int i = 0; i<root->children.size(); i++){
		printTree(root->children[i]);
	}
}
int main(){
  TreeNode<int>* root = new TreeNode<int>(1);
  TreeNode<int>* n1 = new TreeNode<int>(2);
  TreeNode<int>* n2 = new TreeNode<int>(3);
  
  root->children.push_back(n1);
  root->children.push_back(n2);
  
  printTree(root);
  
  return 0;
}


