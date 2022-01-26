
#include <bits/stdc++.h>
using namespace std;
class Queue {
    // Two inbuilt queues
    stack<int> q1, q2;
    int curr_size;

public:
    Queue()
    {
        curr_size = 0;
    }

    void push(int x)
    {
        curr_size++;
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.top());
            q1.pop();
        }
        while(!q2.empty()){
            q1.push(q2.top());
            q2.pop();
        }

    }

    void pop()
    {

        // if no elements are there in q1
        if (q1.empty())
            return;
        q1.pop();
        curr_size--;
    }

    int top()
    {
        if (q1.empty())
            return -1;
        return q1.top();
    }

    int size()
    {
        return curr_size;
    }
};

// Driver code
int main()
{
    Queue s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "current size: " << s.size()
         << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();

    cout << "current size: " << s.size()
         << endl;
    return 0;
}
