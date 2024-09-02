#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200;
int ID[MAXN][MAXN];

int N = 0;
int id(int i, int j) {
    if (ID[i][j] == 0) {
        ID[i][j] = ++N;
    }
    return ID[i][j];
}

pair<int, int> delta(char c) {
    if (c == 'N') return {-1, 0};
    if (c == 'S') return {1, 0};
    if (c == 'W') return {0, 1};
    if (c == 'E') return {0, -1};
    assert(false);
    return {0, 0};
}

vector<int> adj[MAXN];

int main() {
    int n; cin >> n;


    int s = 1;

    vector<int> targs;
    while(n--) {
        int x = 100, y = 100;
        int m; cin >> m;
        memset(ID, 0, sizeof(ID));
        for (int i = 0; i < MAXN; i++) adj[i].clear();

        N = 0;
        id(x, y);
        

        while(m--) {
            char c; cin >> c;
            auto [a, b] = delta(c);

            adj[id(x, y)].push_back(id(x + a, y + b));
            adj[id(x + a, y + b)].push_back(id(x, y));

            x += a;
            y += b;
        }

        int t = id(x, y);
        vector<int> seen(N + 1);
        seen[s] = 1;

        queue<int> q;
        q.push(s);

        while(true) {
            int z = q.size();
            if (z == 0) break;
            while(z--) {
                auto node = q.front();
                q.pop();

                for (auto &nxt: adj[node]) if (!seen[nxt]) {
                    seen[nxt] = seen[node] + 1;
                    q.push(nxt);
                }
            }
        }
        cout << seen[t] - 1 << "\n";
    }

   


}