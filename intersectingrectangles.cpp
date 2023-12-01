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

bool check(vector<pair<pi, pi>> &rects) {
    // time, index. negative index is insertion, pos index is removal
    PQG<pair<int, int>> pq;

    // 0, insert
    // 1, remove

    rep(i, 0, sz(rects)) {
        auto &[x, _] = rects[i];
        pq.push({x.first, -(i + 1)});
        pq.push({x.second, (i + 1)});
    }

    set<int> walls;

    while(sz(pq)) {
        auto [_, type] = pq.top();
        pq.pop();
        int idx = abs(type) - 1;
        auto &[__, y] = rects[idx];
        if (type < 0) {
            if (walls.count(y.first) || walls.count(y.second)) return false;
            walls.insert(y.first);
            walls.insert(y.second);
            auto it = walls.find(y.first);
            it++;
            if (*it != y.second) return false;
        } else {
            walls.erase(y.first);
            walls.erase(y.second);
        }
    }
    return true;
}

int solve(int tt) {
    int n; cin >> n;
    
    // (x1, x2), (y1, y2)
    vector<pair<pi, pi>> rects(n);
    for (auto &[x, y]: rects) {
        cin >> x.first >> y.first >> x.second >> y.second;
    }

    if (!check(rects)) {
        cout << 1 << nl;
        return 0;
    }
    
    for (auto &[x, y]: rects) {
        swap(x, y);
    }

    if (!check(rects)) {
        cout << 1 << nl;
        return 0;
    }
    cout << 0 << nl;
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