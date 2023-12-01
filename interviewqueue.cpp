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
    int n; cin >> n;
    vi val(n);
    trav(v, val) cin >> v;

    vi to_right(n);
    vi to_left(n);
    iota(all(to_right), 1);
    iota(all(to_left), -1);

    PQG<pi> pq;
    vector<vi> ans;
    vector<int> seen(n);

    rep(i, 0, n) {
        bool small = false;
        if (i > 0 && val[i - 1] > val[i]) small = true;
        if (i + 1 < n && val[i] < val[i + 1]) small = true;
        if (small) {
            pq.push({0, i});
            seen[i] = 1;
        }
    }

    int run = 1;
    while(true) {
        int s = sz(pq);
        if (s == 0) break;
        vi cur;
        while(s--) {
            auto [_, node] = pq.top();
            pq.pop();
            cur.pb(val[node]);
            int l = to_left[node];
            int r = to_right[node];

            if (l != -1) to_right[l] = r;
            if (r != n) to_left[r] = l;

            if (l == -1 || r == n) continue;


            if (val[l] == val[r]) continue;
            if (val[l] < val[r]) swap(l, r);

            // r is leaving
            if (seen[r] == 0) {
                seen[r] = 1;
                pq.push({run, r});
            } 
        }
        ans.pb(cur);
        run++;
    }
    cout << sz(ans) << nl;
    trav(row, ans) {
        trav(a, row) {
            cout << a << " ";
        }
        cout << nl;
    }
    rep(i, 0, n) {
        if (seen[i] == 0) {
            cout << val[i] << " ";
        }
    }
    cout << nl;

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