#include<bits/stdc++.h>
using namespace std;

class AVL{
public:
    int data;
    AVL* left;
    AVL* right;
    int height;

    AVL(int data){
      this->data = data;
      left = NULL;
      right = NULL;
      this->height = 1;
    }

     ~AVL(){
      delete left;
      delete right;
    }
};

int node_height(AVL* node){
    int hl,hr;
    hl=node && node->left?node->left->height:0;
    hr=node && node->right?node->right->height:0;
    return (hl>hr)?hl+1:hr+1;
}

int BalanceFactor(AVL* node){
    int hl,hr;
    hl=node && node->left?node->left->height:0;
    hr=node && node->right?node->right->height:0;
    return hl-hr;
}

AVL* LL_rotation(AVL* node){  /// LL rotation function
    AVL* node_lc = node->left;
    AVL* node_rc = node->right;

    node_lc->right = node;
    node->left = node_rc;

    /// now modify height
    node->height = node_height(node);
    node_lc->height = node_height(node_lc);
    node_rc->height = node_height(node_rc);

    return node_lc;
}

AVL* LR_rotation(AVL* node){   /// LR rotation function
    AVL* node_lc = node->left;
    AVL* node_rc = node->right;

    node_lc->right = node_rc->left;
    node->left = node_rc->right;

    node_rc->left = node_lc;
    node_rc->right = node;

    /// now modify heights
    node_lc->height = node_height(node_lc);
    node->height = node_height(node);
    node_rc->height = node_height(node_rc);

    return node_rc;
}

AVL* RR_rotation(AVL* node){  /// RR rotation function
    AVL* node_lc = node->left;
    AVL* node_rc = node->right;

    node_rc->left = node;
    node->right = node_lc;

    /// now modify heights
    node->height = node_height(node);
    node_lc->height = node_height(node_lc);
    node_rc->height = node_height(node_rc);

    return node_rc;
}

AVL* RL_rotation(AVL* node){  /// RL rotation function
    AVL* node_lc = node->left;
    AVL* node_rc = node->right;

    node_rc->left = node_lc->right;
    node->right = node_lc->left;

    node_lc->right = node_rc;
    node_lc->left = node;

    /// now modify heights
    node->height = node_height(node);
    node_lc->height = node_height(node_lc);
    node_rc->height = node_height(node_rc);

    return node_lc;
}

void printTree(AVL* root){
   if(root==NULL){   /// base case
    return;
   }

   cout<<root->data<<": ";
   if(root->left!=NULL){
    cout<<"L"<<root->left->data<<",";
   }

   if(root->right!=NULL){
    cout<<"R"<<root->right->data<<",";
   }
   cout<<endl;

   printTree(root->left);
   printTree(root->right);
}

AVL* insert(AVL* node, int data){
    if(node == NULL){
        AVL* n = new AVL(data);
        return n;
    }
    if(data < node->data){
        node->left = insert(node->left , data);
    }
    else if(data > node->data){
        node->right = insert(node->right, data);
    }
    else{
        return node;
    }


    node->height = node_height(node);  /// update height of nodes after insertion

    if(BalanceFactor(node) == 2 && BalanceFactor(node->left) == 1){
        /// LL rotation;
        return LL_rotation(node);
    }
    else if(BalanceFactor(node) == 2 && BalanceFactor(node->left) == -1){
        /// LR rotation;
        return LR_rotation(node);
    }
    else if(BalanceFactor(node) == -2 && BalanceFactor(node->right) == -1){
        /// RR rotation;
        return RR_rotation(node);
    }
    else if(BalanceFactor(node) == -2 && BalanceFactor(node->right) == 1){
        /// RL  rotation;
        return RL_rotation(node);
    }

    return node;
}

AVL* minDataNode(AVL *root){
    if(!root)return root;

    AVL* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}


int main(){
 // AVL* root = new AVL(10);
 // root = insert(root,5);
 // root = insert(root,2);

  AVL* root = new AVL(10);
  root=insert(root,10);
  root=insert(root,90);
  root=insert(root,50);
  root=insert(root,70);
  root=insert(root,28);
  root=insert(root,19);
  root=insert(root,65);
  root=insert(root,57);
  printTree(root);

  return 0;
}
