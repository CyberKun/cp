#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();

    string str[n];

    for(int i=0;i<n;i++)
    {
        getline(cin,str[i]);
    }

    for(int i=0;i<n;i++)
    {
        int m=str[i].length();
        for(int j=0;j<m;j++)
        {
            if(str[i][j]=='p')
            str[i][j]='q';
            else if(str[i][j]=='q')
            str[i][j]='p';
            
        }

        reverse(str[i].begin(),str[i].end());
    }

     for(int i=0;i<n;i++)
     cout << str[i] << endl;

    return 0;
}