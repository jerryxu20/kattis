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
const int MAXN = 1e5;
vi adj[MAXN];
// # of nodes, total time, answer for subtree
ll cnt[MAXN], sub[MAXN], ans[MAXN]; 

void dfs(int node) {
    // read citations
    sub[node] += 1;

    // answer starts with time to read itself
    ans[node] = sub[node];
    cnt[node] = 1;


    /*
        ans = (time to read itself) + (1 * sz(subtree)) + ans(children)

        We need to read ourself. We incur 1 cost for every node in the subtree (including node itself) 
        because we need to read citations first. 

        We include the borrowing time of all children by themselves. Then we have to extend the
        borrowing time of all children. 

        Whatever child we read first, all the nodes in the subtrees of other unread children and our node itself 
        incur the time to read that child. Imagine all our children are leafs. Then the best order to 
        read them is shortest first. This is because the cost is either a + (a + b) or b + (a + b). 

        Now if the children are not leafs, but there are only two of them with (cnt_a, t_a) and (cnt_b, t_b),
        then we either incur cnt_a * t_b or cnt_b * t_a and there is a greedy choice that is best. 
        We can almost think of each node in the child's subtree as a seperate leaf node with cost t/cnt.      
    */

    trav(nxt, adj[node]) {
        // do shortest first
        dfs(nxt);
        cnt[node] += cnt[nxt];
        sub[node] += sub[nxt];

        ans[node] += ans[nxt];
        ans[node] += cnt[nxt];
    }

    sort(all(adj[node]), [&] (auto &a, auto &b) {
        return sub[a] * cnt[b] < sub[b] * cnt[a];          
    });

    int nodes = cnt[node];
    trav(nxt, adj[node]) {
        nodes -= cnt[nxt];
        ans[node] += sub[nxt] * nodes; 
    }

    return;
}


int solve(int tt) {
    int n; cin >> n;

    rep(i, 0, n) {
        cin >> sub[i];
        int m; cin >> m;
        while(m--) {
            int x; cin >> x;
            x--;
            adj[i].pb(x);
        }
    }
    
    dfs(0);
    cout << ans[0] << endl;
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