#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
vector<vector<int>> canstep;
vector<vector<int>> id;
vector<vector<int>> q;

struct UF {
    vector<int> rank, id;
    UF(int n) {
        rank.resize(n, 1);
        id.resize(n);
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
        rank[a] += rank[b];
        id[b] = a;
    }
};

int n, m;
bool valid(int x) {
    int N = 0;
    for (int i = 0; i + x <= n; i++) {
        for (int j = 0; j + x <= m; j++) {
            int ii = i + x - 1;
            int jj = j + x - 1;

            int cnt = grid[ii][jj];
            if (i > 0) cnt -= grid[i - 1][jj];
            if (j > 0) cnt -= grid[ii][j - 1];
            if (i > 0 && j > 0) cnt += grid[i - 1][j - 1];

            if (cnt == 0) {
                canstep[i][j] = x;
                id[i][j] = N++;
            } 
        }
    }

    UF uf(N);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (canstep[i][j] != x) continue;
            if (i + 1 < n && canstep[i + 1][j] == x) {
                uf.join(id[i][j], id[i + 1][j]);
            }
            if (j + 1 < m && canstep[i][j + 1] == x) {
                uf.join(id[i][j], id[i][j + 1]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (uf.find(i) != uf.find(0)) return false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            q[i][j] = 0;
            if (canstep[i][j] == x) q[i][j]++;
            if (i > 0) q[i][j] += q[i - 1][j];
            if (j > 0) q[i][j] += q[i][j - 1];
            if (i > 0 && j > 0) q[i][j] -= q[i - 1][j - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int obs = grid[i][j];
            if (i > 0) obs -= grid[i - 1][j];
            if (j > 0) obs -= grid[i][j - 1];
            if (i > 0 && j > 0) obs += grid[i - 1][j - 1];            
            if (obs) continue;

            int ii = i - x + 1;
            int jj = j - x + 1;
            ii = max(ii, 0);
            jj = max(jj, 0);

            int cov = q[i][j];
            if (ii > 0) cov -= q[ii - 1][j];
            if (jj > 0) cov -= q[i][jj - 1];
            if (ii > 0 && jj > 0) cov += q[ii - 1][jj - 1];

            if (cov == 0) return false;
        }
    }

    return true;
}

int main() {
    int k; cin >> n >> m >> k;

    grid.resize(n, vector<int>(m));
    canstep.resize(n, vector<int>(m));
    id.resize(n, vector<int>(m));
    q.resize(n, vector<int>(m));

    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        grid[x][y]++;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0) grid[i][j] += grid[i - 1][j];
            if (j > 0) grid[i][j] += grid[i][j - 1];
            if (i > 0 && j > 0) grid[i][j] -= grid[i - 1][j - 1];
        }
    }

    int low = 1;
    int high = 1e6;
    int ans = -1;
    while(low <= high) {
        int mid = (low + high)/2;
        if (valid(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;
}