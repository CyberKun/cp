#include <bits\stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;

    while (t--)
    {
        long long int n;
        cin >> n;
        cin.ignore();

        string str[n];

        for (int i = 0; i < n; i++)
        {

            getline(cin, str[i]);
        }

        vector<pair<int, int>> frequency(n, make_pair(0, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (str[i][j] == '1')
                    frequency[i].second++;
            }
            frequency[i].first = i + 1;
        }

        sort(frequency.begin(), frequency.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.first > b.first; });

        sort(frequency.begin(), frequency.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.second < b.second; });

        if (n == 2)
        {
            cout << 2 << ' ' << 1 << endl;
        }
        else
        {

            for (int i = 0; i < n; i++)
            {
                cout << frequency[i].first << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}