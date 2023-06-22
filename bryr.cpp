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
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const int MOD = 1000000007;
const char nl = '\n';

int solve(int tt) {
    int n, m, a, b, cost;
    cin >> n >> m;
    vector<vpi> adj(n);
    while(m--) {
        cin >> a >> b >> cost;
        a--; b--;
        adj[a].pb(mp(b, cost));
        adj[b].pb(mp(a, cost));
    }

    vi dis(n, INT_MAX);
    dis[0] = 0;
    PQG<pi> pq;
    pq.push(mp(0, 0));
    while(sz(pq)) {
        auto [d, node] = pq.top();
        // cout << d << " " << node << nl;
        pq.pop();
        if (d != dis[node]) continue;
        if (node == n - 1) {
            cout << d << nl;
            return 0;
        }
        for (auto &[nxt, cost]: adj[node]) {
            int distance = cost + d;
            if (distance >= dis[nxt]) continue;
            dis[nxt] = distance;
            pq.push({distance, nxt});
        }
    }

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