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

struct UF {
    vi rank, id;
    vs shortest;

    UF (int n, vs &words) {
        rank.resize(n, 1);
        id.resize(n);
        shortest = words;

        iota(all(id), 0);
    }

    string replace(int a) {
        a = find(a);
        return shortest[a];
    }

    bool join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;

        if (rank[b] > rank[a]) swap(a, b);

        id[b] = a;
        rank[a] += rank[b];
        if (sz(shortest[b]) < sz(shortest[a])) {
            shortest[a] = shortest[b];
        }
        return true;
    }

    int find(int a) {
        if (id[a] == a) return a;
        id[a] = find(id[a]);
        return id[a];
    }
};

int solve(int tt) {
    int n, m;
    cin >> n >> m;
    vs essay(n);
    trav(s, essay) cin >> s;

    string a, b;
    map<string, int> id;
    int N = 0;

    vpi edges;    
    vs words;
    while(m--) {
        cin >> a >> b;
        if (!id.count(a)) {
            id[a] = N++;
            words.pb(a);
        }
        if (!id.count(b)) {
            id[b] = N++;
            words.pb(b);
        }
        edges.pb(mp(id[a], id[b]));
    }

    UF uf(N, words);
    for (auto &[a, b]: edges) {
        uf.join(a, b);
    }

    int ans = 0;
    trav(s, essay) {
        if (id.count(s)) {
            s = uf.replace(id[s]);
        }
        ans += sz(s);
    }
    cout << ans << nl;


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