#include<iostream>
using namespace std;

class Stack{
   int *arr;
   int nextIndex;
   
   public:
       Stack(){
          arr = new int[4];
          nextIndex = 0;
       }
       Stack(int cap){
         arr = new int[cap];
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
};

int main(){


  return 0;
}
