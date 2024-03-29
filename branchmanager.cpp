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
vii adj;
int n, m;
int ans = 0;
vector<int> seen;
void dfs(int node, vi &people) {
    seen[node] = 1;
    while(sz(people) && (seen[people.back()] == 1)) {
        people.pop_back();
    }
    trav(nxt, adj[node]) {
        dfs(nxt, people);
        while(sz(people) && (seen[people.back()] == 1)) {
            people.pop_back();
        }
    }
    seen[node] = -1;
    return;
}

int solve(int tt) {
    cin >> n >> m;
    adj.resize(n);
    seen.resize(n);
    int a, b;
    rep(i, 1, n) {
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
    }

    trav(row, adj) {
        sort(all(row));
    }

    vi people(m);
    trav(p, people) {
        cin >> p;
        p--;
    }
    reverse(all(people));

    dfs(0, people);
    cout << m - sz(people) << nl;


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