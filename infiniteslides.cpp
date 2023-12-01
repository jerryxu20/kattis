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

const double EPS = 1e-2;

tuple<double, double, double> calc(double time, int vert) {
    double z = vert * time;
    double theta = time;

    double x = cos(theta);
    double y = sin(theta);

    if (vert == 2) {
        x += 1;
    }
    return {x, y, z};
}

int solve(int tt) {
    double w; cin >> w;


    double ans = 1e9;
    double t = w;
    while(w < t + 1000) {
        auto [x, y, z] = calc(w, 1);
        auto [xx, yy, zz] = calc(w - t, 2);
        double dx = x - xx;
        double dy = y - yy;
        double dz = z - zz;
        double dis = sqrt(dx * dx + dy * dy + dz * dz);
        ans = min(ans, dis);
        w += EPS;
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