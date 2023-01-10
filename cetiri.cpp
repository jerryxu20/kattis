#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> n(3);
    cin >> n[0] >> n[1] >> n[2];
    sort(n.begin(), n.end());
    int diff = min(n[1] - n[0], n[2] - n[1]);
    if (n[1] - n[0] != diff) {
        cout << n[0] + diff;
    } else if (n[2] - n[1] != diff) {
        cout << n[1] + diff;
    } else {
        cout << n[2] + diff;
    }
    return 0;
}