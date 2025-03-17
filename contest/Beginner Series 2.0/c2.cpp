#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int num[n];

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    for (int i = 0; i < n; i++)
    {
        int flag = 0,a=0,b=0;
        while(num[i]!=0)
        {
            if(flag==0)
            {
                a=num[i]-6;
            }
            if(flag==1)
            {
                b=num[i]-4;
            }
            
        }
    }

    return 0;
}