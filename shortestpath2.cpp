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
typedef vector<string> vs;
typedef vector<tii> vtii;

#define pb push_back
#define mp make_pair

// vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int solve(int tcase) {
    int n, m, q, s, a, b, t, p, c;
    cin >> n >> m >> q >> s;
    if (n == 0) return 1;
    viii adj(n);
    while(m--) {
        cin >> a >> b >> t >> p >> c;
        adj[a].pb({b, c, t, p});
    }
    priority_queue<pii, vpii, greater<pii>> pq;
    pq.push(mp(0, s));
    vi dis(n, INT_MAX);
    dis[s] = 0;
    while(sz(pq)) {
        auto [d, node] = pq.top();
        pq.pop();
        if (dis[node] < d) continue;
        for (auto &edge: adj[node]) {
            int nxt = edge[0];
            int cost = edge[1];
            t = edge[2];
            p = edge[3];
            if (p == 0 && d > t) continue;
            int avail = t;
            if (p != 0) {
                int time = max(0, (d - t + p - 1) / p);
                avail = t  + time * p;
            }
            // cout << d << " " << t << " " << p << " " << avail << endl;
            int dd = avail + cost;
            if (dd >= dis[nxt]) continue;
            dis[nxt] = dd;
            pq.push(mp(dd, nxt));
        }
    }
    while(q--) {
        cin >> a;
        if (dis[a] == INT_MAX) cout << "Impossible\n";
        else cout << dis[a] << "\n";
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