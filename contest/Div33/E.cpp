#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int flag = 0;

        int num[n];

        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }

        for (int i = 1; i < n; i++)
        {
            int minu = min(num[i], num[i - 1]);
            num[i] -= minu;
            num[i - 1] -= minu;

            if (num[i] < num[i - 1])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            cout << "YES" << endl;

        else
            cout << "NO" << endl;
    }

    return 0;
}