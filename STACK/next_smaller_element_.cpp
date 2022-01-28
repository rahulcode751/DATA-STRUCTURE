/*
Next Smaller Element
Difficulty Level : Medium
Last Updated : 06 Oct, 2021
Given an array, print the Next Smaller Element (NSE) for every element. The NSE for an element x is the first smaller element on the right side of x in array. Elements for which no smaller element exist (on right side), consider NSE as -1.
Examples:
a) For any array, rightmost element always has NSE as -1.
b) For an array which is sorted in increasing order, all elements have NSE as -1.
c) For the input array [4, 8, 5, 2, 25}, the NSE for each element are as follows.

Element         NSE
   4      -->    2
   8      -->    5
   5      -->    2
   2      -->   -1
   25     -->   -1
d) For the input array [13, 7, 6, 12}, the next smaller elements for each element are as follows.

  Element        NSE
   13      -->    7
   7       -->    6
   6       -->   -1
   12      -->   -1
*/

///  T = O(N)
///  S = O(N)
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int array[n];
  for(int i=0; i<n; i++){
    cin>>array[i];
  }
  stack<pair<int,int>> s;
  s.push({array[0],0});
  vector<int> ans;

  for(int i=0; i<n; i++){
    while(!s.empty() && s.top().first > array[i]){
        ans[s.top().second] = array[i];
        s.pop();
    }
    s.push({array[i],i});
  }
  while(!s.empty()){
    ans[s.top().second] = -1;
    s.pop();
  }
   for(int i=0; i<n; i++){
    cout<<ans[i]<<" ";
  }

  return 0;
}
