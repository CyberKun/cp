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

        vector<int> arr(n);
        int pt = 0, flag = 1;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 != 0)
            {
                pt++;
            }
            else
            {
                flag = 0;
            }
        }

        if (flag == 0)
        {
            cout << pt + 1 << endl;
        }
        else
        {
            cout << pt - 1 << endl;
        }
    }

    return 0;
}
