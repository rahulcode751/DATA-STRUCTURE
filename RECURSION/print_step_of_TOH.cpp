#include<iostream>
using namespace std;

int toh(int n){
   if(n==0){
    return 0;
   }
   return toh(n-1) + 1 + toh(n-1);
}

void printSteps(int n, char s, char d, char h){
   if(n==0){
    return;
   }
    printSteps(n-1,s,h,d);
    cout<<"Moving disk "<<n<<" from "<<s<<" to "<<d<<endl;
    printSteps(n-1,h,d,s);
}

int main(){
  int n;
  cin>>n;
  cout<<toh(n)<<endl;
  printSteps(n,'A','C','B');

  return 0;
}
