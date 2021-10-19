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

void print(Node *head){
   /*
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }*/
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int length(Node *head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

void printIthNode(Node *head, int i){
      if(i<0){
        cout<<"-1"<<endl;
        return;
      }
      int count = 1;
      while(count<=i && head!=NULL){
        head = head->next;
        count++;
      }
      if(head){
        cout<<head->data<<endl;
      }else{
        cout<<"-1"<<endl;
      }
}
Node* insertAtithPos(Node *head, int i, int data){
      if(i<0){
        return head;
      }
      if(i==0){
        Node* n = new Node(data);
        n->next = head;
        head = n;
        return head;
      }
      Node * copyHead = head;
      int count = 1;
      while(count<=i-1 && head!=NULL){
        head = head->next;
        count++;
      }
      if(head){
     /*   Node *n = new Node(data);
        n->next = head->next;             // aese krenge to copy head nhi banana pdega 
        head->next = n;              // or agr inpur 1 2 3 4 tha or i let suppose 4 h greater thn lenght to upse se while me jo head-> next se head 4 wale data pr a gya tha isliye output shi nhi mil aese
		return head;  */
        Node *n = new Node(data);
        Node *temp = head->next;  // ye wali approach better h
        head->next = n;
        n->next = temp;
        return copyHead;  
      }
      return copyHead;
     // return head;
}
Node* takeInput(){
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
        tail -> next = n;   /// Inserting at Tail
        tail = n;
    }

    cin>>data;
   }
   return head;

}

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
int main(){
 
   Node *head = takeInput();  /// inserting at tail
   int i,data;
   cin>>i>>data;
   head = insertAtithPos(head,i,data);
   
   print(head);
 

   return 0;
}

