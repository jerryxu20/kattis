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

struct Frac {
    ll top, bot;
    Frac(ll _top, ll _bot) {
        top = _top;
        bot = _bot;
        ll g = gcd(top ,bot);
        top /= g;
        bot /= g;
        return;
    }
    Frac operator-(Frac rhs) {
        // a/b - c/d
        return Frac(top * rhs.bot - rhs.top * bot, bot * rhs.bot);
    }
    Frac operator*(Frac rhs) {
        return Frac(top * rhs.top, bot * rhs.bot);
    }
    Frac operator*(ll rhs) {
        return Frac(top * rhs, bot);
    }
    bool operator<(Frac rhs) {
        return top * rhs.bot < rhs.top * bot;
    }
    bool operator==(Frac rhs) {
        return top == rhs.top && bot == rhs.bot;
    }
};

struct Point {
    ll x, y;
    Point(ll _x = 0, ll _y = 0) {
        x = _x;
        y = _y; 
    }
    Point operator-(Point rhs) {
        return Point(x - rhs.x, y - rhs.y);
    }
    ll d2() {
        return x * x + y * y;
    }
};

ll dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

int solve(int tt) {
    Point a, b;
    cin >> a.x >> a.y >> b.x >> b.y;

    Point s = b - a;

    int n; cin >> n;
    Point p;
    string name;
    vs ans;
    Frac best = Frac(INT_MAX, 1);
    while(n--) {
        cin >> name >> p.x >> p.y;
        Point v = p - a;
        Frac scale = Frac(dot(v, s), dot(s, s));
        Frac cand = Frac(v.d2(), 1ll) - scale * scale * s.d2();
        if (cand < best) {
            best = cand;
            ans = {};
        }
        if (best == cand) {
            ans.pb(name);
        }
    }

    trav(city, ans) {
        cout << city << " ";
    }
    cout << endl;

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