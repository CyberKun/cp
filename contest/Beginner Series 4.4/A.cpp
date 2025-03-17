#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        string str;
        cin >> str;

        if (str[1] == '=')
        {
            if (str[0] != str[2])
                str[0] = str[2];
        }
        else if (str[1] == '<')
        {
            if (str[0] > str[2] && str[2] != '0')
                str[0] = str[2] - 1;
            else if (str[0] > str[2] && str[2] == '0')
                str[1] = '>';
            else if (str[0] == str[2])
                str[1] = '=';
        }
        else
        {
            if (str[0] < str[2] && str[0] != '0')
                str[2] = str[0] - 1;
            else if (str[0] < str[2] && str[0] == '0')
                str[1] = '<';
            else if (str[0] == str[2])
                str[1] = '=';
        }

        cout << str << endl;
    }

    return 0;
}
