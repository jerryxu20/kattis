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
const int MAXN = 10001;
/*
For each sprinkler, we will consider all x coorindates it covers and then query for the top y coord at 
each of those x's, then we will iterate over goblins and remove them from a mp. 

Every gob will be considered at most once, and there are MR x coordinates we look at. 
*/

map<int, int> gob[MAXN];

int d2(int y, int yy, int x, int xx) {
    int dy = y - yy;
    int dx = x - xx;
    return dx * dx + dy * dy;
}

int solve(int tt) {
    int g; cin >> g;

    int x, y, r;
    rep(i, 0, g) {
        cin >> x >> y;
        gob[x][y]++;
    }
    int m; cin >> m;
    int ans = 0;
    rep(j, 0, m) {
        cin >> x >> y >> r;
        for (int i = max(0, x-r); i <= x+r; i++) {
            if (i >= MAXN) break;
            // cout << i << endl;
            int dx = i - x;
            int dy = sqrt(r * r - dx * dx);

            int upper = y + dy;
            int lower = y - dy;

            auto it = gob[i].lower_bound(lower);
            vi remove;
            while(it != gob[i].end()) {
                auto [yy, cnt] = *it;
                // cout << i << " " << yy << " gob was covered by sprinkler " << j << endl;
                if (yy > upper) break;
                assert(d2(y, yy, x, i) <= r * r);
                ans += cnt;
                remove.pb(yy);
                it++;
            }

            for (int yy: remove) {
                gob[i].erase(yy);
            }
        }
    }
    cout << g - ans << nl;


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