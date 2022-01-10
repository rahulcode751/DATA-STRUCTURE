#include <iostream>
using namespace std;

void length(char input[], int n, int &count)
{
    if (n == 0 || input[0] == '\0')
    {
        cout << count << endl;
        return;
    }
    if (input[0] != ' ' || input[0] != '\t')
    {
        count++;
    }
    length(input + 1, n - 1, count);
}

int length1(char input[])
{
    if (input[0] == '\0')
    {
        return 0;
    }
    return 1 + length1(input + 1);
    
}

int main()
{
    char input[100];
    cin >> input;
    int c = 0;
    int n = 100;
    length(input, n, c);

    int l = length1(input);
    cout << l << endl;
    return 0;
}
