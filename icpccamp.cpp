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
int n, p, q, s;

bool check(int diff, vi &A, vi &B) {

    map<int, int> cnt;
    for (int &x: B) cnt[-x]++;

    int ans = 0;
    for (int i = p - 1; i >= 0; i--) {
        int mx = min(A[i] + diff, s - A[i]);

        auto it = cnt.lower_bound(-mx);
        if (it == cnt.end()) continue;

        int sm = A[i] - it->first;
        int delta = abs(A[i] + it->first);
        if (sm <= s && delta <= diff) {
            ans++;
            it->second--;
            if (it->second == 0) {
                cnt.erase(it);
            }
        }
    }
    return ans >= n;

}


int solve(int tt) {
    cin >> n >> p >> q;
    cin >> s;

    vi A(p), B(q);
    for (int &x: A) cin >> x;
    for (int &x: B) cin >> x;

    sort(all(A));
    sort(all(B));

    int low = 0;
    int high = 1e9;
    int ans = -1;

    while(low <= high) {
        int mid = (low + high)/2;
        if (check(mid, A, B)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;

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