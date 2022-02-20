// C++ Program for counting sort
#include <bits/stdc++.h>
using namespace std;

int find_max(int a[],int n){
    int max = INT_MIN;
    for(int i=0; i<n; i++){
        if(a[i]> max) max = a[i];
    }
    return max;
}
void countSort(int a[],int n)
{
	int *c;
	int max = find_max(a,n);
	c = new int[max+1];
	for(int i=0; i<max+1; i++) c[i] = 0;
	for(int i=0; i<n; i++) c[a[i]]++;
	int i=0,j=0;
	while(i < max+1){
        if(c[i] > 0){
        a[j] = i;
        c[i]--;
        j++;
        }
        else{
            i++;
        }
	}
}

int main()
{
	int arr[] = {6,3,9,10,15,6,8,12,3,6};
	countSort(arr,10);
    for(int i=0; i<10; i++) cout<<arr[i]<<" ";
	return 0;
}


