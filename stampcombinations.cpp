#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin >> n >> q;

    vector<int> arr(n);
    for (int &x: arr) cin >> x;

    int sm = accumulate(arr.begin(), arr.end(), 0);
    set<int> seen;
    while(q--) {
        int x; cin >> x;

        if (x == sm) {
            cout << "Yes\n";
            continue;
        }
        
        seen.clear();
        seen.insert(0);

        int cur = 0;
        int ans = 0;
        int targ = sm - x;
        for (int i = 0; i < n; i++) {
            cur += arr[i];
            int need = cur - targ;
            if (seen.count(need)) {
                ans = 1;
                break;
            }
            seen.insert(cur);
        }

        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        
    }


}