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
int n;

int dis(int x) {
    return min(x, n - x);
}

vi rot(string &a, string &b) {
    vi ans(n, 1);
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (a[(i + j) % n] == b[j]) {
                ans[i] = 0;
            }
        }
    }
    return ans;
}


int solve(int tt) {
    string a, b, c; 

    cin >> a >> b >> c;
    n = sz(a);

    vi validab = rot(a, b);
    vi validac = rot(a, c);
    vi validbc = rot(b, c);

    int ans = INT_MAX;

    rep(i, 0, n) {
        rep(j, 0, n) {
            int dab = i;
            int dac = j;
            int dbc = dac - dab;
            if (dbc < 0) dbc += n;

            if (validab[dab] && validac[dac] && validbc[dbc]) {
                // fix a
                ans = min(ans, dis(dab) + dis(dac));

                // fix b
                ans = min(ans, dis(dab) + dis(dbc));

                // fix c
                ans = min(ans, dis(dac) + dis(dbc));
            }
        }
    }

    if (ans == INT_MAX) {
        cout << -1 << nl;
        return 0;
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