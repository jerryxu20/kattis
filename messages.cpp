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
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vi> vii;
typedef vector<vii> viii;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define rep(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const int MOD = 1000000007;
const char nl = '\n';

vector<bool> is_terminal = {false};
vii nxt(1, vi(26));
int N = 0;
int f(string &s) {
    // cout << "s " << s << nl;
    vector<int> dp(sz(s) + 1);
    for (int i = 0; i < sz(s); i++) {
        int node = 0;
        dp[i + 1] = max(dp[i + 1], dp[i]);
        for (int j = i; j < sz(s); j++) {
            int idx = s[j] - 'a';
            if (nxt[node][idx] == 0) break;
            node = nxt[node][idx];
            if (is_terminal[node]) {
                // cout << s.substr(i, j - i + 1) << " is terminal " << endl;
                dp[j + 1] = max(dp[j + 1], dp[i] + 1);
            }
        }
    }
    // cout <<"DP TABLE\n";
    // for (int i = 1; i <= sz(s); i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << nl;
    return *max_element(all(dp));
}

void add(string &s) {
    int node = 0;
    for (char &c: s) {
        int idx = c - 'a';
        if (nxt[node][idx] == 0) {
            nxt[node][idx] = ++N;
            nxt.pb(vi(26));
            is_terminal.pb(false);
        }
        node = nxt[node][idx];
    }
    is_terminal[node] = true;
}

int solve(int tt) {
    string s, cur;
    while(true) {
        cin >> s;
        if (s == "#") break;
        add(s);
    }

    while(true) {
        cin >> s;
        if (s == "#") break;
        cur += s;
        if (cur.back() == '|') {
            cur.pop_back();
            cout << f(cur) << endl;
            cur = "";
        }
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
