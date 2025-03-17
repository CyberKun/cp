#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Function to calculate the maximum possible sword strength
int max_sword_strength(string L, string R) {
    int n = R.size();
    int strength = 0;
    
    // Make L the same length as R by padding with leading zeros if necessary
    while (L.size() < R.size()) {
        L = "0" + L;
    }
    
    // Find the first differing digit
    int diff_index = -1;
    for (int i = 0; i < n; i++) {
        if (L[i] != R[i]) {
            diff_index = i;
            break;
        }
    }
    
    // If all digits are the same, strength is 0
    if (diff_index == -1) return 0;
    
    // Maximize the strength by making the differing digit as different as possible
    strength = abs(L[diff_index] - R[diff_index]) * pow(10, n - diff_index - 1);
    
    // Add the max possible difference for remaining digits
    for (int i = diff_index + 1; i < n; i++) {
        strength += 9 * pow(10, n - i - 1);
    }
    
    return strength;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string L, R;
        cin >> L >> R;
        cout << max_sword_strength(L, R) << endl;
    }
    return 0;
}
