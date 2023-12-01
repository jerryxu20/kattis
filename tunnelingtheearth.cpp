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

const double r = 6371009;

double sphericalDistance(double f1, double t1, double f2, double t2, double radius) {
	double dx = sin(t2)*cos(f2) - sin(t1)*cos(f1);
	double dy = sin(t2)*sin(f2) - sin(t1)*sin(f1);
	double dz = cos(t2) - cos(t1);
	double d = sqrt(dx*dx + dy*dy + dz*dz);
	return radius*2*asin(d/2);
}

tuple<double, double, double> coord(double theta, double phi) {
    double x = r * sin(theta) * cos(phi);
    double y = r * sin(theta) * sin(phi);
    double z = r * cos(theta);
    return {x, y, z};
}

double dis(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    double dz = z1 - z2;

    return sqrt(dx * dx + dy * dy + dz * dz);
}

int solve(int tt) {
    double lat1, long1, lat2, long2;
    cin >> lat1 >> long1 >> lat2 >> long2;
    
    if (long2 < 0) {
        long2 += 360;
    }
    if (long1 < 0) {
        long1 += 360;
    }
    lat1 -= 90;
    lat2 -= 90;
    
    long1 *= M_PI/180.0;
    long2 *= M_PI/180.0;
    lat1 *= M_PI/180.0;
    lat2 *= M_PI/180.0;

    auto [x1, y1, z1] = coord(lat1, long1);
    auto [x2, y2, z2] = coord(lat2, long2);
    cout << fixed << sphericalDistance(long1, lat1, long2, lat2, r) - dis( x1, y1, z1, x2, y2, z2) << endl;


    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}