#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n > m) {
        cout << "Dr. Chaz needs " << abs(n - m) << " more piece";
        if (abs(n - m) > 1) {
            cout << "s";
        }
        cout << " of chicken!";
    } else {
        cout << "Dr. Chaz will have " << abs(n - m) << " piece";
        if (abs(n - m ) > 1) {
            cout << "s";
        }
        cout << " of chicken left over!";
    }
    return 0;
}