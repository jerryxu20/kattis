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

ll d2(const pl &a, const pl &b) {
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;

    return dx * dx + dy * dy;
}

int solve(int tt) {
    ll r, c, d, n;
    cin >> r >> c >> d >> n;

    vpl arr(n);
    for (auto &[a, b]: arr) {
        cin >> a >> b;
        a--; b--;
    }

    sort(all(arr), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    ll prev = 0;

    // check if there is an open row
    for (auto &[_, y]: arr) {
        if (y - d > prev) {
            cout << 0 << nl;
            return 0;
        }
        prev = y + d + 1;
    }

    if (prev + d < c - 1) {
        cout << 0 << nl;
        return 0;
    }

    // if there's some height that's not covered then its zero
    vector<vpl> events(c);
    set<pl> taken;

    for (auto &[x, y]: arr) {
        taken.insert(mp(x, y));
        for (ll yy = y - d; yy <= y + d; yy++) {
            if (yy < 0 || yy >= c) continue;

            // find when I enter the range on left
            // find when I exit the range on right

            // (yy - y)^2 + (xx - x)^2 <= d^2
            ll dy = yy - y;
            ll dx = sqrt(d * d - (dy * dy));

            // x - lx = dx
            ll lx = x - dx;
            ll rx = x + dx + 1;
            
            // assert(d2(mp(lx, yy), mp(x, y)) <= d * d);
            // assert(d2(mp(rx, yy), mp(x, y)) > d * d);
            // assert(d2(mp(rx - 1, yy), mp(x, y)) <= d * d);

            lx = max(lx, (ll) 0);
            events[yy].pb({lx, 1});
            if(rx < r) {
                events[yy].pb({rx, -1});
            }
        }
    }

    int ans = n;
    rep(i, 0, c) {
        events[i].pb({r, 0});
        events[i].pb({0, 0});
        sort(all(events[i]));

        auto &e = events[i];
        int cur = e[0].second;
        rep(j, 1, sz(e)) {
            if (e[j].first != e[j - 1].first && !taken.count(mp(e[j - 1].first, i))) {
                ans = min(ans, cur);
            }
            cur += e[j].second;
        }
    }

    cout << ans << nl;

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