/// qustion link -> https://practice.geeksforgeeks.org/problems/k-closest-elements3619/1#
/*
Input:
N = 13
arr[] = {12, 16, 22, 30, 35, 39, 42,
         45, 48, 50, 53, 55, 56}
K = 4, X = 35
Output: 39 30 42 45
Explanation:
First closest element to 35 is 39.
Second closest element to 35 is 30.
Third closest element to 35 is 42.
And fourth closest element to 35 is 45.
*/
vector<int> printKClosest(vector<int> arr, int n, int k, int x)
{
    vector<int> v;
    priority_queue<int> p1;
    priority_queue<int, vector<int>, greater<int>> p2;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > x) p2.push(arr[i]);
        else if (arr[i] < x) p1.push(arr[i]);
    }

    if (p1.size() == 0 && p2.size() == 0) return v;
    else if (p1.size() != 0 && p2.size() == 0)
    {
        while (k--)
        {
            v.push_back(p1.top());
            p1.pop();
        }
        return v;
    }

    else if (p1.size() == 0 && p2.size() != 0)
    {
        while (k--)
        {
            v.push_back(p2.top());
            p2.pop();
        }
        return v;
    }

    while(k)
    {
        int a = abs(p1.top() - x);
        int b = abs(p2.top() - x);
        if (p1.size() != 0 && p2.size() == 0)
        {
            while (k--)
            {
                v.push_back(p1.top());
                p1.pop();
            }
            return v;
        }
        else if (p1.size() == 0 && p2.size() != 0)
        {
            while (k--)
            {
                v.push_back(p2.top());
                p2.pop();
            }
            return v;
        }
        if (b > a)
        {
            v.push_back(p1.top());
            p1.pop();
        }
        else if (a > b)
        {
            v.push_back(p2.top());
            p2.pop();
        }
        else if (a == b)
        {
            if (p1.top() > p2.top())
            {
                v.push_back(p1.top());
                p1.pop();
            }
            else if (p1.top() < p2.top())
            {
                v.push_back(p2.top());
                p2.pop();
            }
        }
        k = k - 1;
    }

    return v;
}
