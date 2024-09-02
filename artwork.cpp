#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MAXQ = 1e4 + 1;
const int MAXN = 1000;
vector<pi> changed[MAXQ];

vector<pi> vstroke[MAXN][MAXN];
vector<pi> hstroke[MAXN][MAXN];

vector<pair<int, int>> delta = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct UF {
    vector<int> rank, id;
    int N = 0;
    UF(int n): N(n), rank(n, 1), id(n) {
        iota(id.begin(), id.end(), 0);
    }

    int find(int a) {
        if (id[a] == a) return a;
        id[a] = find(id[a]);
        return id[a];
    }

    void join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank[b] > rank[a]) swap(a, b);
        id[b] = a;
        rank[a] += rank[b];
        N--;
    }

    int comps() {
        return N;
    }
};


int main() {
    int n, m, q; cin >> n >> m >> q;

    vector<vector<int>> filled(n, vector<int>(m, q));
    for (int i = 0; i < q; i++) {
        pi a, b;
        cin >> a.first >> a.second >> b.first >> b.second;
        a.first--; a.second--;
        b.first--; b.second--;
        // horizontal stroke
        if (a.first == b.first) {
            hstroke[a.first][a.second].push_back({i, b.second});
        } else {
            vstroke[a.first][a.second].push_back({i, b.first});
        }
    }

    for (int i = 0; i < n; i++) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for (int j = 0; j < m; j++) {
            for (auto &p: hstroke[i][j]) {
                pq.push(p);
            }

            while(pq.size() && pq.top().second < j) pq.pop();
            if (pq.size()) {
                filled[i][j] = min(filled[i][j], pq.top().first);
            }
        }
    }
    
    for (int j = 0; j < m; j++) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for (int i = 0; i < n; i++) {
            for (auto &p: vstroke[i][j]) {
                pq.push(p);
            }

            while(pq.size() && pq.top().second < i) pq.pop();
            if (pq.size()) {
                filled[i][j] = min(filled[i][j], pq.top().first);
            }
        }
    }

    int covered = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (filled[i][j] < q) covered++;
            changed[filled[i][j]].push_back({i, j});
        }
    }
    
    vector<int> ans(q);

    auto id = [&] (int i, int j) {
        return i * m + j;
    };

    UF uf(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (filled[i][j] == q) {
            for (auto &[a, b]: delta) {
                int ii = i + a;
                int jj = j + b;
                if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
                if (filled[ii][jj] != q) continue;

                uf.join(id(i, j), id(ii, jj));
            }
        }
    }    

    for (int t = q - 1; t >= 0; t--) {
        ans[t] = uf.comps() - covered;
        for (auto &[i, j]: changed[t]) {
            covered--;
            for (auto &[a, b]: delta) {
                int ii = i + a;
                int jj = j + b;

                if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
                if (filled[ii][jj] < t) continue;

                uf.join(id(i, j), id(ii, jj));
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
}