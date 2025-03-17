#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;

    while (t--)
    {
        long long int a[5];
        cin >> a[0] >> a[1] >> a[3] >> a[4];

        int maxcount = 0, count = 0;

        for (int i = -100; i < 101; i++)
        {
            a[2] = i;
            count = 0;
            for (int i = 2; i < 5; i++)
            {
                if (a[i] == (a[i - 1] + a[i - 2]))
                    count++;
            }
            if (count > maxcount)
                maxcount = count;

            if (maxcount == 3)
                break;
        }

        cout << maxcount << endl;
    }

    return 0;
}
