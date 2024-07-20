#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;

    int n; cin >> n;
    vector<string> arr(n);

    for (auto &x: arr) cin >> x;
    map<char, int> cnt;
    for (auto &x: arr) cnt[x[0]]++;

    for (auto &x: arr) {
        if (x[0] == s.back()) {
            int k = cnt[x.back()];
            if (x[0] == x.back()) k--;
            if (k == 0) {
                cout << x << "!\n";
                return 0;
            }
        }
    }
    for (auto &x: arr) {
        if (x[0] == s.back()) {
            cout << x << endl;
            return 0;
        }
    }

    cout << "?\n";
}