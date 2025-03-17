#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (arr[0] > 15)
    {
        cout << 15;
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            int diff = arr[i + 1] - arr[i];
            if (diff > 15)
            {
                cout << arr[i] + 15;
            }
        }
    }

    return 0;
}