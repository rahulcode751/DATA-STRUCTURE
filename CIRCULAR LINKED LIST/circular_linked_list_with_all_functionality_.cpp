
#include<bits/stdc++.h>
using namespace std;//

class Node {
   public:
     Node *prev;
     int data;
     Node *next;

     Node(int data){
       this->data = data;
       next = NULL;
     }
};

Node *takeinput(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
      Node *newNode=new Node(data);

      if(head==NULL){
        head=newNode;
        tail=newNode;

      }
      else{
         Node *temp=tail;
         temp->next=newNode;
         tail=newNode;
         newNode->prev=temp;

      }
      cin>>data;
    }
    return head;
}

Node *movetolast(Node *head){
    Node *tmp=head;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next = head;
    return tmp;
}

void insert_beg(Node* &End,int val){
    Node* newNode = new Node(val);
    if(End == NULL){
        newNode->next = newNode;
        End = newNode;
    }
    else{
        newNode->next = End->next;
        End->next = newNode;
    }
}

void insert_end(Node* &End,int val){
    Node* newNode = new Node(val);
    if(End == NULL){
        newNode->next = newNode;
        End = newNode;
    }
    else{
        newNode->next = End->next;
        End->next = newNode;
        End = newNode;
    }
}

void display(Node *End){
    if(End == NULL){
        cout<<"Empty"<<endl;
        return;
    }
    else{
        Node *temp = End->next;
        cout<<temp->data<<"->";
        temp = temp->next;
        while(temp != End->next){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL";
    }
    cout<<endl;
}
int main(){
    Node* start = takeinput();
    Node* End = movetolast(start);
    display(End);

    insert_beg(End,10);
    display(End);
    insert_end(End,11);
    display(End);
    return 0;
}
