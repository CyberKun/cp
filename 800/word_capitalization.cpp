#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int n;
    getline(cin,str);

    if(str[0]>96) str[0]-=32;

    cout << str;
    return 0;
}