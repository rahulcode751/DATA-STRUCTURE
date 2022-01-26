// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
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
