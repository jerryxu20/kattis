#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> mp(7);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (mp[a] > 0) {
            mp[a] = -1;
        } else if (mp[a] == 0) {
            mp[a] = i;
        }
    }
    int ans = 0;
    for (int i = 6; i > 0; i--) {
        if (mp[i] > 0) {
            cout << mp[i];
            return 0;
        }
    }
    cout << "none";
    return 0;
}