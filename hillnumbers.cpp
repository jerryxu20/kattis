#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> arr;

ll dp[20][10][2][2];

ll f(int idx, int prev, int fall, int less) {
    if (idx == (int)arr.size()) return less == 0;

    ll &ans = dp[idx][prev][fall][less];
    if (ans != -1) return ans;

    ans = 0;
    if (fall) {
        for (int i = 0; i <= arr[idx]; i++) if (i <= prev) {
            ans += f(idx + 1, i, fall, less & (i == arr[idx]));
        }

        if (less == 0) {
            for (int i = arr[idx] + 1; i < 10; i++) if (i <= prev) {
                ans += f(idx + 1, i, fall, 0);
            }
        }
    } else {
        for (int i = 0; i <= arr[idx]; i++) {
            int nfall = i < prev;
            ans += f(idx + 1, i, nfall, less & (i == arr[idx]));
        }

        if (less == 0) {
            for (int i = arr[idx] + 1; i < 10; i++) {
                int nfall = i < prev;
                ans += f(idx + 1, i, nfall, 0);
            }
        }
    }

    return ans;
}


int main() {
    memset(dp, -1, sizeof(dp));
    string s; cin >> s;
    int fall = 0;
    for (int i = 1; i < (int)s.size(); i++) {
        if (fall && s[i] > s[i - 1]) {
            cout << -1 << endl;
            return 0;
        }

        if (s[i] < s[i - 1]) fall = 1;
    }

    for (char &c: s) arr.push_back(c - '0');
    // ans = DP - 1 (remove 0) + 1 (add s)
    cout << f(0, 0, 0, 1) << endl;
}