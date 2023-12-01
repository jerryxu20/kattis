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
const double EPS = 1e-9;

vector<pair<double, double>> coords;
double dis(double y, double x) {
    double ans = 0;
    for (auto &[xx, yy]: coords) {
        double dy = y-yy;
        double dx = x-xx;
        ans += sqrt(dx*dx+dy*dy);
    }
    return ans;
}

double best(double y) {
    double high = 10000;
    double low = 0;
    double ans = 1e10;
    while(abs(high - low) > EPS) {
        double m1 = low + (high - low) / 3.0;
        double m2 = high - (high - low) / 3.0;
        double a = dis(y, m1);
        double b = dis(y, m2);
        if (a < b) {
            high = m2;
        } else {
            low = m1;
        }
        ans = min({ans, a, b});
    }
    return ans;
}

int solve(int tt) {
    int n;
    cin >> n;

    coords.resize(n);
    for (auto &[x, y]: coords) cin >> x >> y;

    double high = 10000;
    double low = 0;
    double ans = 1e10;
    while(abs(high - low) > EPS) {
        double m1 = low + (high - low) / 3.0;
        double m2 = high - (high - low) / 3.0;
        double a = best(m1);
        double b = best(m2);
        if (a < b) {
            high = m2;
        } else {
            low = m1;
        }
        ans = min({ans, a, b});
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