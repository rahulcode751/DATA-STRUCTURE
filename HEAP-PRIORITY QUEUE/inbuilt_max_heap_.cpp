#include<iostream>
#include<queue>
using namespace std;

int main(){
   priority_queue<int> pq;   /// max heap

   pq.push(16);
   pq.push(1);
   pq.push(167);
   pq.push(7);
   pq.push(45);
   pq.push(32);

   cout<<"Size : "<<pq.size()<<endl; /// 6
   cout<<"Top : "<<pq.top()<<endl; /// 167

   while(!pq.empty()){
    cout<<pq.top()<<endl;
    pq.pop();
   }

   return 0;
}
