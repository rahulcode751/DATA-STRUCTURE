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

void printTree(TreeNode<int>* root){
   if(root==NULL){
    return ;
   }
   cout<<root->data<<": ";
   for(int i=0;i<root->children.size();i++){
    cout<<root->children[i]->data<<" ,";
   }
   cout<<endl;

   for(int i=0;i<root->children.size();i++){
    printTree(root->children[i]);
   }
}

TreeNode<int>* takeInput(){
   int rootData;
   cout<<"Enter data"<<endl;
   cin>>rootData;
   TreeNode<int>* root = new TreeNode<int>(rootData);
   /// how many children
   int n;
   cout<<"Enter num of children of "<<rootData<<endl;
   cin>>n;

   for(int i=1;i<=n;i++){
     TreeNode<int>* child = takeInput();
     root->children.push_back(child);
   }
   return root;
}

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode<int>* f = q.front();
        q.pop();

        cout<<"Enter no of children of "<<f->data<<endl;
        int n;
        cin>>n;

        for(int i=1;i<=n;i++){
            int childData;
            cout<<"Enter "<<i<<" th child of "<<f->data<<endl;
            cin>>childData;

            TreeNode<int>* child = new TreeNode<int>(childData);
            q.push(child);
            f->children.push_back(child);
        }
    }
    return root;
}

void printTreeLevelWise(TreeNode<int>* root){     /// level order printing
     queue<TreeNode<int>*> q;
     q.push(root);
     while(!q.empty()){
        TreeNode<int>* f = q.front();
        q.pop();

        cout<<f->data<<": ";
        for(int i=0;i<f->children.size();i++){
           cout<<f->children[i]->data<<" ,";
           // q.push(f->children[i]);
         }
        cout<<endl;

        for(int i=0;i<f->children.size();i++){
            q.push(f->children[i]);
        }   
     }
}
int main(){
 /* TreeNode<int>* root = new TreeNode<int>(1);
  TreeNode<int>* n1 = new TreeNode<int>(2);
  TreeNode<int>* n2 = new TreeNode<int>(3);

  root->children.push_back(n1);
  root->children.push_back(n2);*/

  TreeNode<int>* root = takeInputLevelWise();
  printTreeLevelWise(root);
  return 0;
}

