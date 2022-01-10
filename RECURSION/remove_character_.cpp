#include <iostream>
using namespace std;

void removeA(char input[])
{
    if (input[0] == '\0')
    {
        return;
    }
    if (input[0] != 'a')
    {
        removeA(input + 1);
    }
    else
    {
        for (int i = 0; input[i] != '\0'; i++)
        {
            input[i] = input[i + 1];
        }
        removeA(input);
    }
}

int main()
{
    char input[100];
    cin >> input;
    removeA(input);
    cout << input << endl;
    return 0;
}
