#include <iostream>
using namespace std;

void print_subs(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }
    print_subs(input.substr(1), output + input[0]); /// include
    print_subs(input.substr(1), output);            /// exclude
}

void print_subs2(char input[], char output[], int i)
{
    if (input[0] == '\0')
    {
        output[i] = '\0';
        cout << output << endl;
        return;
    }
    /// excluding
    print_subs2(input + 1, output, i);
    /// including
    output[i] = input[0];
    print_subs2(input + 1, output, i + 1);
}

int main()
{
    char input[10];
    cin >> input;
    char output[100];

    string in;
    cin >> in;
    string out = "";

    print_subs(in, out);
    cout << endl;

    print_subs2(input, output, 0);

    return 0;
}
