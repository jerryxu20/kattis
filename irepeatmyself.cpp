#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair


int main() {
    // what is the length of the shortest pattern in the string
    // 200 characters
    // vector<vector<map<char, int>>> nxt(1);
    // vector<bool> is_terminal(1, false);
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    while (t--) {
        getline(cin, s);
        int n = sz(s);
        int ans = n;
        for (int len = 1; len < n ; len++) {
            bool good = true;
            for (int j = 0; j < n; j++) {
                if (s[j] != s[j % len]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                ans = len;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}