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
const int MAXN = 100000;
constexpr int n = MAXN - MAXN/3 + 1;
int idx[MAXN + 1];

void guess(int x) {
    if (idx[x] != -1) return;

    if (x % 3 == 1) {
        idx[x + 1] = idx[x - 1] + 1;
    }

    if (x % 3 == 2) {
        idx[x - 1] = idx[x - 2] + 1;
    }
}

int solve(int tt) {
    memset(idx, -1, sizeof(idx));

    // [0, x1, 3] [3, x2, 6], [6, x3, 9]
    // fix all multiples of 3 to have 1 unknown
    // every unknown has two choices, so we can always force it to miss

    idx[0] = 0;
    idx[MAXN] = n - 1;
    for (int i = 3; i < MAXN; i += 3) {
        idx[i] = idx[i - 3] + 2;
    }

    cout << n << endl;

    while(true) {
        int x; cin >> x;
        if (x == -1) break;
        if (idx[x] != -1) {
            cout << idx[x] + 1 << endl;
            continue;
        }

        cout << -1 << endl;
        guess(x);
    }

    int cnt = 0;
    rep(i, 0, MAXN + 1) {
        guess(i);
        if (idx[i] != -1) {
            cout << i << nl;
        }
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