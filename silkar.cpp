#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair


int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> grid (r, vector<char> (c));
    vector<vector<int>> flood_time (r, vector<int> (c, -1));
    queue<pair<int, int>> flood;
    queue<pair<int, int>> q;
    pair<int, int> end;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '*') {
                flood.push(mp(i, j));
                flood_time[i][j] = 0;
            } else if (grid[i][j] == 'S') {
                q.push(mp(i, j));
            } else if (grid[i][j] == 'D') {
                end = mp(i, j);
            }
        }
    }
    vector<vector<int>> delta = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int d = 0;
    while (true) {
        int sz = flood.size();
        if (sz == 0) break;
        while(sz--) {
            auto p = flood.front();
            flood.pop();
            for (auto &v: delta) {
                int i = p.first + v[0];
                int j = p.second + v[1];
                if (i < 0 || j < 0 || i >= r || j >= c) continue;
                if (flood_time[i][j] > -1) continue;
                if (grid[i][j] != '.') continue;
                flood_time[i][j] = d + 1;
                flood.push(mp(i, j));
            }
        }
        d++;
    }
    d = 0;
    int ans = -1;
    vector<vector<bool>> seen(r, vector<bool> (c));
    while (true) {
        int sz = q.size();
        if (sz == 0) break;
        while(sz--) {
            auto p = q.front();
            q.pop();
            if (p == end) {
                ans = d;
                break;
            }
            for (auto &v: delta) {
                int i = p.first + v[0];
                int j = p.second + v[1];
                if (i < 0 || j < 0 || i >= r || j >= c) continue;
                if (seen[i][j]) continue;
                if (flood_time[i][j] > 0 && flood_time[i][j] <= d + 1) continue;
                if (grid[i][j] == 'X') continue;
                q.push(mp(i, j));
                seen[i][j] = true;
            }
        }
        d++;
    }
    if (ans == -1) {
        cout << "KAKTUS\n";
        return 0;
    } 
    cout << ans << "\n";
    
    return 0;
}