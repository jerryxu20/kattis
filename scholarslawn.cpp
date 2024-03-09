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
const double EPS = 1e-7;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

typedef Point<double> P;
double segDist(P& s, P& e, P& p) {
	if (s==e) return (p-s).dist();
	auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	// Checks if intersection is single non-endpoint point.
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
		return {(a * ob - b * oa) / (ob - oa)};
	set<P> s;
	if (onSegment(c, d, a)) s.insert(a);
	if (onSegment(c, d, b)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	return {all(s)};
}

typedef Point<double> P;

int solve(int tt) {
    int n; cin >> n;


    vector<pair<P, P>> lines(n);
    for (auto &[a, b]: lines) { 
        cin >> a.x >> a.y >> b.x >> b.y;
    }

    P bully;
    double ss, vbully;
    cin >> bully.x >> bully.y >> vbully;

    double vnerd;
    P s, t;
    cin >> s.x >> s.y >> t.x >> t.y;
    cin >> vnerd;

    // each relevant point can be described by the intersection of two lines. 
    // point x is lines (a, b). 

    // for (a, x), consider moving to this point
    // for (x, b), consider moving to this point

    // each node has 1000 edges
    // there are 500^2 nodes
    int BULLY = n + 1;
    int NERD = n;
    
    vector<vector<P>> inter(n + 2, vector<P>(n + 2, P(1e10, 1e10)));    
    vector<vector<double>> arrive(n + 2, vector<double>(n + 2, -1));

    typedef tuple<double, int, int> entry;
    PQG<entry> pq;
    
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (i == j) continue;
            vector<P> res = segInter(lines[i].first, lines[i].second, lines[j].first, lines[j].second);
            assert(sz(res) != 2);
            if (sz(res) == 0) continue;

            P pt = res[0];
            inter[i][j] = pt;
        }
    }

    rep(i, 0, n) {
        if (segDist(lines[i].first, lines[i].second, bully) < EPS) {
            inter[i][BULLY] = bully;
            pq.push({0, i, BULLY});
            arrive[i][BULLY] = 0; 
        }
    }

    // find intersection of scholar with other lines
    vector<double> nerd_time(n);
    rep(i, 0, n) {
        vector<P> res = segInter(lines[i].first, lines[i].second, s, t);
        assert(sz(res) != 2);
        if (sz(res) == 0) continue;

        P pt = res[0];

        inter[i][NERD] = pt;
        // v = d/t
        // t = d/v
        
        nerd_time[i] = (pt - s).dist()/vnerd;
    }

    while(sz(pq)) {
        auto [dis, i, j] = pq.top();
        pq.pop();
        if (dis > arrive[i][j] + EPS) continue;
        if (j == NERD) continue;

        // consider [i, a], where a is some other line
        for (int a = 0; a < n + 2; a++) {
            auto [ii, jj] = minmax(a, i);
            if (inter[ii][jj].x > 1e9) continue;
            P pt = inter[ii][jj];

            double ndis = dis + (pt - inter[i][j]).dist()/vbully; 
            if (arrive[ii][jj] < 0 || arrive[ii][jj] > ndis) {
                arrive[ii][jj] = ndis;
                pq.push({ndis, ii, jj});
            }
        }

        for (int a = 0; a < n + 2; a++) {
            auto [ii, jj] = minmax(a, j);
            if (inter[ii][jj].x > 1e9) continue;
            P pt = inter[ii][jj];

            double ndis = dis + (pt - inter[i][j]).dist()/vbully; 
            if (arrive[ii][jj] < 0 || arrive[ii][jj] > ndis) {
                arrive[ii][jj] = ndis;
                pq.push({ndis, ii, jj});
            }
        }
    }

    double ans = -1;
    bool pos = false;

    rep(i, 0, n) {
        if (arrive[i][NERD] < 0) continue;
        if (nerd_time[i] + EPS < arrive[i][NERD]) continue;

        if (ans < 0) ans = nerd_time[i];
        ans = min(ans, nerd_time[i]);
        pos = true;
    }

    if (!pos) {
        cout << "Impossible" << nl;
        return 0;
    }

    cout << setprecision(15) << fixed << ans << endl;

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