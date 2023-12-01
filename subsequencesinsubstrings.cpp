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
    string s, t; cin >> s >> t;

    int n = sz(s);
    vector<vector<int>> nxt;
    vector<int> last(26, -1);


    FORd(i, 0, n) {
        nxt.push_back(last);
        int idx = s[i] - 'a';
        last[idx] = i;
    }
    reverse(all(nxt));

    ll ans = 0;
    int prev = -1;
    rep(i, 0, n) {
        if (s[i] != t[0]) continue;
        int j = i, jj = 1;
        while(jj < sz(t)) {
            int idx = t[jj] - 'a';
            if (nxt[j][idx] == -1) break;
            j = nxt[j][idx];
            jj++;
        }
        // did not find a match
        if (jj != sz(t)) break;

        for (int ii = prev + 1; ii <= i; ii++) {
            ans += (n - j);
        }
        prev = i;
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