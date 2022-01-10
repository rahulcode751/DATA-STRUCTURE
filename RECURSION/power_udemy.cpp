#include<bits/stdc++.h>
using namespace std;

int power(int x,int n){
  ///Base Case
  if(n==0){
    return 1;
  }

  ///Recursive
  int smallOutput = power(x,n-1);

  /// Calculation

  return x*smallOutput;

}

int main(){

     cout<<power(5,3);
    return 0;
}
