#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int k[t], n[t];

    vector<string> chr(t);

    for (int i = 0; i < t; i++)
    {
        cin >> n[i] >> k[i];
        chr[i].resize(n[i]);
        getchar();
        getline(cin, chr[i]);
    }

    for (int i = 0; i < t; i++)
    {
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        int count4 = 0;
        int count5=0;
        int flag = 0;
        for (int j = 0; j < n[i]; j++)
        {
            if (chr[i][j] == 'B')
            {
                count2++;
                count3++;
            }
            if (chr[i][j] == 'W')
            {
                count1++;
                count2 = 0;
                count3++;
            }
            if (count2 == k[i])
            {
                cout << 0 << endl;
                flag = 1;
                break;
            }
            if(count3>count5)
            {
                count5=count3;
            }
            if (count3 == k[i])
            {
                count4 = count1;
            }
        }
        if (flag == 0)
            cout << count4 << endl;
    }

    return 0;
}