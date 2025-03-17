#include <iostream>
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
        return 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int diff = arr[i + 1] - arr[i];
        if (arr[i] >= 90)
        {
            cout << 90;
            return 0;
        }
        if (diff > 15)
        {
            int ans = arr[i] + 15;
            cout << ans;
            return 0;
        }
    }

    if (arr[n - 1] < 90 && arr[n - 1] + 15 <= 90)
    {
        cout << arr[n - 1] + 15;
    }
    else
    {
        cout << 90;
    }

    return 0;
}
