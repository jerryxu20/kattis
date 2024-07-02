#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    int low = 0;
    int high = 0;
    for (int i = 0; i < 22; i++) {
        if (n & (1 << i)) {
            low = i;
            break;
        }
    }

    for (int i = 21; i >= 0; i--) {
        if (n & (1 << i)) {
            high = i;
            break;
        }
    }

    if (high == low) {
        cout << n << " " << 0 << endl;
        return 0;
    }

    int b = high - low + 1;
    while(__builtin_popcount(n) != 1) n++;

    cout << n << " " << b << endl;
}