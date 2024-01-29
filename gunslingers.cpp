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
const int MAXN = 10;
const double EPS = 1e-12;
int n;
vector<double> dp[1 << MAXN][MAXN];
double hit[MAXN];

vector<double> best(int, int);
vector<double> f(int, int);


vector<double> best(int bitmask, int idx) {
    // idx will hit, what is best?
    vector<double> ans(n, -1);
    rep(i, 0, n) {
        if (i == idx) continue;
        if ((bitmask & (1 << i)) == 0) continue;
        vector<double> cand = f(bitmask & ~(1 << i), (idx + 1) % n);
        if (cand[idx] > ans[idx] + EPS) swap(ans, cand);
    }
    return ans;
}

void add(vector<double> &a, const vector<double> &b, double c) {
    rep(i, 0, n) {
        a[i] += b[i] * c;
    }
}

vector<double> f(int bitmask, int idx) {
    if (sz(dp[bitmask][idx]) != 0) return dp[bitmask][idx];

    if ((bitmask & (1 << idx)) == 0) return f(bitmask, (idx + 1) % n);

    vi dudes;
    vector<double> ans(n);
    rep(i, idx, n) {
        if (bitmask & (1 << i)) dudes.pb(i);
    }
    rep(i, 0, idx) {
        if (bitmask & (1 << i)) dudes.pb(i);
    }

    if (sz(dudes) == 1) {
        assert(dudes[0] == idx);
        ans[idx] = 1;
        return ans;        
    }


    double all_miss = 1;
    trav(i, dudes) {
        all_miss *= (1-hit[i]);
    }

    double some_hit = 1 - all_miss;
    double prob = 1/some_hit;


    trav(dude, dudes) {
        // imagine this dude hits
        add(ans, best(bitmask, dude), prob * hit[dude]);
        prob *= (1 - hit[dude]);
    }

    dp[bitmask][idx] = ans;
    return ans;
}


int solve(int tt) {
    cin >> n;
    rep(i, 0, n) {
        cin >> hit[i];
    }


    vector<double> ans = f((1 << n) - 1, 0);
    cout << fixed << setprecision(25);
    trav(a, ans) {
        cout << a << endl;
    }


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