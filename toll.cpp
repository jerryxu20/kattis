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
const int B = 150;
int k, n, m, q;
vector<vpi> adj;

int calc(vi &to_a, int a, int b) {

    
    vi dp(k, INT_MAX);
    dp[b % k] = 0;

    FORd(i, a/k, b/k) {
        vi dis(k, INT_MAX);
        rep(node, i*k, (i + 1) * k) {
            for (auto &[nxt, cost]: adj[node]) {
                if (dp[nxt % k] == INT_MAX) continue;
                dis[node % k] = min(dis[node % k], dp[nxt % k] + cost);
            }
        }

        swap(dp, dis);
    }

    int ans = INT_MAX;
    rep(i, 0, k) {
        if (to_a[i] == INT_MAX || dp[i] == INT_MAX) continue;
        ans = min(ans, to_a[i] + dp[i]);
    }
    if (ans == INT_MAX) return -1;
    return ans;
}


int traverse(int a, int b, vii &next) {
    int target_bucket = b/k/B;
    int current_bucket = a/k/B;
    int current_layer = a/k;

    vector<int> dis(k, INT_MAX);
    dis[a % k] = 0;
    while(current_bucket != target_bucket) {
        vi new_dis(k, INT_MAX);

        rep(i, 0, k) {
            if (dis[i] == INT_MAX) continue;
            int ii = current_layer * k + i;
            vi jump = next[ii];

            rep(j, 0, k) {
                if (jump[j] == INT_MAX) continue;
                new_dis[j] = min(new_dis[j], dis[i] + jump[j]); 
            }
        }

        current_bucket++;
        current_layer = current_bucket * B;
        swap(dis, new_dis);
    }

    // now we are in the same bucket
    return calc(dis, current_layer * k, b);
}

int solve(int tt) {
    cin >> k >> n >> m >> q;

    adj.resize(n);
    while(m--) {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].pb(mp(b, t));
    }

    // build the jump pointers

    // bext_bucket[i]: the cheapest way to reach the first layer of nodes in the next bucket
    // layer: nodes that have same i/k
    // bucket: layers with same layer/B

    vector<vi> next_bucket(n);

    FORd(i, 0, n) {
        vi dis(k, INT_MAX);
        for (auto &[nxt, cost]: adj[i]) {
            // these nodes are in the same bucket
            if (nxt/k/B == i/k/B) {
                auto &v = next_bucket[nxt];

                rep(j, 0, k) {
                    if (v[j] != INT_MAX) dis[j] = min(dis[j], v[j] + cost);
                }
            } else {
                int id = nxt % k;
                dis[id] = cost; 
            }
        }

        next_bucket[i] = dis;
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << traverse(a, b, next_bucket) << nl;
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