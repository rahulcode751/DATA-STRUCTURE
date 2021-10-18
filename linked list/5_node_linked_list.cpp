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

void print(Node *head){   //// pas by value

 /*   Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl; */

    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

void print1(Node *&head){    //// pass by refernce
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
    }
     */
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
   /// Statically
   Node n1(1);
   Node *head = &n1;

   Node n2(2);
   Node n3(3);
   Node n4(4);
   Node n5(5);

   n1.next = &n2;
   n2.next = &n3;
   n3.next = &n4;
   n4.next = &n5;


   print(head);
   print(head);
   print1(head);
   print1(head);


   return 0;
}
