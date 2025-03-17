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
        long long int n;
        cin >> n;

        vector<int> vec(n);

        for (int i = 0; i < n; i++)
            cin >> vec[i];

        sort(vec.begin(), vec.end());

        int flag = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (vec[i] == vec[i + 1])
            {
                flag = vec[i];
                break;
            }
        }

        if (flag == 0)
            cout << -1 << endl;
        else
        {
            cout << 1 << endl
                 << flag << endl;
        }
    }

    return 0;
}
