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

int solve(int tt) {
    int n, k; cin >> n >> k;
    
    vi nums(n), last(k + 1);
    trav(num, nums) cin >> num;
    
    rep(i, 0, n) {
        last[nums[i]] = i;
    }

    vi ans, in_stack(k + 1);
    deque<int> stack;
    rep(i, 0, n) {
        // already took this number
        if (last[nums[i]] == -1) continue;

        if (!in_stack[nums[i]]) {
            while(sz(stack) && stack.back() > nums[i]) {
                in_stack[stack.back()] = 0;
                stack.pop_back();
            } 
            stack.pb(nums[i]);
            in_stack[nums[i]] = 1;
        }

        if (last[nums[i]] != i) continue;            
        while(sz(stack) && stack.front() <= nums[i]) {
            ans.pb(stack.front());
            last[stack.front()] = -1;
            stack.pop_front();
        }

    }

    assert(sz(ans) == k);
    assert(sz(set<int>(all(ans))) == k);
    trav(a, ans) {
        cout << a << " ";
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