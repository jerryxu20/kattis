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
    ll n, r; cin >> n >> r;
    vl pts(n);
    trav(p, pts) cin >> p;
    sort(all(pts));



    vl ans;
    while(sz(pts)) {
        ll low = 0;
        ll mx = 0;
        ll choice = -1;
        rep(i, 0, sz(pts)) {
            while(pts[i] - pts[low] > 2 * r) {
                low++;
            }
            // pts[low] is the right end point
            if (i - low + 1 > mx) {
                choice = pts[i] - r;
                mx = i - low + 1;
            }
        }
        ans.pb(choice);
        vl npts;
        rep(i, 0, sz(pts)) {
            if (pts[i] < choice - r || pts[i] > choice + r) npts.pb(pts[i]);
        }
        pts = npts;
    }
    cout << sz(ans) << nl;
    trav(a, ans) {
        cout << a << ' ';
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