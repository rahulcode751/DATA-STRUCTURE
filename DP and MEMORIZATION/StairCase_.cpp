#include <iostream>
using namespace std;

int count(int x)
{
    return calc(x + 1);
}
int calc(int n)
{
    if (n <= 1)
        return n;
    return calc(n-1) + calc(n-2) + calc(n-3);
}


int main ()
{
    int n ;
    cout<<("Enter number of stairs : ");
    cin>>n;
    cout<<("Number of ways = %d", count(n));

    return 0;
}
