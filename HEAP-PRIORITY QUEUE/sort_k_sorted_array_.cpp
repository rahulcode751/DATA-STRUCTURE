#include<iostream>
#include<queue>
using namespace std;

void KSortedArray(int *input, int n,int k){
    priority_queue<int,vector<int> ,greater<int>> pq;

    for(int i = 0; i<=k; i++){
        pq.push(input[i]);
    }

    int s = 0;
    for(int i=k+1; i<n; i++){
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

   int array[] = {6,5,3,2,8,10,9};
   int k = 3;
   KSortedArray(array,7,k);

   for(int i = 0; i<7; i++){
      cout<<array[i]<<" ";
   }

   return 0;
}
