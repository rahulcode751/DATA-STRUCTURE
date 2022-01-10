#include<iostream>
#include<vector>
using namespace std;

void saveAllPos(int a[],int n,int x,int i, vector<int> &ans){
   if(i==n){
    return;
   }
   if(a[i]==x){
    ans.push_back(i);
   }
   saveAllPos(a,n,x,i+1,ans);
}

int saveAllPosUsingArray(int a[],int n,int x,int i, int out[],int j){
   if(i==n){
    return 0;
   }
   if(a[i]==x){
    out[j] = i;
    return 1 + saveAllPosUsingArray(a,n,x,i+1,out, j+1);
   }
   return 0 + saveAllPosUsingArray(a,n,x,i+1,out,j);
}

int main(){
  int a[] = {5,5,6,5,6,7};

  vector<int> v;
  saveAllPos(a,6,5,0,v);
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;

  int output[10];
  int count = saveAllPosUsingArray(a,6,5,0,output,0);
  for(int i=0;i<count;i++){
    cout<<output[i]<<" ";
  }



  return 0;
}

