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
    int L, P;
    cin >> L >> P;
    int n = L + P;
    vi val(n);
    rep(i, 0, L) {
        cin >> val[i];
    }

    vii adj(n);
    int x, y;
    vector<pair<double, double>> odds(n);

    vi deg(n);
    for (int i = L; i < n; i++) {
        cin >> odds[i].first >> odds[i].second;
        cin >> x >> y;
        x--; y--;
        adj[i].pb(x);
        adj[i].pb(y);
        deg[x]++;
        deg[y]++;
    }

    vector<double> dp(n);
    vector<double> hit(n, 1);
    for (int i = 0; i < n; i++) {
        // this is a sink
        if (val[i] != 0) {
            dp[i] = val[i];
            continue;
        }
        // this can branch out
        auto [l, r] = odds[i];
        hit[i] = l * hit[adj[i][0]] + r * hit[adj[i][1]];
        dp[i] = l * dp[adj[i][0]] + r * dp[adj[i][1]];
    }

    double ans = 0;
    for (int i = 0; i < n; i++) {
        // this is a drop point
        if (deg[i] == 0) {
            ans = max(ans, dp[i]/hit[i]);            
        }
    }
    cout << setprecision(20) << fixed << ans << endl;

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