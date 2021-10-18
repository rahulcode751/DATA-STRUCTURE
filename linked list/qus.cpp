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
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

int length(Node *head){    //// pass by refernce
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
    int count = 0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;
}

void print1(Node *&head,int i){    //// pass by refernce
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
    int count =0;
    while(head!=NULL){
    	
        if(count == i){
		cout<<head->data<<" ";		
		}
		count++;
        head = head->next;
    }
    
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
   cout<<"enter the iteration: ";
   int i,n;
   n = length(head);
   
   cin>>i;
   length(head);
   if(i<0 || i>n)
   {
   	cout<<"invalid itration"<<endl;
   }
 
   
   print1(head,i);
   

  
   return 0;
}
