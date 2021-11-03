#include<iostream>
using namespace std;

template<typename T>
class Node{
   public:
       T data;
       Node<T>* next;
       Node(T data){
         this->data = data;
         next = NULL;
       }
};

template<typename T>
class Queue{
    Node<T>* head;
    Node<T>* tail;
    int size;

  public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int getSize(){
       return size;
    }
    bool isEmpty(){
       return size==0;
    }
    void push(T ele){
       Node<T>* n = new Node<T>(ele);
       if(head==NULL){
        head = n;
        tail = n;
       }else{
         tail->next = n;
         tail = n;
       }
       size++;
    }
    T front(){
       if(isEmpty()){
        return 0;
       }
       return head->data;
    }
    void pop(){
       if(isEmpty()){
        return;
       }
       Node<T>* temp = head;
       head = head->next;
       temp->next = NULL;
       delete temp;
       size--;
    }
};
int main(){
 Queue<int> q;
 q.push(10);
 q.push(20);
 q.push(30);
 q.push(40);
 q.push(50);
 q.push(60);
 q.push(70);
 cout<<q.front()<<endl;
 q.pop();
 q.pop();
 q.pop();
 cout<<q.front()<<endl;
 cout<<q.getSize()<<endl;
 cout<<q.isEmpty()<<endl;
 q.push(60);
 q.push(70);

 q.pop();
 q.pop();
 cout<<q.front()<<endl;
 cout<<q.getSize()<<endl;

 while(!q.isEmpty()){
    cout<<q.front()<<endl;
    q.pop();
 }
 cout<<q.getSize()<<endl;
 cout<<q.isEmpty()<<endl;
   return 0;
}
