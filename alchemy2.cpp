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
int dp[101][101][2][2];
string s;
int dfs(int i, int j, int a, int b) {
    if (i >= j) return 0;

    int &ans = dp[i][j][a][b];
    if (ans != -1) return ans;

    ans = INT_MAX;


    // no matter what, we can use an operation on both ends
    ans = min(ans, 2 + dfs(i + 1, j - 1, 1, 1));

    // no operation on either end and the pair is already good
    if (s[i] == s[j] && !a && !b) {
        ans = min(ans, dfs(i + 1, j - 1, 0, 0));
    }

    // no matter what pair can change into a 
    // shared character
    if (a && b) {
        ans = min(ans, dfs(i + 1, j - 1, 0, 0));
    }

    // the pair can change into one of s[i] or s[j]
    if ((a || b) && s[i] != s[j]) {
        ans = min(ans, dfs(i + 1, j - 1, 0, 0));
    }

    // use an operation on left/right to take care of matching s[i] and s[j].
    // this is possible as long as they are not equal
    if (((a || b) && s[i] == s[j]) || (s[i] != s[j])) {
        ans = min(ans, 1 + dfs(i + 1, j - 1, 1, 0));
        ans = min(ans, 1 + dfs(i + 1, j - 1, 0, 1));
    }


    return ans;


}


int solve(int tt) {
    cin >> s;

    memset(dp, -1, sizeof(dp));

    /*
    
    dp[i][j][a][b]: min cost to make s[i..j] into a palindrome
    a, b is whether or not s[i] and s[j] can change. 
    */

   cout << dfs(0, sz(s) - 1, 0, 0) << endl;


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