#include<bits/stdc++.h>
using namespace std;

double gSum(int k){
  /// base
  if(k==0){
    return 1;
  }
  /// recursive
  double smallAns = gSum(k-1);

  /// calculation
  return smallAns + 1.0/pow(2,k);

}

int main(){
    cout<<gSum(3);
    return 0;
}

