#include<bits/stdc++.h>
using namespace std;

int countZeroes(int n){
  /// base
  if(n==0){
    return 0;
  }
  /// recursive
  int smallAns = countZeroes(n/10);

  /// calculation
  int last_digit = n%10;

  if(last_digit==0){
    return 1 + smallAns;
  }else{
    return smallAns;
  }

}

int main(){
    cout<<countZeroes(10004);
    return 0;
}

