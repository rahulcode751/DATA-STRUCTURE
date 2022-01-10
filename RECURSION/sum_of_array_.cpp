#include<iostream>
using namespace std;

int sumOfArray(int a[], int n){
   if(n==0){
    return 0;
   }

   return a[0] + sumOfArray(a+1 , n-1);
}

int sumOfArray3(int a[], int n, int i){
   if(i==n){
    return 0;
   }
   return a[i] + sumOfArray3(a , n, i+1);
}

int sumOfArray2(int a[], int n){
      if(n==0){
       return 0;
      }
     return a[n-1] + sumOfArray2(a,n-1);
}
int main(){
  int a[] = {1,2,3,4,5};
  cout<<sumOfArray3(a, 5, 0)<<endl;;
  return 0;
}

