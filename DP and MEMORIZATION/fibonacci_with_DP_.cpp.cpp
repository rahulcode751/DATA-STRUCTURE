#include <iostream>
using namespace std;

// Recursion  o(2^n)
int fib(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	return fib(n - 1) + fib(n-2);
}

/// Top Down DP (just fancy name) => Recursive + store result => Memorization   O(N)
int fib2(int n,int *arr){
    if(n==0 || n==1){
        return n;
    }

    if(arr[n] != 0){
        return arr[n];
    }

    int output = fib2(n-1,arr) + fib2(n-2,arr);
    arr[n] = output;   /// store for future use
    return output;
}

/// Bottom Up DP (just fancy name) => Iterative  O(N)
int fib3(int n){

   int *arr = new int[n+1];
   arr[0] = 0;
   arr[1] = 1;

   for(int i=2;i<=n;i++){
    arr[i] = arr[i-1] + arr[i-2];
   }

   int output = arr[n];
   delete []arr;
   return output;
}

int main(){
   int n;
   cin>>n;

   int *arr = new int[n+1];
   for(int i=0;i<=n;i++){
    arr[i] = 0;     /// Initialise with any invalid value like -2,-10..
   }
   cout<<fib3(n)<<endl;
   cout<<fib2(n,arr)<<endl;
   cout<<fib(n)<<endl;

   delete []arr;    /// do not forget to delete array
}
