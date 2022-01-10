#include<bits/stdc++.h>
using namespace std;

int multiply(int m,int n){    /// m*n
    /// base
    if(n==0){
        return 0;
    }
    /// recursive
    int smallAns = multiply(m,n-1);  /// m*(n-1)

    /// calculation
    return smallAns + m;
}

int main(){
    cout<<multiply(3,5);
    return 0;
}


