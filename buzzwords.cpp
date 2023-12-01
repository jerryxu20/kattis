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

vector<vector<int>> nxt(1, vi(26));
vector<int> cnt(1);
int N = 0;
int solve(string s) {
    int n = sz(s);
    vi ans(n + 1);
    cnt.assign(sz(nxt), 0);
    rep(i, 0, sz(s)) {
        int len = 1;
        int node = 0;
        rep(j, i, n) {
            int idx = s[j] - 'A';
            if (nxt[node][idx] == 0) {
                nxt.pb(vi(26));
                nxt[node][idx] = ++N;
                cnt.pb(0);
            }
            node = nxt[node][idx];
            cnt[node]++;
            ans[len] = max(ans[len], cnt[node]);
            len++;
        }
    }
    trav(a, ans) {
        if (a == 0) continue;
        if (a == 1) break;
        cout << a << endl;
    }
    cout << endl;
    return 0;
}

string strip(string &s) {
    string ans = "";
    trav(c, s) {
        if (c == ' ') continue;
        ans += c;
    }
    return ans;
}

int main() {
    string s;
    while(getline(cin, s)) {
        solve(strip(s));
    }

    return 0;
}