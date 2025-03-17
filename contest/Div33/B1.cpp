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

        vector<vector<long long int>> cds(n, vector<long long int>(m));
        vector<pair<long long int,long long int>> ans(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> cds[i][j];
            }
            sort(cds[i].begin(), cds[i].end());
            ans[i].second = cds[i][0];
            ans[i].first = i + 1;
        }

        sort(ans.begin(), ans.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.second < b.second; });

        int flag = 0;
        int num = 0;

        if (m > 1)
        {
            for (int j = 0; j < m; j++)
            {
                for (int i = 0; i < n; i++)
                {
                    if (cds[ans[i].first - 1][j] != num)
                    {
                        cout << -1 << endl;
                        flag = 1;
                        break;
                    }
                    num++;
                }
                if (flag == 1)
                    break;
            }
        }

        if (flag == 0)
        {
            for (int i = 0; i < n; i++)
            {
                cout << ans[i].first << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}
