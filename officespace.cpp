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

vii cnt;
int fill(int a, int b, int c, int d, int inc) {
    int ans = 0;
    for (int i = a; i < c; i++) {
        for (int j = b; j < d; j++) {
            cnt[i][j] += inc;
            if (cnt[i][j] == 1) ans++;        
        }
    }
    return ans;
}

int n, m;

int solve(int tt) {
    cnt.assign(n, vi(m, 0));
    int N; cin >> N;
    vector<tuple<int, int, int, int>> coords;
    vs name;
    rep(i, 0, N) {
        int a, b, c, d;
        string s; cin >> s;
        cin >> a >> b >> c >> d;
        // a--; b--; c--; d--;
        name.pb(s);
        coords.pb({a, b, c, d});
    }

    for (auto &[i, j, ii, jj]: coords) {
        fill(i, j, ii, jj, 1);
    }

    int uncon = 0;
    int contest = n * m;
    trav(row, cnt) {
        uncon += count(all(row), 0);
        contest -= count(all(row), 1);
    }
    contest -= uncon;
    
    cout << "Total " << n * m << endl;
    cout << "Unallocated " << uncon << endl;
    cout << "Contested " << contest << endl;
    rep(i, 0, N) {
        auto [a, b, c, d] = coords[i];
        cout << name[i] << " " << fill(a, b, c, d, 0) << endl;
    }

    cout << endl;
    tt++;
    return 0;
}

int main() {
    int T = 1;
    while(cin >> n >> m) {
        solve(0);
    }
    T++;
    return 0;
}