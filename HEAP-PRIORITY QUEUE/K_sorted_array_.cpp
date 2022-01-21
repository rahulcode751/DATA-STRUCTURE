#include<iostream>
#include<queue>
using namespace std;
/// code by rahulcode751
void KSortedArray(int *input, int n,int k){
    priority_queue<int> pq;

    for(int i = 0; i<k; i++){
        pq.push(input[i]);
    }

    int s = 0;
    for(int i=k; i<n; i++){
        input[s] = pq.top();
        pq.pop();
        s++;
        pq.push(input[i]);
    }

    while(!pq.empty()){
        input[s] = pq.top();
        pq.pop();
        s++;
    }
}
int main(){

   int array[] = {10,12,6,7,9};
   int k = 2;
   KSortedArray(array,5,k);

   for(int i = 0; i<5; i++){
      cout<<array[i]<<" ";
   }

   return 0;
}
