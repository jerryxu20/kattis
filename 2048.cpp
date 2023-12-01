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

// [0, 1, 2, 3] -> [left, up, right, down]
void push(vi &nums, bool flip = false) {
    vi ans;
    if (flip) reverse(all(nums));
    rep(i, 1, sz(nums)) {
        if (nums[i] == nums[i - 1]) {
            nums[i - 1] += nums[i];
            nums[i] = 0;
        }
    }
    trav(num, nums) {
        if (num != 0) {
            ans.pb(num);
        }
    }
    while(sz(ans) < 4) ans.pb(0);
    nums = ans;
    if (flip) reverse(all(nums));
    return;
}

void movev(vii &grid, int dir) {
    rep(j, 0, 4) {
        vi nums;
        rep(i, 0, 4) {
            if (grid[i][j] != 0) nums.pb(grid[i][j]);
        }
        push(nums, dir == 3);
        rep(i, 0, 4) {
            grid[i][j] = nums[i];
        }
    }
    return;
}


void moveh(vii &grid, int dir) {
    trav(row, grid) {
        vi nums;
        trav(cell, row) {
            if (cell != 0) nums.pb(cell);
        }
        push(nums, dir == 2);
        rep(i, 0, 4) {
            row[i] = nums[i];
        }
    }
    return;
}

int solve(int tt) {
    vii grid(4, vi(4));
    trav(row, grid) {
        trav(cell, row) cin >> cell;
    }

    int dir; cin >> dir;
    if (dir == 1 || dir == 3) {
        movev(grid, dir);
    } else {
        moveh(grid, dir);
    }
    trav(row, grid) {
        trav(cell, row) {
            cout << cell << " "; 
        }
        cout << nl;
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