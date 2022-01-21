#include<iostream>
#include<vector>
/// code by rahulcode751
using namespace std;

class PriorityQueue{
  vector<int> pq;
  public:
      PriorityQueue(){

      }
      bool isEmpty(){
          return pq.size()==0 ;
      }

      /// Return size of priority queue - no of elements present
      int getSize(){
         return pq.size();
      }

      int getMin(){
         if(isEmpty()){
            return 0;  /// pq is empty
         }
         return pq[0];
      }

      void insert(int element){
         pq.push_back(element);   /// CBT yes, Heap not

         int cI = pq.size() - 1;
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
      int removeMin(){
          if(isEmpty()){
            return 0;  /// pq is empty
         }
         int ans = pq[0];
         swap(pq[0], pq[pq.size()-1]);
         pq.pop_back();

         /// CBT yes , Heap no
         /// Down Heapify

         int pi = 0;
         while(true){
            int lci = 2*pi + 1;
            int rci = 2*pi + 2;
            int mini = pi;

            if(lci < pq.size() && pq[lci] < pq[mini]){
                mini = lci;
            }
            if(rci < pq.size() && pq[rci] < pq[mini]){
                mini = rci;
            }

            if(mini == pi){
                break;
            }
            swap(pq[pi], pq[mini]);
            pi = mini;
         }
         return ans;
      }
};
int main(){

   PriorityQueue p;
   p.insert(100);
   p.insert(10);
   p.insert(15);
   p.insert(4);
   p.insert(17);
   p.insert(21);
   p.insert(67);

   cout<<"size: "<<p.getSize()<<endl;
   cout<<"minimum number: "<<p.getMin()<<endl;

   while(!p.isEmpty()){
    cout<<p.removeMin()<<" ";
   }


   return 0;
}
