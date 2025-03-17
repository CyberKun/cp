#include <iostream>
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

    if (n == 1)
    {
        cout << arr[0];
    }
    else
    {
        sort(arr, arr + n);
        if (n == 3)
        {
            cout << arr[1];
        }
        else
        {
            cout << arr[2];
        }
    }

    return 0;
}
