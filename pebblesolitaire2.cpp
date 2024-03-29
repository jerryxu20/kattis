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

int ans[1 << 23];

int dfs(int state) {
    if (ans[state] != -1) return ans[state];
    int mn = __builtin_popcount(state);

    rep(i, 1, 22) {
        // I am being jumped over
        int cur = state & (1 << i);
        int prev = state & (1 << (i - 1));
        int nxt = state & (1 << (i + 1));

        if (cur && prev && !nxt) {
            int nstate = state;
            nstate -= cur;
            nstate -= prev;
            nstate += (1 << (i + 1));
            mn = min(mn, dfs(nstate));
        }

        if (cur && nxt && !prev) {
            int nstate = state;
            nstate -= cur;
            nstate -= nxt;
            nstate += (1 << (i - 1));
            mn = min(mn, dfs(nstate));
        }

    }
    ans[state] = mn;
    return mn;

}


int solve(int tt) {
    string s; cin >> s;    

    int x = 0;
    rep(i, 0, sz(s)) {
        if (s[i] == 'o') {
            x += (1 << i);
        }
    }

    cout << dfs(x) << nl;


    tt++;
    return 0;
}

int main() {
    memset(ans, -1, sizeof(ans));
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}