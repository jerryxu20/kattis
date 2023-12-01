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
    int n; cin >> n;
    vii adj(n);
    int x;
    rep(i, 1, n) {
        cin >> x; x--;
        adj[i].pb(x);
    }
    vi mx(n), val(n);
    trav(m, mx) cin >> m;
    trav(v, val) cin >> v;

    vector<PQG<pi>> pq(n);

    FORd(i, 0, n) {
        pq[i].push({val[i],i});
        while(sz(pq[i]) > mx[i]) pq[i].pop();
        trav(nxt, adj[i]) {
            auto &a = pq[i];
            auto &b = pq[nxt];
            bool flipped = sz(a) > sz(b);
            if (flipped) swap(a, b);

            // a into b
            while(sz(a)) {
                b.push(a.top());
                a.pop();
            }
        }
    }

    ll ans = 0;
    vi res;
    while(sz(pq[0])) {
        ans += (ll) pq[0].top().first;
        res.pb(pq[0].top().second);
        pq[0].pop();
    }
    cout << ans << endl;
    cout << sz(res) << " ";
    sort(all(res));
    trav(r, res) {
        cout << r + 1 << ' ';
    }
    cout << nl;
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