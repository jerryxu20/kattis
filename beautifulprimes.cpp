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
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const int MOD = 1000000007;
const char nl = '\n';

vii seq(10);
int N;

void factor(int a, vi &ans) {
    int div = 2;
    while(div * div <= a) {
        while (a % div == 0) {
            a/=div;
            ans.pb(div);
        }
        div++;
    }
    if (a > 1) ans.pb(a);
    return;
}

vi help(int power) {
    if (sz(seq[power]) > 0) return seq[power];
    vi ans;
    for (int i = pow(10, power) - 1; i >= 0; i--) {
        ans.clear();
        factor(i, ans);
        if (sz(ans) == power) {
            seq[power] = ans;
            break;
        }
    }
    return seq[power];
}



int solve(int tt) {
    cin >> N;
    vi ans;
    for (int power = 9; power >= 1; power--) {
        while (N - power >= 0) {
            vi primes = help(power);
            ans.insert(ans.end(), all(primes));
            N -= power;
        }
    }
    trav(a, ans) {
        cout << a << " ";
    }
    cout << nl;
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