// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> queue, int k) {
    // add code here.
    stack<int> s;
    for(int i=0; i<k; i++){
        s.push(queue.front());
        queue.pop();
    }
    while(!s.empty()){
        queue.push(s.top());
        s.pop();
    }
    int n = queue.size();
    for(int i=1; i<=n-k; i++){
        queue.push(queue.front());
        queue.pop();
    }
    return queue;
}
