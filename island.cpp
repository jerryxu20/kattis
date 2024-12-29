#include <bits/stdc++.h>
using namespace std;
vector<string> grid;
const char nl = '\n';
int T = 0;
struct UF {
    vector<int> id;
    UF (int n) {
        id.resize(n);
        iota(id.begin(), id.end(), 0);
    }
    int find(int a) {
        if (id[a] == a) return a;
        id[a] = find(id[a]);
        return id[a];
    } 
    bool join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        id[a] = b;
        return true;
    }
};

vector<pair<int, int>> delta = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int count_comps(string valid) {
    set<char> st(valid.begin(), valid.end());
    int n = grid.size();
    int m = grid[0].size();
    
    auto id = [&] (int i, int j) {
        return i * m + j;
    };

    UF uf(n * m);
    int comp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (st.count(grid[i][j])) comp++;
            for (auto &[a, b]: delta) {
                int ii = i + a;
                int jj = j + b;
                if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
                if (st.count(grid[i][j]) && st.count(grid[ii][jj])) {
                    if (uf.join(id(i, j), id(ii, jj))) comp--;
                }
            }
        }
    }
    return comp;
}

int bus(string valid = "XB") {
    set<char> st(valid.begin(), valid.end());
    int n = grid.size();
    int m = grid[0].size();
    
    auto id = [&] (int i, int j) {
        return i * m + j;
    };

    UF uf(n * m);
    int comp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (auto &[a, b]: delta) {
                int ii = i + a;
                int jj = j + b;
                if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
                if (st.count(grid[i][j]) && st.count(grid[ii][jj])) {
                    if (uf.join(id(i, j), id(ii, jj))) comp--;
                }
            }
        }
    }

    st.clear();
    st.insert('#');
    st.insert('X');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (auto &[a, b]: delta) {
                int ii = i + a;
                int jj = j + b;
                if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
                if (st.count(grid[i][j]) && st.count(grid[ii][jj])) {
                    if (uf.join(id(i, j), id(ii, jj))) comp--;
                }
            }
        }
    }
    st.insert('B');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
           if (st.count(grid[i][j])) comp++;
        }
    }
    return comp;
}

void solve() {
    T++;
    int n = grid.size();
    int m = grid[0].size();

    int islands = count_comps("#X");
    int bridges = count_comps("B");
    int buses = bus();
    cout << "Map " << T << nl;
    cout << "islands: " << islands << nl;
    cout << "bridges: " << bridges << nl;
    cout << "buses needed: " << buses << nl;
    cout << nl;
}

int main() {
    string s;
    while(getline(cin, s)) {
        if (s.size() == 0) {
            solve();
            grid.clear();
        } else {
            grid.push_back(s);
        }
    }
    solve();
}