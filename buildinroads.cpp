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
const double EPS = 1e-9;
struct UF {
    vi rank, id;
    UF(int n) {
        rank.resize(n, 1);
        id.resize(n);
        iota(all(id), 0);
    }
    int find(int a) {
        if (a == id[a]) return a;
        id[a] = find(id[a]);
        return id[a];
    }

    bool join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[b] > rank[a]) swap(a, b);
        rank[a] += rank[b];
        id[b] = a;
        return true;
    }
};


vector<vi> edges;
vector<int> idx;
int n, m;

pl check(double x) {
    double score = 0;
    ll P = 0, G = 0;

    sort(all(idx), [&] (auto &a, auto &b) {
        return edges[a][2] - x*edges[a][3] < edges[b][2] - x*edges[b][3];
    });

    UF uf(n + 1);
    trav(i, idx) {
        vi &edge = edges[i];
        int a = edge[0];
        int b = edge[1];

        if (!uf.join(a, b)) continue;
        int p = edge[2];
        int g = edge[3];

        score += p - x * g;
        P += p;
        G += g;
    }

    if (score > 0) return {-1, -1};
    return {P, G};
}


int solve(int tt) {
    cin >> n >> m;
    edges.assign(m, vi(4));
    idx.resize(m);
    iota(all(idx), 0);

    trav(edge, edges) {
        trav(a, edge) cin >> a;
    }

    double high = 1e14;
    double low = 0;

    pl ans = {-1, -1};
    while(abs(high - low) > EPS) {
        double mid = (high + low)/2;
        pl cand = check(mid);
        if (cand.first == -1) {
            low = mid;
        } else {
            high = mid;
            ans = cand;
        }
    }

    assert(ans.first != -1);

    ll g = gcd(ans.first, ans.second);
    ans.first /= g;
    ans.second /= g;

    cout << ans.first << "/" << ans.second << endl;
    
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