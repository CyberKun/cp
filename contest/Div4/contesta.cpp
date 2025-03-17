#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int num[n];

    for(int i=0;i<n;i++)
    {cin >> num[i];
    }


    for(int i=0;i<n;i++)
    {
        int count = 0;
        int a=num[i]-1;
        int b=1;
        while(a>0)
        {
            a--;
            b++;
            count++;
        }
        cout << count << endl;

    }

    

    return 0;
}