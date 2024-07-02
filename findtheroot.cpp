#include <bits/stdc++.h>
using namespace std;

int main() {
    int m; cin >> m;

    int n = 0;
    vector<int> arr(m);

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        n = max(n, arr[i]);
    }
    n++;

    for (int i = 0; i < m; i++) {
        if (arr[i] * 2 + 1 == n) {
            cout << "yes\n";
            return 0;
        }
    }
    cout << "no\n";
}