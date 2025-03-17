#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);
        vector<int> diff(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            diff[i] = a[i] - b[i];
        }

        int neg_count = 0;
        int min_diff = INT_MAX;
        int sec_min_diff = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (diff[i] < 0)
            {
                neg_count++;
            }
            if (diff[i] < min_diff)
            {
                sec_min_diff = min_diff;
                min_diff = diff[i];
            }
            else if (diff[i] < sec_min_diff)
            {
                sec_min_diff = diff[i];
            }
        }

        if (neg_count > 1)
        {
            cout << "NO" << endl;
        }
        else if (neg_count == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            if (min_diff + sec_min_diff >= 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}