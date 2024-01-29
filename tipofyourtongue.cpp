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

vii pref(1, vi(26)), suff(1, vi(26)), both(1, vi(26));
vi cnt_pref(1), cnt_suff(1), cnt_both(1);

void add_to_trie(const string &s, vii &nxt, vi &cnt) {
    int node = 0;
    for (char c: s) {
        int idx = c - 'a';
        if (nxt[node][idx] == 0) {
            nxt[node][idx] = sz(nxt);
            nxt.pb(vi(26));
            cnt.pb(0);
        }
        node = nxt[node][idx];
        cnt[node]++;
    }
    return;
}

string fuse(string a, string b, bool flip = true) {
    if (flip) reverse(all(b));

    string ans = "";
    rep(i, 0, sz(a)) {
        ans.pb(a[i]);
        ans.pb(b[i]);    
    }
    return ans;
}

void add(string &s) {
    add_to_trie(fuse(s, s), both, cnt_both);
    add_to_trie(s, pref, cnt_pref);
    reverse(all(s));
    add_to_trie(s, suff, cnt_suff);
}

int query(const string &s, vii &nxt, vi&cnt) {
    int node = 0;
    for (char c: s) {
        int idx = c - 'a';
        if (nxt[node][idx] == 0) return 0;
        node = nxt[node][idx];
    }
    return cnt[node];
}

int solve(int tt) {
    int n, q;
    cin >> n >> q;

    string s, a, b;
    while(n--) {
        cin >> s;
        add(s);
    }

    while(q--) {
        cin >> s >> a >> b;
        int ans = 0;
        if (s == "AND") {
            ans = query(fuse(a, b), both, cnt_both);
        } else if (s == "OR") {
            reverse(all(b));
            ans = query(a, pref, cnt_pref) + query(b, suff, cnt_suff) - query(fuse(a, b, false), both, cnt_both);
        } else {
            reverse(all(b));
            ans = query(a, pref, cnt_pref) + query(b, suff, cnt_suff) - 2 * query(fuse(a, b, false), both, cnt_both);
        }
        cout << ans << nl;
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