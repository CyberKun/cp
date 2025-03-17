#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int n, m;
        cin >> n >> m;

        vector<vector<long long int>> a(n);
        vector<long long int> rowSUM(n, 0);
        vector<long long int> colSUM(m, 0);

        string str;
        cin.ignore();
        getline(cin, str);

        for (int i = 0; i < n; i++)
        {
            a[i].resize(m);
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                rowSUM[i] += a[i][j];
            }
        }

        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                colSUM[j] += a[i][j];
            }
        }

        // cout << "Row Sum : ";

        // for (int i = 0; i < n; i++)
        // {

        //     cout << rowSUM[i] << " ";
        // }
        // cout << endl;

        // cout << "Column Sum : ";

        // for (int i = 0; i < m; i++)
        // {

        //     cout << colSUM[i] << " ";
        // }
        // cout << endl;

        int i = 0, j = 0, k = 0;
        while (i + j != (n + m - 2))
        {
            if (str[k] == 'D')
            {
                a[i][j] = -(rowSUM[i]);
                rowSUM[i] = 0;
                colSUM[j] += a[i][j];
                i++;
            }
            else
            {
                a[i][j] = -(colSUM[j]);
                colSUM[j] = 0;
                rowSUM[i] += a[i][j];
                j++;
            }
            k++;
        }
        a[n - 1][m - 1] = -(rowSUM[n - 1]);

        rowSUM[n - 1]=0;
        colSUM[m - 1]=0;

        // cout << "Row Sum : ";

        // for (int i = 0; i < n; i++)
        // {

        //     cout << rowSUM[i] << " ";
        // }
        // cout << endl;

        // cout << "Column Sum : ";

        // for (int i = 0; i < m; i++)
        // {

        //     cout << colSUM[i] << " ";
        // }
        // cout << endl;


        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}