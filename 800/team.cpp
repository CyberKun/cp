#include<iostream>
using namespace std;

int main(){
    int n,count2=0;
    cin >> n;
    int arr[n][3];
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> arr[i][j];}}
    
    for(int i=0;i<n;i++){
        int count1=0;
        for(int j=0;j<3;j++){
           if(arr[i][j]==1)
           count1++;}
        if(count1>1)
        count2++;}

    cout << count2;
    return 0;}