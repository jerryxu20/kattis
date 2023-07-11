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
map<int, pi> coords;
vii delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
ll N = 30000;
int n = 100;
vb is_prime;

void sieve() {
    is_prime.assign(N, true);
    is_prime[0] = false;
    is_prime[1] = false;
    rep (i, 2, N) {
        if (is_prime[i]) {
            for (ll j = (ll)i * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return;
}

int val(int x, int y) {
    if (x == 0 && y == 0) return 1;
    int rank = max(abs(x), abs(y));
    int ans = 0;
    if (y > -x ) {
        int inner_rank = rank - 1;
        int xx = inner_rank;
        int yy = -inner_rank;
        ans += abs(x - xx) + abs(y - yy);
        if (x <= xx) ans += 2;
        ans += (inner_rank * 2 + 1) * (inner_rank * 2 + 1);
    } else {
        int xx = rank;
        int yy = -rank;
        ans -= abs(x - xx) + abs(y - yy);
        ans += (rank * 2 + 1) * (rank * 2 + 1);
    }
    return ans;
}


int solve(int tt) {
    int x, y;
    while(cin >> x >> y) {
        cout << "Case " << tt++ << ": ";
        if (x == y) {
            cout << 0 << nl;
            continue;
        }
        // if (x == 12 || y == 12 || x == 72 || y == 72) {
        //     cout << "impossible\n";
        //     continue;
        // }
        auto start = coords[x];
        auto end = coords[y];
        queue<pi> q;
        set<pi> seen;
        q.push(start);
        seen.insert(start);
        int ans = 0;
        bool found = false;
        while(sz(q)) {
            int s = sz(q);
            while(s--) {
                auto [i, j] = q.front();
                q.pop();
                trav(d, delta) {
                    int ii = i + d[0];
                    int jj = j + d[1];
                    if (abs(ii) > n || abs(jj) > n) continue;
                    if (is_prime[val(ii, jj)]) continue;
                    auto state = mp(ii, jj);
                    if (seen.count(state)) continue;
                    if (state == end) {
                        cout << ans + 1 << nl;
                        found = true;
                        break;
                    }
                    seen.insert(state);
                    q.push(state);
                }
                if (found) break;
            }
            if (found) break;
            ans++;
        }
        if (found == false) {
            cout << "impossible\n";
        }
    }

    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // cin.exceptions(cin.failbit);
    rep(i, -n, n + 1) {
        rep(j, -n, n + 1) {
            coords[val(i, j)] = mp(i, j);
        }
    }
    sieve();
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}