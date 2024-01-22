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

vi subs(vi &arr, int low, int high) {
    int m = high - low + 1;
    vi ans;
    rep(bitmask, 0, (1 << m)) {
        int sm = 0;
        rep(i, 0, m) {
            if (bitmask & (1 << i)) {
                sm += arr[low + i];
            }
        }
        ans.pb(sm);
    }
    sort(all(ans));
    return ans;
}


int solve(int tt) {
    int n; cin >> n;

    vi arr(n);
    trav(a, arr) cin >> a;

    vi left = subs(arr, 0, n/2 - 1);
    vi right = subs(arr, n/2, n - 1);

    int idx = sz(right) - 1;
    ll sm = right.back();
    ll ans = 0;
    ll cnt = 1;
    trav(x, left) {
        while(idx > 0 && x + right[idx - 1] >= 200) {
            idx--;
            cnt++;
            sm += right[idx];
        }

        if (right[idx] + x >= 200) {
            ans += sm + cnt * x;
        }
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