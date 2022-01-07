#include<iostream>
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

BTNode<int>* takeInput_1(){  /// pehla
     int rootData;
     cout<<"Enter data"<<endl;
     cin>>rootData;

     if(rootData==-1){
        return NULL;
     }
     BTNode<int>* root = new BTNode<int>(rootData);
     BTNode<int>* leftChild = takeInput_1();
      BTNode<int>* rightChild = takeInput_1();

      root->left = leftChild;
      root->right = rightChild;

      return root;
}

BTNode<int>* takeInput_2(){   /// dusra
     int rootData;
     cout<<"Enter data"<<endl;
     cin>>rootData;

     if(rootData==-1){
        return NULL;
     }
     BTNode<int>* root = new BTNode<int>(rootData);
     root->left = takeInput_2();
     root->right  = takeInput_2();
     
	return root;
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

int main(){

 /* BTNode<int>* root = new BTNode<int>(1);
  BTNode<int>* n1 = new BTNode<int>(2);
  BTNode<int>* n2 = new BTNode<int>(3);

  root->left = n1;
  root->right = n2;*/
  BTNode<int>* root = takeInput_1();
//  BTNode<int>* root = takeInput_2();
  printTree(root);

  delete root;
  return 0;
}


