#include<iostream>
using namespace std;

bool isPresent(int a[], int n, int x){
	if(n==0)
	{
		return false;
	}
	if(a[0]==x)
	{
		return true;
	}
	return isPresent(a+1,n-1,x);
}

bool isPresent3(int a[], int n, int x){
	if(n==0)
	{
		return false;
	}
	if(a[n-1]==x)
	{
		return true;
	}
	return isPresent3(a,n-1,x);
}

bool isPresent2(int a[], int n, int x){
	if(n==0)
	{
		return false;
	}
	
	bool remArray = isPresent2(a+1,n-1,x);
	if(remArray){
		return true;
	}
	
	if(a[0]==x)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isPresent4(int a[], int n, int x,int i){
	if(i==n)
	{
		return false;
	}
	if(a[i]==x)
	{
		return true;
	}
	return isPresent4(a,n,x,i+1);
}


int main()
{
	int a[] = { 1,2,3,4,5,6};
	if(isPresent3(a,6,3))
	{
		cout<<"found"<<endl;
	}
	else
	{
		cout<<"not found"<<endl;
	}
	
	if(isPresent4(a,6,3,1))
	{
		cout<<"found"<<endl;
	}
	else
	{
		cout<<"not found"<<endl;
	}

	 return 0;
}


