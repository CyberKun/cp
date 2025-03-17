#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int n[t];

    vector<vector<int>> num(t);

    for (int i = 0; i < t; i++)
    {
        cin >> n[i];
        num[i].resize(n[i]);
        for (int j = 0; j < n[i]; j++)
        {
            cin >> num[i][j];
        }
    }

    for (int i = 0; i < t; i++)
    {
        int count = 0;
        int flag = 0;
        for (int j = 0; j < n[i] - 1; j++)
        {
            for (int k = j + 1; k < n[i]; k++)
            {
                flag = 0;
                if (num[i][k] != num[i][j])
                {
                    count++;
                    cout << count;
                }
                if (count == (n[i] - 1))
                {
                    cout << "YES" << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag == 0)
        {
            cout << "NO" << endl;
        }
        else if (flag == 1)
        {
            int count = 0;
            for (int j = 0; j < n[i] - 1; j++)
            {
                int flag = 0;
                for (int k = j + 1; k < n[i]; k++)
                {
                    if (num[i][k] != num[i][j])
                    {
                        cout << j + 1 << ' ' << k + 1 << endl;
                        count++;
                    }
                    if (count == n[i] - 1)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                    break;
            }
        }
    }

 

    return 0;
}