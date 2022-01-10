#include<iostream>
using namespace std;

int count(int a[],int n,int x,int i, int &ans){
    if(i==n){
      return ans;
   }
   if(a[i]==x){
    ans++;
   }
   count(a,n,x,i+1,ans);
}

void count2(int a[],int n,int x,int i, int &ans){
    if(i==n){
      return;
   }
   if(a[i]==x){
    ans++;
   }
   count2(a,n,x,i+1,ans);
}

int main(){
  int a[] = {5,5,6,5,6,7};
  
  int ans = 0;
  cout<<count(a,6,5,0,ans)<<endl;
  
  ans = 0;
  count2(a,6,5,0,ans);
  cout<<ans<<endl;
  
 
  
  return 0;
}

