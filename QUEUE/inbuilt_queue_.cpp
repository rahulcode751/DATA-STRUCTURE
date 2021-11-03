#include<iostream>
#include<queue>
using namespace std;

int main(){
 queue<int> q;
 q.push(10);
 q.push(20);
 q.push(30);
 q.push(40);
 q.push(50);
 cout<<q.front()<<endl;
 q.pop();
 q.pop();
 cout<<q.front()<<endl;
 cout<<q.size()<<endl;

 q.push(60);
 q.push(70);

 q.pop();
 cout<<q.front()<<endl;
 cout<<q.size()<<endl;

 while(!q.empty()){
    cout<<q.front()<<endl;
    q.pop();
 }
 cout<<q.size()<<endl;
   return 0;
}
