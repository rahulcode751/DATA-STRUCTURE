#include<iostream>
using namespace std;

int lastIndex(int a[],int n,int x,int i){
    if(i==-1){
    	cout<<"invalid index ";
        return -1;
    }

    if(a[i]==x){
        return i;
    }

    return lastIndex(a,n,x,i-1);
}
int lastIndex2(int a[],int n,int x){
    if(n==0){
        return -3;
    }

    if(a[n-1]==x){
        return n-1;
    }

    return lastIndex2(a,n-1,x);
}

int lastIndex3(int a[],int n,int x, int i){
    if(i==n){
        return -1;
    }
    int indexInRem = lastIndex3(a,n,x,i+1);
    if(indexInRem == -1){
        if(a[i]==x){
            return i;
        }else{
          return -1;
        }
    }else{
       return indexInRem;
    }
}
int main(){
  int a[] = {5,5,6,5,6,7};
  cout<<lastIndex(a, 6, 8, 0)<<endl;
  return 0;
}

