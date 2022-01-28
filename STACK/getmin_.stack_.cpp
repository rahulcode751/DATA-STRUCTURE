/*
You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

Example 1:

Input:
push(2)
push(3)
pop()
getMin()
push(1)
getMin()
Output: 3 2 1
Explanation: In the first test case for
query
push(2)  the stack will be {2}
push(3)  the stack will be {2 3}
pop()    poped element will be 3 the
         stack will be {2}
getMin() min element will be 2
push(1)  the stack will be {2 1}
getMin() min element will be 1
*/
class Solution{
    int minEle;
    stack<int> s;
    public:

       /*returns min element from stack*/

       int getMin(){
           if(s.size() == 0) return -1;
           return minEle;
           //Write your code here
       }

       /*returns poped element from stack*/
       int pop(){
           if(s.empty()) return -1;
           int v = s.top();
           if(v>=minEle){
               int t = s.top();
               s.pop();
               return t;
           }
           else{
               int r = minEle;
               int y = 2*minEle - v;
               s.pop();
               minEle = y;
               return r;
           }
           //Write your code here
       }

       /*push element x into the stack*/
       void push(int a){
           if(s.empty()){
               minEle = a;
               s.push(a);
           }
           else{
               int x = a;
               if(a<minEle){
                   x = 2*a - minEle;
                   minEle = a;
               }
               s.push(x);
           }

           //Write your code here
       }
};
