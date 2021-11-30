
#include <bits/stdc++.h>

using namespace std;

class Queue {
    // Two inbuilt queues
    stack<int> q1, q2;

    // To maintain current number of
    // elements
    int curr_size;

public:
    Queue()
    {
        curr_size = 0;
    }

    void push(int x)
    {
        curr_size++;

        // Push x first in empty q2
        q2.push(x);

        // Push all the remaining
        // elements in q1 to q2.
        while (!q1.empty()) {
            q2.push(q1.top());
            q1.pop();
        }

        // swap the names of two queues
       /* stack<int> q = q1;
        q1 = q2;
        q2 = q; */
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
