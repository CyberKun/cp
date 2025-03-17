#include <iostream>
using namespace std;

int main()
{
    int n, m, a, b, c;
    cin >> n;
    int num[n];

    for (int i = 0; i < n; i++)
    {
        cin >> m >> a >> b >> c;
        int m1 = m, m2 = m;
        int sum = 0;

        if (m1 > a)
        {
            m1 = m1 - a;
            sum = sum + a;
        }
        else if (m1 <= a)
        {
            sum = sum + m1;
            m1 = 0;
        }

        if (m2 > b)
        {
            m2 = m2 - b;
            sum = sum + b;
        }
        else if (m2 <= b)
        {
            sum = sum + m2;
            m2 = 0;
        }

        int m3 = m1 + m2;

        if (m3 > c)
        {
            sum = sum + c;
        }
        else if (m3 <= c)
        {
            sum = sum + m3;
        }

        num[i] = sum;
    }

    for (int i = 0; i < n; i++)
        cout << num[i] << endl;

    return 0;
}