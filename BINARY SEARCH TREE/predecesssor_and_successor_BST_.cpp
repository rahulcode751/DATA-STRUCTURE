Node*inordersuc(Node*root)
{
   Node*temp=root->right;
   while(temp->left!=NULL)
   {
       temp=temp->left;
   }
   return temp;
}

Node*inorderpre(Node*root)
{
   Node*temp=root->left;
   while(temp->right!=NULL)
   {
       temp=temp->right;
   }
   return temp;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
   if(root==NULL) return;
   if(key==root->key)
   {
      if(root->left){
         Node*p=inorderpre(root);
         pre=p;
      }
      if(root->right){
         Node*s=inordersuc(root);
         suc=s;
      }
      return;

   }
   else if(key<root->key){
       suc = root;
       findPreSuc(root->left,pre,suc,key);
   }
   else if(key>root->key){
       pre = root;
       findPreSuc(root->right,pre,suc,key);
   }

}
