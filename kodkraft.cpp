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

int solve(int tt) {
    int n, K, c;
    cin >> n >> K;
    vector<vpl> contests(K);
    rep(i, 0, n) {
        cin >> c;
        contests[c - 1].pb({i, 1});
    }
    FORd(i, 0, K - 1) {
        vpl &nxt = contests[i + 1];
        vpl &cur = contests[i];
        int j = sz(nxt) - 1;
        int k = sz(cur) - 1;

        while(k >= 0 && cur[k].first > nxt[j].first) {
            cur[k].second += (n - 1 - cur[k].first) + nxt[0].second + nxt[0].first;
            // cout << "wraparound\n";
            // cout << cur[k].first << " " << cur[k].second  << endl;
            k--;  
        }

        while(k >= 0 && j >= 0) {
            while(j > 0 && cur[k].first < nxt[j - 1].first) {
                j--;
            }
            cur[k].second += nxt[j].second + (nxt[j].first - cur[k].first - 1); 
            // cout << cur[k].first << " " << cur[k].second  << endl;

            k--;
        }
    }

    ll ans = LLONG_MAX;
    for (auto &[idx, cost]: contests[0]) {
        ans = min(ans, cost);
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