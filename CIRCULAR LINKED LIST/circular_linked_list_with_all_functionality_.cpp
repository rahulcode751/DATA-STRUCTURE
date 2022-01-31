#include<bits/stdc++.h>
using namespace std;

class Node {
   public:
     int data;
     Node *next;

     Node(int data){
       this->data = data;
       next = NULL;
     }
    ~Node(){
       delete next;
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

Node* insertAtithPos(Node *End, int i, int data){
      if(i<0){
        return End;
      }
      if(i==0){
        insert_beg(End,data);
        return End;
      }
      Node * copyHead = End->next;
      int count = 1;
      while(count <= i-1){
        copyHead = copyHead->next;
        count++;
      }
      if(copyHead != End->next){
        Node *n = new Node(data);
        Node *temp = copyHead->next;
        copyHead->next = n;
        n->next = temp;
        return End->next;
      }
      return End->next;
}

Node* delete_beg(Node* &End){
    if(End == NULL){
        return End;
    }
    Node* temp = End;
    Node* deli = temp->next;
    temp->next = temp->next->next;
    deli->next = NULL;
    delete deli;
    End = temp;
    return End;
}

Node* delete_end(Node* &End){
    if(End == NULL){
        return End;
    }
    Node* temp = End->next;
    while(temp->next != End){
        temp = temp->next;
    }
    Node* deli = temp->next;
    temp->next = temp->next->next;
    deli->next = NULL;
    delete deli;
    End = temp;
    return End;
}

Node* deleteithNode(Node* End, int i){
   if(i<0){
      return End;
   }
   if(i==0){
    delete_beg(End);
    return End;
   }

   Node* curr = End->next;
   int count = 1;
   while(count < i-1){
    curr = curr->next;
    count++;
   }
   if(curr->next == End){
    End = delete_end(End);
    return End;
   }
   else if(curr != End->next){
    Node* deli = curr->next;
    curr->next = curr->next->next;
    deli->next = NULL;
    delete deli;
    return End;
   }
   return End;
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
    
    End = delete_end(End);
    display(End);
    display(End);

    End = delete_beg(End);
    display(End);

    End = insertAtithPos(End,2,99);
    display(End);  
    
    End = deleteithNode(End,3);
    display(End);

    return 0;
}
