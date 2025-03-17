#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int n[t];

    vector<vector<int>> num1(t);
    vector<vector<int>> num2(t);
    vector<vector<int>> num3(t);

    for (int i = 0; i < t; i++)
    {
        cin >> n[i];
        num1[i].resize(n[i]);
        num2[i].resize(n[i]);
        num3[i].resize(n[i]);
        for (int j = 0; j < n[i]; j++)
        {
            cin >> num1[i][j];
        }
        for (int k = 0; k < n[i]; k++)
        {
            cin >> num2[i][k];
        }
    }


    for (int i = 0; i < t; i++)
    {
        int diff = num1[i][n[i]-1];
        int j = 0;
        while (j < n[i]-1)
        {
            if ((num1[i][j] - num2[i][j+1])>0)
            {
                diff = diff + (num1[i][j] - num2[i][j+1]);
            }
            j++;
        }
            cout << diff << endl;
    }

    return 0;
}