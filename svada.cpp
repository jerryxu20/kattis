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

ll TT, n, m;

bool check(vpl &monkey, ll time, ll target) {
    ll total = 0;
    for (auto &[a, b]: monkey) {
        if (time < a) continue;
        total += (time - a)/b + 1;
    }
    return total >= target;
}

ll monkey_time(vpl &monkey, ll coconuts) {
    ll low = 0;
    ll high = TT;

    ll ans = TT;

    while(low <= high) {
        ll mid = (low + high)/2;

        // mid was enough time
        if (check(monkey, mid, coconuts)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
int solve(int tt) {
    cin >> TT;

    cin >> n;
    vpl monkey_A(n);
    for (auto &[a, b]: monkey_A) cin >> a >> b;

    cin >> m;
    vpl monkey_B(m);
    for (auto &[a, b]: monkey_B) cin >> a >> b;

    ll low = 0;
    ll high = n * TT;

    while (low <= high) {
        ll mid = (low + high) / 2;

        ll T1 = monkey_time(monkey_A, mid);
        ll T2 = monkey_time(monkey_B, mid);

        if (T1 + T2 > TT) {
            high = mid - 1;
        } else if (T1 + T2 < TT) {
            low = mid + 1;
        } else {
            cout << T1 << nl;
            return 0;
        }
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