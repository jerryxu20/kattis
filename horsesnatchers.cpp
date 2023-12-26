#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<bool> vb;
typedef tuple<int,int,int> ti;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vi> vii;
typedef vector<vii> viii;

template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, a, b) for (int i=a; i<(b); i++)
#define FOR(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(x,A) for (auto& x : A)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ins insert

const int MOD = 1000000007;
const char nl = '\n';

int n, k, m, t, w;
vector<vpi> adj;
vi bad;

vi dijk(int s, bool snatch) {
    PQG<pi> pq;
    pq.push({0, s});

    vi dis(n, INT_MAX);
    dis[s] = 0;

    while(sz(pq)) {
        auto [d, node] = pq.top();
        pq.pop();
        if (dis[node] != d) continue;
        if (snatch && bad[node]) continue;
        
        for (auto &[nxt, c]: adj[node]) {
            int cost = d + c;
            if (cost >= dis[nxt]) continue;
            dis[nxt] = cost;
            pq.push({cost, nxt});
        }
    }

    return dis;
}

int solve(int tt) {
    cin >> n >> k >> m >> t >> w;
    adj.resize(n);
    bad.resize(n);

    int a, b, c;
    rep(_, 0, k) {
        cin >> a; a--;
        bad[a] = 1;
    }
    while(m--) {
        cin >> a >> b >> c;
        a--; b--;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }

    vi walk = dijk(n - 1, false);
    vi horse = dijk(0, true);

    if (walk[0] <= t * w) {
        cout << "No horse needed!\n";
        return 0;
    }

    double ans = 1e9;

    rep(i, 0, n) {
        // horse from 0 to i, then walk from i to n - 1
        if (walk[i] == INT_MAX || horse[i] == INT_MAX) continue;
        double time = t - (double)walk[i]/w;
        double speed = horse[i]/time;
        if (speed <= 0) continue;
        ans = min(ans, speed);
    }

    if (ans == 1e9) {
        cout << "Impossible\n";
        return 0;
    }

    cout << setprecision(20) << ans << endl;
    
    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}