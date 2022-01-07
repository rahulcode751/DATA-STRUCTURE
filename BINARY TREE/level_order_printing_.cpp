
#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BTNode{
public:

    T data;
    BTNode* left;
    BTNode* right;

    BTNode(T data){
      this->data = data;
      left = NULL;
      right = NULL;
    }
    ~BTNode(){
      delete left;
      delete right;
    }
};

BTNode<int>* takeInput(){
     int rootData;
     cout<<"Enter data"<<endl;
     cin>>rootData;

     if(rootData==-1){
        return NULL;
     }
     BTNode<int>* root = new BTNode<int>(rootData);
     root->left = takeInput();
     root->right = takeInput();
    return root;
}

BTNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    BTNode<int>* root = new BTNode<int>(rootData);
    queue<BTNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        BTNode<int>* f = q.front();
        q.pop();

         cout<<"Enter left child of "<<f->data<<endl;
         int leftChildData;
         cin>>leftChildData;
         if(leftChildData != -1){
            BTNode<int>* child = new BTNode<int>(leftChildData);
            q.push(child);
            f->left = child;
         }
         cout<<"Enter right child of "<<f->data<<endl;
         int rightChildData;
         cin>>rightChildData;
         if(rightChildData != -1){
            BTNode<int>* child = new BTNode<int>(rightChildData);
            q.push(child);
            f->right = child;
         }
    }
    return root;
}

void levelOrder(BTNode<int>* root) {
        
        
        if(root==NULL){
            return;
        }
       
        
        queue<BTNode<int>*> q;
        q.push(root);
        q.push(NULL);
        cout<<root->data<<endl;;
        
        while(!q.empty()){
            BTNode<int>* f = q.front();
            q.pop();
            if(f==NULL){
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
                
            }else{
               
                if(f->left){
                    q.push(f->left);
                    cout<<f->left->data<<",";
                }
                if(f->right){
                    q.push(f->right);
                    cout<<f->right->data;
                }
            }
        }
        
    }
void printTree(BTNode<int>* root){
   if(root==NULL){   /// base case
    return;
   }

   cout<<root->data<<": ";
   if(root->left!=NULL){
    cout<<"L"<<root->left->data;
   }

   if(root->right!=NULL){
    cout<<"R"<<root->right->data;
   }
   cout<<endl;

   printTree(root->left);
   printTree(root->right);
}


/// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){

 /* BTNode<int>* root = new BTNode<int>(1);
  BTNode<int>* n1 = new BTNode<int>(2);
  BTNode<int>* n2 = new BTNode<int>(3);

  root->left = n1;
  root->right = n2;*/
  BTNode<int>* root = takeInputLevelWise();
  levelOrder(root);
  
  delete root;
  return 0;
}

