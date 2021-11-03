#include<iostream>
using namespace std;

class Stack{
   int *arr;
   int nextIndex;
   int capacity;

   public:
       Stack(){
          capacity = 4;
          arr = new int[capacity];
          nextIndex = 0;
       }
       Stack(int cap){
         capacity = cap;
         arr = new int[capacity];
         nextIndex = 0;
       }
       /// return no of elements present in stack
       int size(){
          return nextIndex;
       }
       bool isEmpty(){
         /*if(nextIndex==0){
            return true;
         }else{
            return false;
         }*/
         return nextIndex==0;
       }
       void push(int ele){
          if(nextIndex==capacity){
            cout<<"Stack full"<<endl;
            return;
          }
          arr[nextIndex] = ele;
          nextIndex++;
       }
       void pop(){
          if(isEmpty()){
            cout<<"Stack empty"<<endl;
            return;
          }
          nextIndex--;
       }
       int top(){
         if(isEmpty()){
            cout<<"Stack empty"<<endl;
            return -1;
          }
         return arr[nextIndex-1];
       }
};

int main(){
  Stack s(4);
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);

  cout<<s.top()<<endl;
  s.pop();

  cout<<s.top()<<endl;
  s.pop();

  cout<<s.top()<<endl;
  s.pop();

  cout<<s.size()<<endl;
  cout<<s.isEmpty()<<endl;

  Stack s2(10);
  for(int i=1;i<=10;i++){
    s2.push(i);
  }
  /// print content of stack
  while(!s2.isEmpty()){
    cout<<s2.top()<<endl;
    s2.pop();
  }
  cout<<s2.size()<<endl;
  return 0;
}
