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
    int n; cin >> n;
    vi arr(n);
    trav(a, arr) cin >> a;

    vector<int> good(n);
    int mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= mx) {
            good[i]++;
        }
        mx = max(arr[i], mx);
    }

    int mn = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] <= mn) {
            good[i]++;
        }
        mn = min(arr[i], mn);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (good[i] == 2) {
            ans.pb(i);
        }
    }
    cout << ans.size() << " ";
    for (int i = 0; i < min(100, (int)ans.size()); i++) {
        cout << arr[ans[i]] << " ";
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