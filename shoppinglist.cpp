#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    // what belongs to every list
    map<string, int> cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s;
            if (cnt[s] != i) continue;
            cnt[s]++;
        }
    }
    vector<string> ans;
    for (auto &[item, freq]: cnt) {
        if (freq == n) {
            ans.pb(item);
        }
    }
    cout << sz(ans) << endl;
    for (auto &a: ans) {
        cout << a << endl;
    }
    return 0;
}