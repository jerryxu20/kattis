#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<ll, ll, ll> tii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef vector<string> vs;
typedef vector<tii> vtii;
#define pb push_back
#define mp make_pair

// vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int solve(int tcase) {
    int n, m, q, s;
    cin >> n >> m >> q >> s;
    if (n == 0) return 1;
    vector<tii> edges(m);
    for (auto &[a, b, c]: edges) cin >> a >> b >> c;
    vector<ll> dis(n, LLONG_MAX);
    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        for (auto &[a, b, c]: edges) {
            if (dis[a] == LLONG_MAX) continue;
            dis[b] = min(dis[a] + c, dis[b]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto &[a, b, c]: edges) {
            if (dis[a] == LLONG_MAX) continue;
            if (dis[a] == LLONG_MIN) dis[b] = LLONG_MIN;
            else if (dis[a] + c < dis[b]) dis[b] = LLONG_MIN;
        }
    }
    while(q--) {
        cin >> n;
        if (dis[n] == LLONG_MAX) cout << "Impossible\n";
        else if (dis[n] == LLONG_MIN) cout << "-Infinity\n";
        else cout << dis[n] << "\n";
    }
    cout << "\n";
    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    // cin >> testcase;
    // for (int i = 1; i <= testcase; i++) {
    //     solve(i);
    // }
    for (int i = 1; ; i++) {
        if (solve(i)) break;
    }
    testcase++;
    return 0;
}