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
    ll n, m, a;
    cin >> n >> m >> a;
    if (a % n == 0 || a % m == 0) {
        cout << 1 << nl;
        return 0;
    }

    // select some num
    for (ll i = 1; i * i <= a; i++) {
        if (a % i == 0 && min(i, a/i) <= min(n, m) && max(i, a/i) <= max(n, m)) {
            cout << 2 << nl;
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        // how many rows we are taking
        ll block = i * m;
        ll rem = a - block;
        if (rem < 0) break;

        int rem_row = n - i;
        if (rem % rem_row == 0) {
            cout << 2 << nl;
            return 0;
        }   
    }

    for (int j = 1; j <= m; j++) {
        ll block = j * n;
        ll rem = a - block;
        if (rem < 0) break;

        int rem_col = m - j;
        if (rem % rem_col == 0) {
            cout << 2 << nl;
            return 0;
        }
    }
    

    if (a <= max(n, m)) {
        cout << 2 << nl;
        return 0;
    }

    if (a >= n * m - max(n, m)) {
        cout << 2 << nl;
        return 0;
    }

    /*
    
    4 x 5 -> 20 - 5, 15

    3 x 5
    
    */

    cout << 3 << nl;

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