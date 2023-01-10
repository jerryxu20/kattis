#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> order(n - 1);
    for (int i = 2; i < n + 1; i++) {
        int a;
        cin >> a;
        order[a] = i;
    }
    cout << 1 << ' ';
    for (int i: order) {
        cout << i << ' ';
    }
    return 0;
}