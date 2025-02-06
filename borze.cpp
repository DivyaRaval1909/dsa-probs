#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int len = s.length();

    for (int i = 0; i < len; )
    {
        if (i < len - 1 && s[i] == '.' && s[i + 1] == '-')
        {
            cout << 0;
            i += 2; // Skip over the two characters processed
        }
        else if (i < len - 1 && s[i] == '-' && s[i + 1] == '.')
        {
            cout << 1;
            i += 2; // Skip over the two characters processed
        }
        else
        {
            cout << 2;
            i++; // Move to the next character
        }
    }

    return 0;
}
