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
const int MAXK = 60;
const int MAXN = 500'000;

double weight[MAXN][MAXK];
int seen[MAXN], sat[MAXN];
vi adj[MAXN];
vi order;
double dp[MAXN][MAXK];

void dfs(int node) {
    seen[node] = 1;
    trav(nxt, adj[node]) {
        assert(seen[nxt] != 1);
        if (seen[nxt] == 0) dfs(nxt);
    }
    order.pb(node);
    seen[node] = 2;
    return;
}


int solve(int tt) {
    int n, m;
    cin >> n >> m;

    rep(i, 0, n) {
        cin >> sat[i];
    }

    rep(i, 0, n) {
        weight[i][0] = sat[i];
        rep(j, 1, MAXK) {
            weight[i][j] = weight[i][j - 1]/2.0;
        }
    }

    
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }

    rep(i, 0, n) {
        if (seen[i] == 0) dfs(i);
    }

    reverse(all(order));

    double ans = 0;
    trav(node, order) {
        rep(i, 0, MAXK) {
            trav(nxt, adj[node]) {
                dp[nxt][i] = max(dp[nxt][i], dp[node][i]);
            }

            // take node
            dp[node][i] += weight[node][i];
            ans = max(ans, dp[node][i]);
        
            if (i == MAXK - 1) continue;
            trav(nxt, adj[node]) {
                dp[nxt][i + 1] = max(dp[nxt][i + 1], dp[node][i]);
            }

            
        }
    }


    cout << setprecision(20) << fixed << ans << nl;

    



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