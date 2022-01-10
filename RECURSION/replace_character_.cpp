#include <iostream>
using namespace std;

void replaceChar(char input[])
{
    if (input[0] == '\0')
    {
        return;
    }
    if (input[0] == 'a')
    {
        input[0] = 'x';
    }
    replaceChar(input + 1);
}

int main()
{
    char input[100];
    cin >> input;
    replaceChar(input);
    cout << input << endl;

    return 0;
}
