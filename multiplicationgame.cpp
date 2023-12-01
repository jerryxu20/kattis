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

int n;
string s;

vi factor(ll nn) {
    vi ans;
    ll div = 2;
    int run = 0;
    while(div * div <= nn) {
        while(nn % div == 0) {
            nn /= div;
            run++;
        }
        
        if (run > 0) {
            ans.pb(run);
            run = 0;
        }

        div++;
    }
    if (nn > 1) ans.pb(1);
    return ans;
}

string opposite() {
    if (s[0] == 'A') return "Bob";
    return "Alice";
}

    // can this player stop the other from winning?
bool ruin(vi &cnt, int player) {
    // player wants to decrement the smallest
    // (player + 1) % 2 wants to decrement the largest
    // sum of cnt is at most 31

    multiset<int> st(all(cnt));

    int total = accumulate(all(cnt), 0);
    int num;

    for (int turn = 0; ; turn = (turn + 1) % 2) {
        if (total == 0) break;
        if (turn == player) {
            auto it = st.begin(); 
            num = *it;
        } else {
            auto it = st.rbegin();
            num = *it;
        }
        if (num == 0) return true;

        st.erase(st.find(num));
        st.insert(num - 1);
        total--;
    }
    return false;
}

int solve(int tt) {
    cin >> n >> s;

    vi cnt = factor(n);

    int parity = accumulate(all(cnt), 0) % 2;

    // if number of factors is odd, second player needs to ruin
    // if number of factors is even, first player needs to ruin

    if (ruin(cnt, parity)) {
        cout << "tie\n";
    } else {
        cout << (parity ? s : opposite()) << nl; 
    }

    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}