#include<iostream>
#include<vector>
#include<queue>
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

TreeNode<int>* takeinput(){  
	cout<<"Enter data "<<endl;
	int rootData;
	cin>>rootData;
	
	TreeNode<int>* root = new TreeNode<int> (rootData);
	queue<TreeNode<int>*> q;
	q.push(root);
	
	while(!q.empty()){
		TreeNode<int>* f = q.front();
		q.pop();
		
		cout<<"Enter no of children of "<<f->data<<endl;
		int n;
		cin>>n;
		
		for(int i=1; i<=n; i++){
			int children;
			cout<<"Enter "<<i<<" th child of "<<f->data<<endl;
			cin>>children;
			
			TreeNode<int>* child = new TreeNode<int> (children);   /// creating node
			q.push(child);                                       /// push
			f->children.push_back(child);                   /// connecting with parent
		}	
	}
	return root;
}   


void printTree(TreeNode<int>* root){
	if(root == NULL){
		return;      /// its a edge case not a base case
	}
	cout<<root->data<<": ";
	
	for(int i = 0; i<root->children.size(); i++){
		cout<<root->children[i]->data<<" ,";
	}
	cout<<endl;
	
	for(int i = 0; i<root->children.size(); i++){
		printTree(root->children[i]);
	}
}
int main(){
 
  TreeNode<int>* root1;
  root1 = takeinput();
  printTree(root1);
  
  return 0;
}
