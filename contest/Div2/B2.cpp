#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int n;
        cin >> n;
        int a[n], b[n], c[n];
        int count = 0, flag = 0, count0 = 0, flag0 = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            c[i] = a[i] - b[i];
        }
        int min = INT_MAX, second_min = 0;

        for (int i = 0; i < n; i++)
        {

            if (c[i] < 0)
            {
                count++;
                min = c[i];
            }
            else if (c[i] == 0)
                count0++;

            if (count == 2)
            {
                cout << "NO" << endl;
                flag = 1;
                break;
            }

            if (c[i] >= 0 && c[i] < diff)
            {
                diff = c[i];
            }
        }

        if (flag == 0)
        {
            if (count == 1)
            {
                if (diff + min > 0)
                {
                    cout << "YES" << endl;
                }
            }
        }
    }

    return 0;
}