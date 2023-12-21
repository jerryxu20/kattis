#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// typedef long double ld;
// typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<double, double> pd;

typedef vector<int> vi;
// typedef vector<ld> vld;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
// typedef vector<cd> vcd;
typedef vector<bool> vb;
typedef tuple<int,int,int> ti;
typedef vector<string> vs;
// typedef vector<double> vd;
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
int n, k;
vector<double> odds;
double cross(pd &a, pd &b) {
    return a.first * b.second - b.first * a.second;
}

// Compute (x chose k - 2)/(k choose n) for k - 2 <= x <= n - 2
// Compute in parts to keep result reasonable at all stages (not massive and not tiny)
void comp_odds() {
    // Start with result for x = n - 2
    double res = k * (k - 1);
    for (int i = n; i > n - 2; i--) {
        res *= 1.0/(double)i;
    }


    odds[n - 2] = res;
    for (int i = n - 3; i >= 0; i--) {
        int bot = i - k + 2;
        if (bot < 0) break;
        
        double factor = (double)(i + 1)/(bot + 1);
        odds[i] = odds[i + 1] / factor;
    }
    return;
}

double prob(int x) {
    if (x < k - 2) return 0;
    return odds[x];
}

int solve(int tt) {
    cin >> n >> k;
    odds.resize(n);
    comp_odds();
    vector<pd> pts(n);
    for (auto &[x, y]: pts) {
        cin >> x >> y;
    }

    double ans = 0;
    for (int i = 0; i < n; i++) {
        // right is number of vertices between i and j going CW 
        // left is number of vertices between i and j going CCW
        int right = 0;
        int left = n - 2;
        // resulting polygon will have edges in CCW order
        for (int j = i + 1; j < n; j++) {
            
            
            double contribution = cross(pts[i], pts[j])/2.0;

            // When other points are from the right, the correct edge is i->j
            ans += prob(right) * contribution;

            // When other points are from the left, the correct edge is j->i
            ans += prob(left) * -contribution;

            left--;            
            right++;
        }
    }
    cout << setprecision(20) << ans << nl;


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