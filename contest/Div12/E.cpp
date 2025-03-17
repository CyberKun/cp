#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int t;
    cin >> t;

    while (t--) {
        long long int n, m;
        cin >> n >> m;

        vector<int> a(n);
        vector<int> b(m);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        multiset<int> setA(a.begin(), a.end());
        multiset<int> setB(b.begin(), b.end());

        bool isPossible = true;

        for (auto bi : setB) {
            auto it = setA.find(bi);
            if (it != setA.end()) {
                setA.erase(it);
            } else {
                bool found = false;
                for (auto ai = setA.begin(); ai != setA.end(); ++ai) {
                    if (abs(bi - *ai) <= 1) {
                        int newElement = *ai + bi;
                        setA.erase(ai);
                        setA.insert(newElement);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    isPossible = false;
                    break;
                }
            }
        }

        if (isPossible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
