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
int n, m;

double dis(pair<double, double> a, pair<double, double> b) {
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

pair<double, double> check(double d, pair<double, double> &cur, pair<double, double> &nxt) {
    pair<double, double> dir = {nxt.first - cur.first, nxt.second - cur.second};
    double x = dis(cur, nxt);
    dir.first /= x;
    dir.second /= x;
    dir.first *= d;
    dir.second *= d;
    return {cur.first + dir.first, cur.second + dir.second};
}


const double EPS = 1e-9;

int solve(int tt) {
    cin >> n;
    vector<pair<double, double>> A(n);
    for (auto &[x, y]: A) cin >> x >> y;

    cin >> m;
    vector<pair<double, double>> B(m);
    for (auto &[x, y]: B) cin >> x >> y;

    int idx = 0;
    pair<double, double> cur1, cur2;
    cur1 = A[0];
    cur2 = B[0];
    double ans = 1e9;
    int j = 0, i = 0;
    while (j != m -1 && i != n - 1) {
        double d1 = dis(cur1, A[i + 1]);
        double d2 = dis(cur2, B[j + 1]);

        double high = min(d1, d2);
        double low = 0;
        while(abs(high - low) > EPS) {
            double m1 = (high - low)/3 + low;
            double m2 = 2 * (high - low)/3 + low; 

            double a = dis(check(m1, cur1, A[i + 1]), check(m1, cur2, B[j + 1]));
            double b = dis(check(m2, cur1, A[i + 1]), check(m2, cur2, B[j + 1]));
            ans = min({ans, a, b});
            if(a < b) {
                high = m2;
            } else {
                low = m1;
            }
        }
        if (d1 < d2) {
            i++;
            cur2 = check(min(d1, d2), cur2, B[j + 1]);
            cur1 = A[i];
        } else {
            j++;
            cur2 = B[j];
            cur1 = check(min(d1, d2), cur1, A[i + 1]);
        }
    }

    cout << fixed << setprecision(20) << ans << endl;
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