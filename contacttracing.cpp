#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef pair<int, int> pi;

const int MAXN = 20000;
int inf[MAXN];
vector<int> adj[MAXN];

int main() {
    int n, d; cin >> n >> d;

    int c; cin >> c;
    for (int i = 0; i < c; i++) {
        int x; cin >> x;
        x--;
        inf[x] = 1;
    }
    
    vector<pi> range(n);
    for (auto &[a, b]: range) cin >> a >> b;

    range.push_back({INT_MAX, INT_MAX});


    priority_queue<pi, vector<pi>, greater<pi>> pq;

    vector<int> idx(n + 1);
    iota(all(idx), 0);

    sort(all(idx), [&] (auto &a, auto &b) {
        return range[a] < range[b];
    });

    // when someone leaves add the edge


    set<int> active;
    for (int i: idx) {
        auto &[s, t] = range[i];

        while(sz(pq) && pq.top().first < s) {
            auto [_, u] = pq.top();
            pq.pop();
            active.erase(u);

            for (int v: active) {
                adj[u].push_back(v);
                adj[v].push_back(u);
                // cout << u + 1 << " " << v + 1 << endl;
            }
        }
        
        
        active.insert(i);
        pq.push({t, i});
    }


    queue<int> q;

    for (int i = 0; i < n; i++) if (inf[i]) q.push(i);

    while(d--) {
        int x = sz(q);
        if (x == 0) break;
        while(x--) {
            int node = q.front();
            q.pop();
            for (int &nxt: adj[node]) {
                if (inf[nxt]) continue;
                inf[nxt] = 1;
                q.push(nxt);
            }
        }
    }

    for (int i = 0; i < n; i++) if (inf[i]) cout << i + 1 << " ";
    cout << endl;
    




}