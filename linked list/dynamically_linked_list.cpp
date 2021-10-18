#include<iostream>
using namespace std;

class Node {
   public:
     int data;
     Node *next;

     Node(int data){
       this->data = data;
       next = NULL;   /// initially pointer is null
     }
};
int main(){
   /// dynamically
   Node *n3 = new Node(3);
   Node *n4 = new Node(4);
   
   n3->next = n4;
   cout<<n3->data<<" "<<n4->data<<endl;

   return 0;
}

