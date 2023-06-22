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
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const int MOD = 1000000007;
const char nl = '\n';
int solve(int tt) {
    int n;
    vi nums;
    vi parent;
    vi ans;
    while(cin >> n) {
        ans.clear();
        nums.resize(n);
        parent.assign(n, 0);
        trav(num, nums) cin >> num;
        vpi arr = {{INT_MIN, -1}};
        rep(i, 0, n) {
            pi el = mp(nums[i], i);
            int idx = upper_bound(all(arr), mp(nums[i], -1)) - arr.begin();
            if (idx >= sz(arr)) {
                arr.pb(el);
            } else arr[idx] = el;
            parent[i] = arr[idx - 1].second;
        }
        int idx = arr.back().second;
        while(idx != -1) {
            ans.pb(idx);
            idx = parent[idx];
        }
        reverse(all(ans));
        cout << sz(ans) << nl;
        trav(a, ans) {
            cout << a << " ";
        }
        cout << nl;
    }

    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // cin.exceptions(cin.failbit);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}