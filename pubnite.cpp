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

struct Point {
    double x, y;
    Point(double _x = 0, double _y = 0) {
        x = _x;
        y = _y;
        return;
    }
};

struct Line {
    ll slope;
    double inter;
    Line(double start, ll speed) {
        inter = start;
        slope = -speed;
        return;
    }

    double at(double X) {
        return inter + slope * X;
    }

    double solve(double Y) {
        return (Y - inter)/slope;
    }
    
};

bool intersect(Line &a, Line &b, Point &p) {
    if (a.slope == b.slope) return false;
    double X = (b.inter - a.inter)/(a.slope - b.slope);
    double Y = a.at(X);
    p.x = X;
    p.y = Y;
    return true;
}



int solve(int tt) {
    ll x, y, s, ri, rf;
    cout << setprecision(15);
    cin >> x >> y >> s >> ri >> rf;

    Line circle = Line(ri, s);


    ll xp, yp, sp;
    cin >> xp >> yp >> sp;

    ll dx = x - xp;
    ll dy = y - yp;
    double dis = sqrt(dx*dx + dy*dy);

    Line player = Line(dis, sp);
    double stop_time = circle.solve(rf);
    double req_time = player.solve(rf);
    
    if (dis <= rf || (dis <= ri && sp >= s)) {
        cout << 0 << nl;
        return 0;
    }

    if (dis >= ri && sp <= s) {
        cout << req_time << nl;
        return 0;
    }

    Point p;
    bool res = intersect(circle, player, p);
    assert(res);

    double meet_time = p.x;
    double rad = p.y;

    if (dis > ri) {
        cout << min(meet_time, req_time) << nl;
        return 0;
    }

    if (rad <= rf) {
        cout << 0 << nl;
        return 0;
    }

    cout << req_time - meet_time << nl;

    
    
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