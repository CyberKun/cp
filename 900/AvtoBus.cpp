#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int n;
        cin >> n;

        int flag = 0;

        long long int min, max;

        if (n % 6 == 0)
        {
            min = n / 6;
        }
        else
        {
            long long int s = n / 6;

            long long int f = n % 6;
            while (f % 4 != 0 && f <= n)
            {
                f = f + 6;
                s--;
                if (f > n)
                    flag = 1;
            }
            min = s + (f / 4);
        }
        if (flag != 1)
        {
            if (n % 4 == 0)
            {
                max = n / 4;
            }
            else
            {
                long long int s = n / 4;

                long long int f = n % 4;
                while (f % 6 != 0 && f <= n)
                {
                    f = f + 4;
                    s--;
                    if (f > n)
                        flag = 1;
                }
                max = s + (f / 6);
            }
        }

        if (flag == 0)
            cout << min << " " << max << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}