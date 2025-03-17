#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        long long int n, m;
        int minu = INT_MAX, index = 0;
        cin >> n >> m;

        vector<int> vec1(n);
        vector<int> vec2(m);
        vector<int> vec3(m);

        for (int i = 0; i < n; i++)
            cin >> vec1[i];

        for (int i = 0; i < m; i++)
        {
            cin >> vec2[i];

            if (minu > vec2[i])
                index = i;

            minu = min(minu, vec2[i]);
        }
        int j = 0;

        for (int i = index; i < m; i++, j++)
        {
            vec3[j] = vec2[i];
        }

        for (int i = 0; i < index; i++, j++)
        {
            vec3[j] = vec2[i];
        }

        for (int i = 0; i < (n - m + 1); i++)
        {
            // if (vec1[i] == vec3[0])
            //{
            if (lexicographical_compare(vec3.begin(), vec3.end(), vec1.begin() + i, vec1.begin() + i + m))
            {
                int j = i;

                for (int k = 0; k < m; k++, j++)
                {
                    vec1[j] = vec3[k];
                }
            }
            //}
            // else if (vec1[i] > vec3[0])
            // {
            //     while (vec1[i] > vec3[0] && i < (n - m + 1))
            //     {
            //         vec1[i] = vec3[0];
            //         i++;
            //     }

            //     int j = i;

            //     for (int k = 1; k < m; k++, j++)
            //     {
            //         vec1[j] = vec3[k];
            //     }
            // }
        }

        for (int i = 0; i < n; i++)
            cout << vec1[i] << ' ';
        cout << endl;
    }

    return 0;
}
