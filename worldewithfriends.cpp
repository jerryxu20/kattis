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

map<char, int> atleast, atmost;
vector<set<char>> isnot(5);
set<char> doesnotcontain;
string ans = string(5, '-');

void process(string &guess, string &res) {
    map<char, int> cnt;
    map<char, int> contains;
    
    rep(i, 0, 5) {
        if (res[i] == 'G') {
            ans[i] = guess[i];
        } else {
            isnot[i].insert(guess[i]);
        }
        cnt[guess[i]]++;

        if (res[i] != '-') {
            contains[guess[i]]++;
        }
    }

    for (auto &[c, guessed]: cnt) {
        int has = contains[c];
        if (has < guessed) {
            atleast[c] = has;
            atmost[c] = has;
        } else {
            atleast[c] = max(atleast[c], has);
        }
    }

}

bool check(string &guess) {
    map<char, int> cnt;
    rep(i, 0, 5) {
        if (ans[i] != '-' && guess[i] != ans[i]) return false;
        if (isnot[i].count(guess[i])) return false;
        if (doesnotcontain.count(guess[i])) return false;
        cnt[guess[i]]++;
    }

    for (auto &[c, freq]: atleast) {
        if (cnt[c] < freq) return false;
    }
    for (auto &[c, freq]: atmost) {
        if (cnt[c] > freq) return false;
    }
    return true;
}

int solve(int tt) {
    int n, w;
    cin >> n >> w;

    string guess, res;
    while(n--) {
        cin >> guess >> res;
        process(guess, res);
    }

    while(w--) {
        cin >> guess;
        if (check(guess)) {
            cout << guess << nl;
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