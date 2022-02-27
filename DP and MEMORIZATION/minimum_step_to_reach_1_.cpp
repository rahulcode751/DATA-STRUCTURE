#include<bits/stdc++.h>
using namespace std;

int helper(int n, int *ans){
    /// base case
    if(n <= 1){
        return 0;
    }
    /// check if output already exist
    if(ans[n] != -1){
        return ans[n];
    }

    /// recursive
    int x = helper(n-1,ans);
    int y,z;
    y=z=INT_MAX;

    if(n%2==0){
         y = helper(n/2,ans);
    }
    if(n%3==0){
         z = helper(n/3,ans);
    }
    /// calculate ans
    int output = min(x,min(y,z)) + 1;

    /// save ans for future use
    ans[n] = output;

    return output;

}

int minSteps2(int n){

    int *ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }
    return helper(n,ans);
}


int minSteps(int n){
    /// base case
    if(n <= 1){
        return 0;
    }
    /// recursive
    int x = minSteps(n-1);
    int y,z;
    y=z=INT_MAX;

    if(n%2==0){
         y = minSteps(n/2);
    }
    if(n%3==0){
         z = minSteps(n/3);
    }
    /// calculate ans
    int ans = min(x,min(y,z)) + 1;
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<minSteps(n)<<endl;
    cout<<minSteps2(n)<<endl;
    return 0;
}
