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
int n, d, s, t, mn, mx;
vd laces;
double tri(int a, int b) {
    int dx = s;
    int dy = abs(b - a) * d;
    return sqrt(dx * dx + dy * dy);
}

void calclen(vi &holes) {
    holes.pb(n - 1);
    vector<vd> options;
    double base = s +  (sz(holes)+1) * 2 * t;

    int prev = 0;
    trav(hole, holes) {

        // go across
        double diag = tri(prev, hole);
        
        // consider going vertical
        if (abs(hole - prev) == 1) {
            double vert = d;
            options.pb({2 * vert, 2 * diag});
        } else {
            base += 2 * diag;
        }
        prev = hole;
    }

    int c = sz(options);
    for (int i = 0; i < (1 << c); i++) {
        double choice = 0;
        for (int j = 0; j < c; j++) {
            if (i & (1 << j)) {
                choice += options[j][1];
            } else {
                choice += options[j][0];
            }
        }
        laces.pb(base + choice);
    }
    holes.pop_back();
    return;
}

int solve(int tt) {
    cin >> n >> d >> s >> t >> mn >> mx;
    mn *= 2;
    mx *= 2;

    int r = n - 2;
    for (int i = 0; i < (1 << r); i++) {
        vi holes;
        rep(j, 0, r) {
            if (i & (1 << j)) {
                holes.pb(j + 1);
            }
        }
        do {
            calclen(holes);
        } while(next_permutation(all(holes)));
    }

    int len;    
    while(cin >> len) {
        int ans = 0;
        trav(lace, laces) {
            double rem = len - lace;
            if (rem >= mn && rem <= mx) {
                ans++;
            }
        }
        cout << ans << endl;
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