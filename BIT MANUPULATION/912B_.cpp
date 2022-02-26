#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n)
{
    return (ceil(log2(n)) == floor(log2(n)));
}
int main() {
	// your code goes here
	int n,k;
	cin>>n>>k;
	if(k == 1) cout<<n<<endl;
	else if(n < k) cout<<n<<endl;
	else{
		int sum = 0;
		int  i=0;
		while(k and n>0){
			if(isPowerOfTwo(n) == 1){
				sum = sum xor n;
				k--;
			}
			n--;
		}
		cout<<sum<<endl;
	}
	return 0;
}
