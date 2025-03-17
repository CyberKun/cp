#include <bits/stdc++.h>
using namespace std;

void rota(const vector<int> &B, vector<int> &minRotation)
{
    int m = B.size();
    int minB = INT_MAX, index = 0;
    for (int i = 0; i < m; i++)
    {
        if (minB > B[i])
        {
            minB = B[i];
            index = i;
        }
    }

    int j = 0;
    for (int i = index; i < m; i++, j++)
    {
        minRotation[j] = B[i];
    }
    for (int i = 0; i < index; i++, j++)
    {
        minRotation[j] = B[i];
    }
}

bool rep(vector<int> &A, const vector<int> &minRotation, int m)
{
    bool replaced = false;
    int n = A.size();

    for (int i = 0; i <= n - m; i++)
    {
        bool shouldReplace = false;
        for (int k = 0; k < m; k++)
        {
            if (minRotation[k] < A[i + k])
            {
                shouldReplace = true;
                break;
            }
            else if (minRotation[k] > A[i + k])
            {
                break;
            }
        }

        if (shouldReplace)
        {
            for (int k = 0; k < m; k++)
            {
                A[i + k] = minRotation[k];
            }
            replaced = true;
        }
    }

    return replaced;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        long long int n, m;
        cin >> n >> m;

        vector<int> A(n);
        vector<int> B(m);
        vector<int> minRotation(m);

        for (int i = 0; i < n; i++)
            cin >> A[i];

        for (int i = 0; i < m; i++)
            cin >> B[i];

        rota(B, minRotation);

        bool replaced;
        do
        {
            replaced = rep(A, minRotation, m);
        } while (replaced);

        for (int i = 0; i < n; i++)
        {
            cout << A[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
