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
    ll n, m, k; cin >> n >> m >> k;

    vl arr(n), paid(n);
    for (auto &x: arr) cin >> x;


    vl stack;

    ll cnt = 0;
    rep(i, 0, n) {
        stack.push_back(i);
        if (i >= m) {
            cnt -= paid[i - m];
        }

        while(cnt < k && sz(stack)) {
            int j = stack.back();
            ll cap = min(k - cnt, arr[j]);
            arr[j] -= cap;
            if (arr[j] == 0) stack.pop_back();

            paid[j] += cap;
            cnt += cap;
        }
    }

    reverse(all(paid));
    reverse(all(arr));
    stack.clear();
    
    cnt = 0;
    rep(i, 0, n) {
        stack.push_back(i);
        cnt += paid[i];
        if (i >= m) {
            cnt -= paid[i - m];
        }

        while(cnt < k && sz(stack)) {
            int j = stack.back();
            ll cap = min(k - cnt, arr[j]);
            arr[j] -= cap;
            if (arr[j] == 0) stack.pop_back();

            paid[j] += cap;
            cnt += cap;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += paid[i];
    }
    cout << ans << endl;

    

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