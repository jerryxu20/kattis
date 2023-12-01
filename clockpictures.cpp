#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<ll> vl;
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

const int MOD = 360000;
const char nl = '\n';
vi pi(const string& s) {
	vi p(sz(s));
	rep(i,1,sz(s)) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

bool match(const string& s, const string& pat) {
	vi p = pi(pat + '\0' + s), res;
	rep(i,sz(p)-sz(s),sz(p))
		if (p[i] == sz(pat)) return true;
	return false;
}

int choose(int delta) {
    return (delta + MOD) % MOD;
    int sign = delta / abs(delta);
    int cand = (360000 - abs(delta));
    if (cand < abs(delta)) return cand * sign;
    return delta;
}

int solve(int tt) {
    int n;
    cin >> n;

    vi a(n), b(n);
    trav(hand, a) cin >> hand;
    trav(hand, b) cin >> hand;

    sort(all(a));
    sort(all(b));

    vi delta_a, delta_b;
    for (int i = 0; i < n; i++) {
        int cur = i % n;
        int nxt = (i + 1) % n;
        delta_a.pb(choose(a[nxt] - a[cur]));
    }
    for (int i = 0; i < n; i++) {
        int cur = i % n;
        int nxt = (i + 1) % n;
        delta_a.pb(choose(a[nxt] - a[cur]));
        delta_b.pb(choose(b[nxt] - b[cur]));
    }


    string A, B;
    trav(hand, delta_a) {
        A.pb((char) hand + 1);
    }
    trav(hand, delta_b) {
        B.pb((char) hand + 1);
    }

    if (match(A, B)) {
        cout << "possible\n";
    } else {
        cout << "impossible\n";
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