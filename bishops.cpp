#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    while (cin >> n) {
        if (n <= 2) {
            cout << n;
        } else {
            cout << n + n - 2;
        }
        cout << '\n';
    }
    return 0;
}