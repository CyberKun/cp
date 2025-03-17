#include <bits\stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;

    while (t--)
    {
        long long int n, m;
        cin >> n >> m;

        int per = 4 * m * n;

        long long int x[n], y[n];

        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }

        for (int i = 1; i < n; i++)
        {
            per = per - (2 * ((m - x[i]) + (m - y[i])));
        }

        cout << per << endl;
    }
    return 0;
}