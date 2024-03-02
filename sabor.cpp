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
    set<pair<int, int>> edges;
    rep(_, 0, 5) {
        int m; cin >> m;
        while(m--) {
            int a, b;
            cin >> a >> b;

            pi e = minmax(a, b);
            if (edges.count(e)) continue;

            edges.insert(e);

            a--; b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }
    }

    vi color(n), cnt(n);
    queue<int> q;
    rep(i, 0, n) { 
        cnt[i] = sz(adj[i]);

        if (cnt[i] > 2) {
            q.push(i);
        }
    }

    while(sz(q)) {
        auto node = q.front();
        q.pop();
        if (cnt[node] <= 2) continue;

        // switch my color
        color[node] ^= 1;
        cnt[node] = 0;
        trav(nxt, adj[node]) {
            if (color[nxt] == color[node]) {
                cnt[nxt]++;
                cnt[node]++;
            }

            if (color[nxt] != color[node]) cnt[nxt]--;    

            if (cnt[nxt] == 3) {
                q.push(nxt);
            }
        }
    }

    rep(i, 0, n) {        
        if (color[i] == 0) {
            cout << 'B';
        } else {
            cout << 'A';
        }
    }
    cout << endl;


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