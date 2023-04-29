#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int, int, int> tii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

#define pb push_back
#define mp make_pair

// vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int solve(int tcase) {
    int n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << 0 << endl;
        return 0;
    }
    vpii time(n);
    for (auto &[a, b]: time) cin >> a >> b;
    sort(all(time));
    int ans = 0;
    priority_queue<int, vi, greater<int>> pq;
    for (auto &[a, b]: time) {
        pq.push(b);
        int mn = a - k;
        while(sz(pq) && pq.top() < mn) {
            pq.pop();
        }
        ans = max(ans, sz(pq));
    }
    cout << ans << endl;
    
    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    testcase++;
    return 0;
}