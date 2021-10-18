#include<iostream>
using namespace std;

class Node {
   public:
     int data;
     Node *next;

     Node(int data){
       this->data = data;
       next = NULL;
     }
};

Node* takeInput2(){
   int data;
   cin>>data;
   Node *head = NULL;  /// LL is empty
   Node *tail = NULL;   /// LL is empty
   while(data != -1){
    /// creating LL
    Node *n = new Node(data);
    /// 1st node
    if(head == NULL){
        head = n;
        tail = n;
    }else {
        n -> next = head;   /// Inserting at head
        head = n;
    }
    cin>>data;
   }
   return head;
}

int length(Node *head)
{
	Node *temp = head;
	int count = 0;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
   return count;
}
int main(){

   Node *head2 = takeInput2(); /// inserting at head

   cout<<"Length of linked list: "<<length(head2);

   return 0;
}

