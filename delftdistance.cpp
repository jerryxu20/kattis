#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef pair<long double, int> e;
const int MAXN = 3e6;
string grid[MAXN];

vector<pair<int, int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<pair<int, int>> cdelta = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
vector<e> adj[MAXN];

long double EPS = 1e-9;

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> grid[i];


    auto id = [&] (int i, int j) {
        return i * (2 * m + 1) + j;
    };

    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * m; j++) {
            if (i % 2 == 1 && j % 2 == 1) continue;
            for (auto &[a, b]: delta) {
                int ii = i + a;
                int jj = j + b;
                if (ii < 0 || jj < 0 || ii >= 2 * n + 1 || jj >= 2 * m + 1) continue;
                if (ii % 2 == 1 && jj % 2 == 1) continue;

                adj[id(i, j)].push_back({5, id(ii, jj)});
            }
        }
    }

    for (int i = 1; i <= 2 * n; i += 2) {
        for (int j = 1; j <= 2 * m; j += 2) if (grid[i/2][j/2] == 'O') {
            vector<int> coords;
            for (auto &[a, b]: delta) {
                int ii = i + a;
                int jj = j + b;
                coords.push_back(id(ii, jj));
            }

            for (int k = 0; k < 4; k++) {
                adj[coords[k]].push_back({M_PI * 2.5, coords[(k + 1) % 4]});
                adj[coords[k]].push_back({M_PI * 2.5, coords[(k - 1 + 4) % 4]});;
            }
        }
    }

    priority_queue<e, vector<e>, greater<e>> pq;
    pq.push({0, 0});

    int t = id(2*n, 2*m);
    vector<double> ans(t + 1, 1e9);
    ans[0] = 0;
    vector<int> done(t + 1);
    

    while(!pq.empty()) {
        auto [dis, node] = pq.top();
        pq.pop();
        if (node == t) {
            cout << setprecision(20) << fixed << dis << endl;
            return 0;
        }

        if (done[node]) continue;
        done[node] = 1;

        for (auto &[w, nxt]: adj[node]) {
            long double cand = w + dis;
            if (done[nxt]) continue;
            ans[nxt] = cand;
            pq.push({cand, nxt});
        }
    }

    assert(false);
}