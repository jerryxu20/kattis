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
    map<int, int> freq;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            freq[i + j]++;
        }
    }
    map<int, vector<int>> ans;
    for (auto [a, weight]: freq) {
        ans[weight].pb(a);
    }
    auto it = ans.rbegin();
    for (auto &num: it->second) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}