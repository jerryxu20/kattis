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
const int MX = 3601;
int solve(int tt) {
    int n, t;
    cin >> n >> t;
    vi button(n);
    trav(b, button) cin >> b;
    queue<int> q;
    q.push(0);

    vi dis(MX, -1);
    dis[0] = 0;

    while(sz(q)) {
        int s = sz(q);
        while(s--) {
            auto node = q.front();
            q.pop();
            trav(b, button) {
                int nxt = b + node;
                nxt = min(3600, nxt);
                nxt = max(0, nxt);
                if (dis[nxt] != -1) continue;
                dis[nxt] = dis[node] + 1;
                q.push(nxt);
            }
        }
    }
    rep(i, t, MX) {
        if (dis[i] == -1) continue;
        cout << dis[i] << " " << i - t << nl;
        break;
    }

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