#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int p[t], q[t], a[t], b[t];

    for (int i = 0; i < t; i++)
    {
        cin >> p[i] >> q[i] >> a[i] >> b[i];
    }

    for (int i = 0; i < t; i++)
    {
        int count = 0;
        int flag = 0;
        if (b[i] < q[i])
        {
            cout << -1 << endl;
            flag = 1;
        }
        else if (b[i] > q[i])
        {
            count = count + (b[i] - q[i]);
            p[i] = p[i] + count;
        }
        if (p[i] < a[i] && flag == 0)
        {
            cout << -1 << endl;
            flag = 1;
        }
        else if (p[i] > a[i] && flag == 0)
        {
            count = count + (p[i] - a[i]);
        }
        if (flag == 0)
        {
            cout << count << endl;
        }
    }

    return 0;
}