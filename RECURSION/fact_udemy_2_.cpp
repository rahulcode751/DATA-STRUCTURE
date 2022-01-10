#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    /// base case  1st step
    if(n==0){
        return 1;
    }
    int smallAns = fact(n-1);   /// 2nd step assumption  Recursive case

    int ans = n * smallAns;    /// 3rd step calculation
     return ans;
}

int main(){
     cout<<fact(4)<<endl;
    return 0;
}


