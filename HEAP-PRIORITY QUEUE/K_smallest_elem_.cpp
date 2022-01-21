#include<iostream>
#include<queue>
using namespace std;
/// code by rahulcode751
void KSortedArray(int *input, int n,int k){
    priority_queue<int , vector<int> , greater<int> > pq;

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

void k_smallest(int *a,int n,int k){
   priority_queue<int> pq;

   for(int i=0;i<n;i++){
    pq.push(a[i]);
    if(pq.size() > k){
        pq.pop();  /// largest element will be deleted
    }
   }

   /// k elements
   while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
   }
}

void ksmallest(int *a,int n,int k){
   /*priority_queue<int,vector<int> ,greater<int> > pq; /// min
   for(int i=0;i<n;i++){
    pq.push(a[i]);
   }*/
   priority_queue<int,vector<int> ,greater<int> > pq(a,a+n); /// min O(N)   min heap


   /// pop k elements
   for(int i=1;i<=k;i++){
    cout<<pq.top()<<" ";
    pq.pop();
   }

}


int main(){

   int array[] = {10,12,6,7,9};
   int k = 3;
   KSortedArray(array,5,k);

   for(int i = 0; i<k; i++){
      cout<<array[i]<<" ";
   }
   cout<<endl;
   cout<<"another approach"<<endl;

   k_smallest(array,5,3);

   cout<<endl;

   ksmallest(array,5,3);
   return 0;
}

