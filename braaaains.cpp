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

vl dijk(vl &box) {
    ll n = box[0];
    vl ans(n, LLONG_MAX);
    ans[0] = 0;

    vector<vpi> adj(n);
    rep(i, 0, n) {
        trav(b, box) {
            int nxt = (i + b) % n;
            adj[i].pb({nxt, b});
        }
    }

    PQG<pl> pq;
    pq.push({0, 0});

    while(sz(pq)) {
        auto [d, node] = pq.top();
        pq.pop();
        if (ans[node] != d) continue;

        for (auto &[nxt, weight]: adj[node]) {
            ll cand = d + weight;
            if (ans[nxt] <= cand) continue;
            ans[nxt] = cand;
            pq.push({cand, nxt});
        }
    }

    return ans;




}


int solve(int tt) {
    int n, m;
    cin >> n >> m;

    vl box(n);
    trav(a, box) cin >> a;

    vl dis = dijk(box);

    ll s = box[0];
    while(m--) {
        ll x; cin >> x;
        if (dis[x % s] <= x)  {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
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