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
        int n, flag = 0, index = 0, Rfound = 0, Rindex = 0, Lfound = 0, Lindex = 0;
        cin >> n;
        char str[n];

        for (int i = 0; i < n; i++)
            cin >> str[i];

        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'R' && Rfound == 0)
            {
                Rindex = i;
                Rfound = 1;
                break;
            }
        }

        for (int j = n - 1; j >= 0; j--)
        {
            if (str[j] == 'L' && Lfound == 0)
            {
                Lindex = j;
                Lfound = 1;
                break;
            }
        }

        if (Rfound == 1 && Lfound == 1)
        {
            if (Rindex < Lindex)
            {
                cout << 0 << endl;
            }
            else if (Rindex == Lindex + 1)
            {
                cout << Lindex << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else
            cout << -1 << endl;
    }

    return 0;
}
