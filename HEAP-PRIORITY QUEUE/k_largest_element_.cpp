#include<iostream>
#include<queue>
using namespace std;
/// code by rahulcode751

void k_largest(int *a,int n,int k){

   priority_queue<int,vector<int> ,greater<int> > pq;

   for(int i=0;i<n;i++){
    pq.push(a[i]);
    if(pq.size() > k){
        pq.pop();  /// smallest element will be deleted
    }
   }
   /// k elements
   while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
   }
}

void klargest(int *a,int n,int k){
   priority_queue<int> p;
   /// pop k elements
   for(int i=0;i<n;i++){
    p.push(a[i]);
   }
   for(int i=1;i<=k;i++){
    cout<<p.top()<<" ";
    p.pop();
   }
}


int main(){

   int array[] = {10,12,6,7,9};
   int k = 3;

   for(int i = 0; i<k; i++){
      cout<<array[i]<<" ";
   }
   cout<<endl;
   cout<<"another approach"<<endl;

   k_largest(array,5,3);

   cout<<endl;

   klargest(array,5,3);
   return 0;
}

