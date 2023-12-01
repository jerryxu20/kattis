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

typedef __uint128_t ull;
typedef uint64_t ul;

const ull X = 8675309;
const ull P = 9223372036854775783;
const ull inv = 8261199684264045559;

int val(char c) {
    return c - 'a' + 1;
}

vector<ull> rolling_hash(string &s) {
    ull base = X;
    vector<ull> ans(sz(s) + 1, 0);
    rep(i, 0, sz(s)) {
        ans[i + 1] = (val(s[i]) * base) % P;
        ans[i + 1] = (ans[i + 1] + ans[i]) % P;
        base *= X;
        base %= P;
    }
    return ans;
}

ull remove(vector<ull> &hash, int i) {
    ull pref = hash[i];
    ull suf = (hash.back() - hash[i + 1] + P) % P;
    suf *= inv;
    suf %= P;

    return (pref + suf + P) % P;
}

int solve(int tt) {
    int n; cin >> n;
    vs word(n);
    trav(s, word) cin >> s;
    
    unordered_set<ul> st;
    vector<vector<ull>> hash(n);
    rep(i, 0, n) {
        hash[i] = rolling_hash(word[i]);
        st.insert(hash[i].back());
    }

    vs ans;
    rep(i, 0, n) {
        rep(j, 0, sz(word[i])) {
            ull new_hash = remove(hash[i], j);
            if (st.count(new_hash)) {
                ans.pb(word[i]);
                break;
            }
        }
    }

    if (sz(ans) == 0) {
        cout << "NO TYPOS\n";
    }
    trav(s, ans) {
        cout << s << nl;
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