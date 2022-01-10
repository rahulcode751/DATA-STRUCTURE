ssss#include<iostream>
using namespace std;

int isPresent(int a[], int n, int x,int i){
	if(i==n)
	{
		return -1;
	}
	if(a[i]==x)
	{
		return i;
	}
	return isPresent(a,n,x,i+1);
}

int main()
{
	int a[] = {1,2,3,4,5,6};
	cout<<isPresent(a,6,4,0);
}


