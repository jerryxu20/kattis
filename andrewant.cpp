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
    int L, n;
    while(cin >> L >> n) {
        L *= 10;
        vpi ants(n);

        char c;
        vi heading_left, heading_right;
        for (auto &[pos, dir]: ants) {
            cin >> pos >> c;
            pos *= 10;
            if (c == 'R') {
                dir = 1;
            } else {
                dir = 0;
                heading_left.pb(pos);
            }
        }

        // ant {pos, dir}, dir == 1 is right, dir == 0 is left

        sort(all(ants));
        sort(all(heading_left), greater<int>());
        vector<int> dis;
        int mx = 0;

        for (auto &[pos, dir]: ants) {
            while (sz(heading_left) && heading_left.back() <= pos) {
                heading_left.pop_back();
            }

            int equal_collisions = min(sz(heading_left), sz(heading_right));
            int l_select = equal_collisions + (sz(heading_right) > equal_collisions && dir == 0);
            int r_select = equal_collisions + (sz(heading_left) > equal_collisions && dir == 1);


            int left_most = pos;
            int right_most = pos;

            if (l_select > 0) {
                left_most = heading_right[sz(heading_right) - l_select];
            }
            if (r_select > 0) {
                right_most = heading_left[sz(heading_left) - r_select];
            }

            int final_dir = 0;
            if (l_select == r_select) {
                final_dir = dir;
            } else {
                final_dir = (dir + 1) % 2;
            }

            int dleft = (pos - left_most)/2;
            int dright = (right_most - pos)/2;

            int final_pos = pos - dleft + dright;
            int distance = dleft + dright;

            if (final_dir == 1) {
                distance += L - final_pos;
            } else {
                distance += final_pos;
            }

            dis.pb(distance);
            mx = max(distance, mx);

            if (dir == 1) {
                heading_right.pb(pos);
            }
        }

        vector<int> ans;
        rep(i, 0, n) {
            if (dis[i] == mx) {
                ans.pb(ants[i].first/10);
            }
        }

        cout << "The last ant will fall down in " << mx/10 << " seconds - started at " << ans[0];

        rep(i, 1, sz(ans)) {
            cout << " and " << ans[i];
        }
        cout << "." << endl;
        
    }

    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // cin.exceptions(cin.failbit);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}