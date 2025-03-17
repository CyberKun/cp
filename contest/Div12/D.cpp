#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;

    while (t--)
    {
        long long int n, m;
        cin >> n >> m;

        vector<int> a(n);
        vector<int> b(m);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int flg = 0;

        if (a.size() < b.size())
        {
            cout << "NO" << endl;
        }
        else
        {
            for (int i = 0; i < a.size();)
            {
                int flag = 0;
                if (i >= b.size())
                {
                    cout << "NO" << endl;
                    flag = 1;
                    break;
                }
                if (a[i] == b[i])
                {
                    i++;
                }
                else
                {
                    for (int j = i + 1; j < a.size(); j++)
                    {
                        if (abs(a[i] - a[j]) <= 1)
                        {
                            a[i] = a[i] + a[j];
                            a.erase(a.begin() + j);
                            if (a.size() < b.size())
                            {
                                break;
                            }
                            else if (a[i] != b[i])
                            {
                                sort(a.begin(), a.end());
                            }
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0)
                    {
                        cout << "NO" << endl;
                        flg = 1;
                        break;
                    }
                }
            }

            if (flg == 0)
            {
                cout << "YES" << endl;
            }
        }
    }

    return 0;
}