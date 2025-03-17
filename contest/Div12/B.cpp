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

        vector<int> arr;

        arr.clear();
        arr.resize(n);
        int pt = 0, flag = 0, s1, s2;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        for (int i = n - 1; i > 0; i--)
        {
            if (arr[i] == arr[i - 1])
            {
                s1 = arr[i];
                s2 = arr[i - 1];
                arr.erase(arr.begin() + i);
                arr.erase(arr.begin() + i - 1);
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            int flg = 0;
            for (int i = 0; i < arr.size() - 1; i++)
            {
                if (arr[i + 1] > (arr[i] - 2 * s1) && arr[i + 1] < (arr[i] + 2 * s1))
                {
                    cout << s1 << ' ' << s2 << ' ' << arr[i] << ' ' << arr[i + 1] << endl;
                    flg = 1;
                    break;
                }
            }

            if (flg == 0)
                cout << -1 << endl;
        }
    }

    return 0;
}
