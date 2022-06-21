/*
Largest Bitonic Subarray
Send Feedback
You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
Input Format:
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array
Output Format:
Length of Largest Bitonic subsequence
Input Constraints:
1<= N <= 100000
Sample Input 1:
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
2
1 5
Sample Output 2:
2
*/
#include<bits/stdc++.h>
using namespace std;

int LIS(int *input,int n)
{
    int *output = new int[n];
    output[0] = 1;

    for(int i=0; i<n; i++)
    {
        output[i] = 1;
        for(int j=i-1; j>=0; j--)
        {
            if(input[i] < input[j])
            {
                continue;
            }
            int possible = output[j]+1;
            if(possible > output[i])
            {
                output[i] = possible;
            }
        }
    }
    int best = 0;
    for(int i=0; i<n; i++)
    {
        if(best < output[i])
        {
            best = output[i];
        }
    }
    delete []output;
    return best;
}

int main()
{
    int n;
    cin>>n;
    int *input = new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    int ans = LIS(input,n);
    cout<<ans<<endl;
    delete []input;
    return 0;
}

