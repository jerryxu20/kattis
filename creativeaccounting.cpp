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
const int MAXN = 3e4;

int pref[MAXN + 1];
int mn = INT_MAX;
int mx = INT_MIN;

int n, l, h;

void check(int idx, int x) {
    int prev = 0;
    int ans = 0;
    while(true) {
        int profit = pref[min(n, idx + 1)] - pref[prev];
        if (profit > 0) ans++;
        if (idx >= n - 1) break; 
        prev = idx + 1;

        idx += x;
    }

    mx = max(ans, mx);
    mn = min(ans, mn);

}


int solve(int tt) {
    
    // for a given length x, there are n/x chunks. there are also x starting points.
    // x * n/x = n
    // 1000 different xs so this is fine

    cin >> n >> l >> h;

    rep(i, 0, n) {
        int a; cin >> a;
        pref[i + 1] = pref[i] + a;
    }

    rep(x, l, h + 1) {
        // try all starting points
        rep(i, 0, x) {
            check(i, x);            
        }
    }

    assert(mn != INT_MAX && mx != INT_MIN);
    cout << mn << " " << mx << endl;


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