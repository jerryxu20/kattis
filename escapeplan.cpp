#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;

#define pb push_back
#define mp make_pair

bool find(int j, vector<vi>& g, vi& btoa, vi& vis) {
	if (btoa[j] == -1) return 1;
	vis[j] = 1; int di = btoa[j];
	for (int e : g[di])
		if (!vis[e] && find(e, g, btoa, vis)) {
			btoa[e] = di;
			return 1;
		}
	return 0;
}
int dfsMatching(vector<vi>& g, vi& btoa) {
	vi vis;
	rep(i,0,sz(g)) {
		vis.assign(sz(btoa), 0);
		for (int j : g[i])
			if (find(j, g, btoa, vis)) {
				btoa[j] = i;
				break;
			}
	}
	return sz(btoa) - (int)count(all(btoa), -1);
}

double dis(pdd &a, pdd &b) {
    double x = a.first - b.first;
    double y = a.second - b.second;
    return x * x + y * y;
}

int solve(int t) {
    int m, n;

    cin >> m;
    if (m == 0) return 1;
    vector<pdd> robots(m);
    for (auto &[x, y]: robots) cin >> x >> y;

    cin >> n;
    vector<pdd> holes(n);
    for (auto &[x, y]: holes) cin >> x >> y;

    vector<vector<vi>> adj(3, vector<vi>(n));
    vi distance = {50 * 50, 100 * 100, 200 * 200};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double d = dis(holes[i], robots[j]);
            for (int k = 0; k < 3; k++) {
                if (d <= (double) distance[k]) adj[k][i].push_back(j);
            }
        }
    }
    vi ans;
    for (auto &g: adj) {
        vi matches(m, -1);
        ans.pb(dfsMatching(g, matches));
    }
    cout << "Scenario " << t << "\n";
    cout << "In 5 seconds " << ans[0] << " robot(s) can escape\n";
    cout << "In 10 seconds " << ans[1] << " robot(s) can escape\n";
    cout << "In 20 seconds " << ans[2] << " robot(s) can escape\n\n";
    
    return 0;
}

int main() {
    for (int i = 1; ; i++) {
        if (solve(i)) break;
    }
    return 0;
}