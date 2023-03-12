#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair


int main() {
    int n;
    cin >> n;
    vector<vi> adj(n + 1);
    vector<pii> edges(n - 1);
    for (auto &[a, b]: edges) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<bool> seen(n + 1);
    vector<bool> color(n + 1);
    queue<int> q;
    q.push(1);
    seen[1] = true; 
    bool c = false;
    while(true) {
        int len = sz(q);
        if (len == 0) break;
        while(len--) {
            auto a = q.front();
            q.pop();
            for (auto &nxt: adj[a]) {
                if (seen[nxt]) continue;
                color[nxt] = !c;
                seen[nxt] = true;
                q.push(nxt);
            }
        }
        c = !c;
    }
    for (auto &[a, b]: edges) {
        cout << color[a] << endl;
    }
    return 0;
}