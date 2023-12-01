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

int solve(int tt) {
    int n, m, l, s;
    cin >> n >> m >> l >> s;

    set<int> seen;
    vector<vpi> adj(n);
    
    int a, b, w;
    while(s--) {
        cin >> a;
        a--;
        seen.insert(a);
    }

    while(m--) {
        cin >> a >> b >> w;
        w += l;

        a--; b--;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }

    PQG<pi> pq;
    for (auto &node: seen) {
        for (auto &[nxt, cost]: adj[node]) {
            if (seen.count(nxt)) continue;
            pq.push(mp(cost, nxt));
        }
    }

    ll ans = 0;
    while(sz(pq)) {
        auto [cost, node] = pq.top();
        pq.pop();
        if (seen.count(node)) continue;

        ans += cost;
        seen.insert(node);
        for (auto &[nxt, cost]: adj[node]) {
            if (seen.count(nxt)) continue;
            pq.push(mp(cost, nxt));
        }
    }
    cout << ans << endl;
    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}