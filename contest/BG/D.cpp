#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<int> vec(n);

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        if (n == 2)
        {
            cout << vec[1] - vec[0] << endl;
        }
        else
        {
            long long int pw = vec[n-2];
            for (int i = 0; i < n - 2; i++)
            {
                pw = pw - vec[i];
            }
            cout << vec[n - 1] - pw << endl;
        }
    }

    return 0;
}