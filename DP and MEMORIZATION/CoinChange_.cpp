#include<bits/stdc++.h>
using namespace std;

int CoinChange(int n,int* d,int numD){ ///Exponential Time Complexity 2^n
    if(n==0) return 1;
    if(n < 0) return 0;
    if(numD == 0) return 0;
    int first = CoinChange(n-d[0],d,numD);
    int sec = CoinChange(n,d+1,numD-1);
    return first+sec;
}

int CoinChange2(int n,int* d,int numD,int** output){ /// Using Dynamic Programming T(n) = O(n)

    if(n==0) return 1;
    if(n < 0) return 0;
    if(numD == 0) return 0;
    /// In this 2D output array by default we taking all its value as -1 having row size n+1,col size numD+1
    if(output[n][numD] > -1){
        return output[n][numD];
    }
    int first = CoinChange2(n-d[0],d,numD,output);
    int sec = CoinChange2(n,d+1,numD-1,output);
    output[n][numD] = first+sec;
    return output[n][numD];
}

int main(){
    int d[2] = {1,2};
    cout<<CoinChange(6,d,2)<<endl;

    int **output;
    output = new int*[5];
    for(int i=0; i<7; i++){
        output[i] = new int[3];
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            output[i][j] = -1;
        }
    }
    cout<<CoinChange2(6,d,2,output)<<endl;
    return 0;
}
