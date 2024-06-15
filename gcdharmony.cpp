#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000;
const int MAXV = 10005;

typedef vector<int> vi;
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

int dp[MAXN][MAXV];
vector<int> adj[MAXN];
int val[MAXN];
int n;

int id[MAXV];
int best[MAXV];

void dfs(int node, int par = -1) {

    rep(i, 2, MAXV) {
        dp[node][i] = i;
    }
    dp[node][val[node]] = 0;


    for (auto &nxt: adj[node]) if (nxt != par) {
        dfs(nxt, node);
        rep(i, 2, MAXV) {
            int mn = 2 * n;
            for (int j = i; j < MAXV; j+= i) {
                mn = min(mn, dp[nxt][j]);
            }
            for (int j = i; j < MAXV; j += i) {
                if (id[j] != nxt) {
                    id[j] = nxt;
                    best[j] = mn;
                }
                best[j] = min(mn, best[j]);
            }
        }
        // add costs to us
        rep(i, 2, MAXV) {
            dp[node][i] += best[i];
        }

    }

    return;
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);
    int ans = 2 * n;
    rep(i, 2, MAXV) {
        ans = min(ans, dp[0][i]);
    }

    cout << ans << endl;
    
    return 0;
}