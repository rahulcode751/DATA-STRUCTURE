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
   /// Statically
   Node n1(1);
   Node n2(2);

  n1.next = &n2;
  cout<<n1.data<<" "<<n2.data<<endl;
  Node *head = &n1;

   return 0;
}

