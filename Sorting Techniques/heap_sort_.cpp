#include<iostream>
using namespace std;

void inplaceHeapSort(int *pq, int n){
   /// Build the heap in input array
   for(int i=1;i<n;i++){  // elem 1 se star kr rhe h kyuki 0yh pehle se hi healp me le rhe h hm
    int cI = i;
    while(cI > 0){
        int pI = (cI-1)/2;
        if(pq[cI] < pq[pI]){
            swap(pq[cI], pq[pI]);
            cI = pI;
        }else {
            break;
        }
     }
   }
   /// Remove min n times
   int size = n;
   while(size>=1){
   swap(pq[0], pq[size-1]);
   size--; /// element is removed

   /// Down Heapify

         int pi = 0;
         while(true) {
            int lci = 2*pi + 1;
            int rci = 2*pi + 2;
            int mini = pi;

            if(lci < size && pq[lci] < pq[mini]){
                mini = lci;
            }
            if(rci < size && pq[rci] < pq[mini]){
                mini = rci;
            }

            if(mini == pi){
                break;
            }
            swap(pq[pi], pq[mini]);
            pi = mini;
         }
   }

}

int main(){
   int input[] = {5,1,2,0,8};
   inplaceHeapSort(input, 5);

   for(int i=0;i<5;i++){
    cout<<input[i]<<" ";  /// descending order because we used min priority queue
   }

   return 0;
}
