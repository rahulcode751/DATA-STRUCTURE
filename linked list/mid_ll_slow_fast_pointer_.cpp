
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

/* Node* reverseList(Node* head) {
        Node *curr = head;
        Node *prev = NULL;
        while(curr != NULL){
            Node *n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        return prev;
    }  */

Node* middleNode(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast == NULL){    /// pehle yhi ayga
            return slow;
        }
        else {
        {
            return slow->next;    /// phir ye ayga agr isko pehle likh diya yani fast->next == null vo even ke liye work krega lekin odd ke liye ye null ke par chla jatga isiliye runtime error milega
        }
    }
 
}
 

/*int length(Node *head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}*/

int length(Node *head){
    if(head==NULL) return 0;

    return 1 + length(head->next);
}
bool isPresent(Node *head, int data){
     Node *curr = head;
     while(curr!=NULL){
        if(curr->data == data){
            return true;
        }
        curr = curr->next;
     }
     return false;
}
bool findElement(Node *head, int data){
     if(head==NULL) return false;
     if(head->data==data) return true;

     return findElement(head->next,data);

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
        /*Node *n = new Node(data);
        n->next = head->next;
        head->next = n;*/
        Node *n = new Node(data);
        Node *temp = head->next;
        head->next = n;
        n->next = temp;
        return copyHead;
      }
      return copyHead;
}

Node* deleteithNode(Node* head, int i){
   if(i<0){
      return head;
   }
   if(i==0 && head){
    Node* newHead = head->next;
    head->next = NULL;
    delete head;
    return newHead;
   }

   Node* curr = head;
   int count = 1;
   while(count<=i-1 && curr!=NULL){
    curr = curr->next;
    count++;
   }
   if(curr && curr->next){
     Node *temp = curr->next;
     curr->next = curr->next->next;
     temp->next=NULL;
     delete temp;
     return head;
   }
   return head;
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
   /// Statically
  /* Node n1(1);
   Node *head = &n1;

   Node n2(2);
   Node n3(3);
   Node n4(4);
   Node n5(5);

   n1.next = &n2;
   n2.next = &n3;
   n3.next = &n4;
   n4.next = &n5;*/

   Node *head = takeInput();  /// inserting at tail
 
   ///int i;
   ///cin>>i;
   ///head = insertAtithPos(head,i,data);
  /// head = deleteithNode(head,i);
   ///printIthNode(head,i);
   ///cout<<length(head)<<endl;
   //Node *head2 = takeInput2(); /// inserting at head
   ///print(head);

  /* int data;
   cin>>data;
   if(findElement(head,data)){
    cout<<"found"<<endl;
   }else{
    cout<<"not found"<<endl;
   }   */
   head = middleNode(head);
   cout<<"mid : "<<head->data;  
   //print(head2);
  // print(head);

  /*n1.next = &n2;
  cout<<n1.data<<" "<<n2.data<<endl;

  Node *head = &n1;

  cout<<head->data<<endl;

  /// Dynamically
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  n3->next = n4;
  */

   return 0;
}



