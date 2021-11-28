#include<bits/stdc++.h>
using namespace std;

int linearSearch(int a[],int n,int key){

   for(int i=0;i<n;i++){

    if(a[i] == key){
        return i;
    }
   }

   return -1;

}

int main(){

   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
    cin>>a[i];
   }

   cout<<"enter key"<<endl;
   int key;
   cin>>key;

   int pos = linearSearch(a,n,key);
   if(pos == -1){
    cout<<"key not found"<<endl;
   }else{
       cout<<"key found at index "<<pos<<endl;
   }

   return 0;
}
//
