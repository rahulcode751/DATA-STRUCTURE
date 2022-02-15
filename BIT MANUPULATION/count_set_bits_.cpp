#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int num;
	cin>>num;
	int temp = num;
	int counter = 0;

	while(temp > 0){
		int ans = temp&1;
	    if(ans != 0) counter++;
	    temp = temp>>1;
	}
	cout<<counter;
	return 0;
}
