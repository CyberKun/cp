#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    long long int n[t], a[t], b[t], c[t];

    for (int i = 0; i < t; i++)
    {
        cin >> n[i] >> a[i] >> b[i] >> c[i];
    }

    for (int i = 0; i < t; i++)
    {
        long long int dist = 0;
        long long int sum = (a[i] + b[i] + c[i]);
        long long int count = (n[i] / sum) * 3;
        dist = (count * sum) / 3;
        while (dist < n[i])
        {
            dist = dist + a[i];
            count++;

            if (dist >= n[i])
                break;

            dist = dist + b[i];
            count++;

            if (dist >= n[i])
                break;

            dist = dist + c[i];
            count++;
        }
        cout << count << endl;
    }

    return 0;
}