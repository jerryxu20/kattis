#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int, int, int> tii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef vector<string> vs;

#define pb push_back
#define mp make_pair

// vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m, a, b, cost, k, q;
vector<tii> edges;
vector<int> dis;
void bellmanford(int s, int k) {
    // cout << s << " " << k << endl;
    dis.assign(n, INT_MAX);
    dis[s] = 0;
    for (int i = 0; i < k - 1; i++) {
        vi new_dis = dis;
        for (auto &[a, b, cost]: edges) {
            if (dis[a] == INT_MAX) continue;
            new_dis[b] = min(new_dis[b], dis[a] + cost);
        }
        dis = new_dis;
    }
    return;
}
int solve(int tcase) {
    cin >> n;
    edges.clear();
    for (int i = 0; i < n; i++) {
        cin >> m;
        while(m--) {
            cin >> b >> cost;
            edges.pb({i, b, cost});
        }
    }
    cin >> q;
    while(q--) {
        cin >> a >> b >> k;
        // cout << a << " " << b << " " << k << endl; 
        bellmanford(a, k);
        if (dis[b] == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << dis[b] << endl;
        }
    }
    cout << endl;
    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    testcase++;
    return 0;
}