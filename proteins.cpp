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
const int MAXN = 1001;

// int dp[1001][1001];

int solve(int tt) {
    int m; cin >> m;
    string s; cin >> s;
    int n = sz(s);

    // dp[i][j][k]: min cost to get j matches using the first i letters, such that total length % 3 is k
    vector<vii> dp(n + 1, vii(n + 1, vi(3, INT_MAX)));
    dp[0][0][0] = 0;
    dp[0][0][1] = 1;
    dp[0][0][2] = 2;
    rep(i, 0, n + 1) {
        rep(j, 0, n + 1) {
            if (i == 0 && j == 0) continue;
            if (j == 0) {
                if (i % 3 == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = 1;
                    dp[i][j][2] = 2;
                } else if (i % 3 == 1) {
                    dp[i][j][1] = 0;
                    dp[i][j][2] = 1;
                    dp[i][j][0] = 2;
                } else {
                    dp[i][j][2] = 0;
                    dp[i][j][0] = 1;
                    dp[i][j][1] = 2;
                }
                continue;
            }
  
            dp[i][j][0] = dp[i][j - 1][0] + 3;
            dp[i][j][1] = dp[i][j - 1][1] + 3;
            dp[i][j][2] = dp[i][j - 1][2] + 3;
            if (i > 0) {
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][2]);
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][0]);
                dp[i][j][2] = min(dp[i][j][2], dp[i - 1][j][1]);
            }
            if (i - 1 >= 0) {
                if (s[i - 1] == 'A' || s[i - 1] == 'T' || s[i - 1] == 'G') {
                    dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j - 1][0] + 2);
                }
            }
            if (i - 2 >= 0) {
                string at = "";
                at += s[i - 2];
                at += s[i - 1];
                if (at == "AT" || at == "AG" || at == "TG") {
                    dp[i][j][0] = min(dp[i][j][0], dp[i - 2][j - 1][0] + 1);
                }
            }
            if (i - 3 >= 0) {
                if (s[i - 3] == 'A' && s[i - 2] == 'T' && s[i - 1] == 'G') {
                    dp[i][j][0] = min(dp[i][j][0], dp[i - 3][j - 1][0]);
                }
            }
            
            dp[i][j][1] = min(dp[i][j][1], dp[i][j][0] + 1);
            dp[i][j][2] = min(dp[i][j][2], dp[i][j][0] + 2);

        }
    }

    // rep(i, 0, n + 1) {
    //     rep(j, 0, min(n + 1, m + 1)) {
    //         cout << dp[i][j][0] << " ";
    //     }
    //     cout << endl;
    // }


    if (m <= n) {
        cout << *min_element(all(dp[n][m]))<< endl;
        return 0;
    } 
    cout << dp[n][n][0] + (m - n) * 3 << endl;

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