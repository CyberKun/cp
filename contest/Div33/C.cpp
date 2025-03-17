#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;

    while (t--)
    {
        long long int n, k;
        cin >> n >> k;

        vector<int> num(n);
        int count = 0;

        for (int i = 0; i < n; i++)
            cin >> num[i];

        sort(num.begin(), num.end());

        for (int i = 0, j = num.size() - 1; i < j;)
        {
            if (num[i] + num[j] < k)
            {
                i++;
            }
            else if (num[i] + num[j] > k)
            {
                j--;
            }
            else
            {
                count++;
                i++;
                j--;
            }
        }

        cout << count << endl;
    }

    return 0;
}
