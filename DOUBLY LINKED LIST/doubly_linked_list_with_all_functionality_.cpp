#include<bits/stdc++.h>
using namespace std;//

class Node {
   public:
     Node *prev;
     int data;
     Node *next;

     Node(int data){
       prev = NULL;
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
    return tmp;
}

void Display_forward(Node* start){
    Node *temp = start;
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}
void Display_backward(Node* End){
    Node *temp = End;
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->prev;
    }
    cout<<endl;
}

void insertion_at_beg(Node* &start,Node* &End,int val){
    Node *newNode = new Node(val);
    newNode->next = start;
    if(start == NULL){
        start = newNode;
        End = newNode;
    }
    else{
        start->prev = newNode;
        start = newNode;
    }
}

void insertion_t_end(Node* &start,Node* &End,int val){
    Node *newNode = new Node(val);
    if(start == NULL || End == NULL){
        start = newNode;
        End = newNode;
    }
    else{
        newNode->prev = End;
        End->next = newNode;
        End = newNode;
    }
}

void insertion_at_any_pos(Node* &start,Node* &End,int val,int loc){
    Node *temp = start;
    Node *newNode = new Node(val);
    if(loc == 1){
        newNode->next = start;
        newNode->prev = NULL;
        if(start == NULL) End = newNode;
        else start->prev = newNode;
        start = newNode;
    }
    else if(loc >=2 && temp != NULL){
        for(int i=1; i<=loc-2; i++){
            temp = temp->next;
            if(temp == NULL){
                cout<<"loc is greater than number of nodes"<<endl;
                return;
            }
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if(temp->next != NULL) temp->next->prev = newNode;
        temp->next = newNode;
    }
    else{
        cout<<"Invalid location"<<endl;
    }
}

void Delete_beg(Node* &start, Node* &End){
    Node* temp = start;
    if(temp == NULL){
        cout<<"Empty"<<endl;
        return;
    }
    if(start == End){
        start = End = NULL;
        return;
    }
    else{
        temp->next->prev = NULL;
        start = start->next;
    }
    delete(temp);
}

void Delete_at_End(Node* &start, Node* &End){
    Node *temp,*temp1;
    temp = End;
    if(temp == NULL) return;
    if(start == End){
        start = End = NULL;
    }
    else{
        temp1 = temp->prev;
        temp1->next = NULL;
        End = temp1;
    }
    delete(temp);
}

void delete_at_any_pos(Node* &start,Node* &End,int loc){
    Node *temp = start;
    Node *temp1 = start;
    if(start == NULL || loc <= 0){
        cout<<"Empty";
        return;
    }
    if(loc == 1){
        if(start == End){
            start = End = NULL;
        }
        else{
            temp->next->prev = NULL;
            start = start->next;
        }
    }
    else if(loc >= 2 && temp->next != NULL){
        for(int i=0; i<= loc-2; i++){
            temp = temp->next;
            if(temp->next == NULL){
                cout<<"Loc is greater than total number of Nodes"<<endl;
                return;
            }
        }
        temp1 = temp->next;
        temp->next = temp1->next;
        if(temp1->next != NULL) temp1->next->prev = temp;
        else End = temp;
    }
    else{
        cout<<"Invalid location"<<endl;
        return;
    }
    delete(temp1);
}


int length_dll(Node* start){
    int length = 0;
    while(start){
        length++;
        start = start->next;
    }
    return length;
}



int main(){

    Node *start = takeinput();
    Node *End = movetolast(start);

    Display_forward(start);
    Display_backward(End);

    insertion_at_beg(start,End,1);
    Display_forward(start);
    Display_backward(End);

    insertion_at_any_pos(start,End,9,4);
    Display_forward(start);
    Display_backward(End);

    insertion_t_end(start,End,11);
    Display_forward(start);
    Display_backward(End);

    Delete_beg(start,End);
    Display_forward(start);
    Display_backward(End);

    Delete_at_End(start,End);
    Display_forward(start);
    Display_backward(End);

    delete_at_any_pos(start,End,4);
    Display_forward(start);
    Display_backward(End);

    return 0;
}
