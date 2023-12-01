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

int ans = 0;
vector<vi> nxt(1, vi(26));
vector<int> cnt(0);
int N = 0;

void add(string &s, int i, int id) {
    int node = 0;
    int len = 0;
    for (; i < sz(s); i++) {
        int idx = s[i] - 'a'; 
        if (nxt[node][idx] == 0) {
            if (id != 1) return;
            nxt[node][idx] = ++N;
            cnt.pb(1);
            nxt.pb(vi(26));
        }
        node = nxt[node][idx];
        if (cnt[node] < id - 1) return;
        cnt[node] = id;
        ans = max(ans, ++len);
    }
    return;
}

void update(string &s, int id) {
    ans = 0;
    for (int i = 0; i < sz(s); i++) {
        add(s, i, id);
    }
    return;
}

int solve(int tt) {
    int n; cin >> n;
    string s;
    rep(i, 0, n) {
        cin >> s;
        update(s, i + 1);
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