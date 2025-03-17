#include <iostream>
#include <vector>

using namespace std;

vector<int> win(int n, vector<int> &arr)
{
    int sum = 0;
    vector<int> results;
    for (int e : arr)
    {
        int g = (e == 1) ? 0 : (e - 1) % 2;
        sum ^= g;
        results.push_back(sum != 0 ? 1 : 2);
    }
    return results;
}

int main()
{
    int n;

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    vector<int> result = win(n, arr);

    for (int res : result)
    {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}