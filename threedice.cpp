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

vi color(26);

bool check(vs &words) {
    for (auto &s: words) {
        int a = s[0] - 'a';
        int b = s[1] - 'a';
        int c = s[2] - 'a';
        if (color[a] == color[b] || color[b] == color[c] || color[a] == color[c]) return false; 
    }
    return true;
}

bool backtrack(int idx, int a, int b, int c, vector<char> &arr, vs &words) {
    if (idx == sz(arr)) {
        return check(words);
    }
    if (a < 6) {
        color[arr[idx] - 'a'] = 1;
        if (backtrack(idx + 1, a + 1, b, c, arr, words)) return true;
    }
    if (b < 6) {
        color[arr[idx] - 'a'] = 2;
        if (backtrack(idx + 1, a, b + 1, c, arr, words)) return true;
    }
    if (c < 6) {
        color[arr[idx] - 'a'] = 3;
        if (backtrack(idx + 1, a, b, c + 1, arr, words)) return true;
    }
    return false;
}

int solve(int tt) {
    int n; cin >> n;
    vs words(n);
    set<char> st;
    trav(s, words) {
        cin >> s;
        if (s[0] == s[1] || s[1] == s[2] || s[0] == s[2]) {
            cout << 0 << endl;
            return 0;
        }
        trav(c, s) st.insert(c);
    }

    vector<char> arr(all(st));
    if (sz(arr) > 18) {
        cout << 0 << endl;
        return 0;
    }
    vi group(sz(arr));
    if (!backtrack(0, 0, 0, 0, arr, words)) {
        cout << 0 << endl;
        return 0;
    }

    vs ans(3);

    rep(i, 0, 26) {
        if (color[i] == 0) continue;
        ans[color[i] - 1].pb(char(i + int('a')));
    }

    trav(s, ans) {
        while(sz(s) < 6) {
            while(color.back() != 0) {
                color.pop_back();
            }

            s.pb(char(sz(color) - 1 + int('a')));
            color.pop_back();
        }
        cout << s << " ";
    }
    cout << endl;

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