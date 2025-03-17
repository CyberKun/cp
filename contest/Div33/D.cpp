#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;

    while (t--)
    {
        long long int n;
        cin >> n;

        vector<int> num(n);
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            int a = min(num[i], num[i + 1]);
            num[i] -= a;
            num[i + 1] -= a;
        }

        int flag = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (num[i] > num[i + 1])
            {
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}
