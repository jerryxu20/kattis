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
const int MAXN = 800;
map<int, int> ID;

int n;
int N = 0;
int last[MAXN], arr[MAXN];
int dp[MAXN][MAXN][2];

int f(int i, int j, int painted) {
    if (i > j) return 0;

    int &ans = dp[i][j][painted];
    if (ans != -1) return ans;

    // new paint
    int cost = 1;
    if (arr[j] == 0 && painted == 0) cost = 0;
    ans = cost + f(i, j - 1, painted);

    // sharing paint
    rep(k, i, j) {
        if (arr[k] == arr[j]) {
            int left = f(i, k, painted);
            int right = f(k + 1, j - 1, arr[j] != 0);
            ans = min(ans, left + right);
        }
    }
    assert(ans <= (j - i + 1));
    return ans;
} 

int id(int a) {
    if (ID.count(a)) return ID[a];
    ID[a] = N++;
    return ID[a];
}

int help() {
    memset(dp, -1, sizeof(dp));

    vi seen(N, -1);
    rep(i, 0, n) {
        last[i] = seen[arr[i]];
        seen[arr[i]] = i;
    }

    return f(0, n - 1, 0);
}


int solve(int tt) {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    id(0);

    rep(i, 0, n) {
        cin >> arr[i];
        arr[i] = id(arr[i]);
    }

    int a = help();
    reverse(arr, arr + n);
    int b = help();
    
    assert(a == b);
    cout << min(a, b) << endl;
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