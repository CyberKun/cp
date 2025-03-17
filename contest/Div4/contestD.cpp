#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> m;
    int *res[m];

    for(int i=0;i<m;i++)
    {
        cin >> n;
        int num[n];
        res[i]=(int*)malloc(n*sizeof(int));

        for(int i=0;i<n;i++)
        cin >> num[i];

        for(int i=0;i<n;i++)
        {
            if(num[i]!=num[i+1])
            {

            }
        }

    }


    

    return 0;
}