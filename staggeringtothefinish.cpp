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
const double PI = M_PI;
int N;
double  R, S, W, F, L1, L2;

double radius(int lane, bool rline = false) {
    double ans = R + lane * W;
    if (rline) {
        if (lane == 0) ans += L1;
        else ans += L2;
    }
    return ans;
}

double semi(int lane) {
    double r = radius(lane, true);
    return r * PI;
}

double total(int lane) {
    return 2 * S + 2 * semi(lane);
}


void race(int lane, double d) {
    double race = total(lane);
    while(d > race) {
        d -= race;
    }
    double rem = F + S/2;
    double x, y;
    double inner_radius = radius(lane);
    double r = radius(lane, true);
    // lower straight
    if (d <= rem) {
        x = F - d;
        y = -inner_radius;
    } else if (d <= rem + semi(lane)) {
        d -= rem;
        double theta = d/r;
        y = -inner_radius * cos(theta);
        x = -inner_radius * sin(theta) - S/2;
        // somewhere on semicircle
    } else if (d <= rem + semi(lane) + S) {
        d -= rem + semi(lane);
        x = -S/2 + d;
        y = inner_radius;
    } else if (d <= rem + 2 * semi(lane) + S) {
        d -= rem + semi(lane) + S;
        double theta = d/r;
        x = inner_radius * sin(theta) + S/2;
        y = inner_radius * cos(theta);
    } else {
        d -= rem + S  + 2 * semi(lane);
        x = S/2 - d;
        y = -inner_radius;
    }
    cout << x << ' ' << y << " ";
} 

int solve(int tt) {
    cin >> N >> R >> S >> W >> F >> L1 >> L2;
    double D;
    cout << setprecision(15) << fixed;
    while(cin >> D) {
        cout << D << " ";
        rep(i, 0, N) {
            race(i, D);
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