#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
const int MAXN = 5000;
pi X[MAXN], Y[MAXN];
vector<int> adj[MAXN], order;
int seen[MAXN];

double calc(int i, int x) {

    auto [x1, x2] = X[i];
    auto [y1, y2] = Y[i];

    if (x == x1) return y1;
    if (x == x2) return y2;
    
    if (x1 == x2) return y2;
    if (y1 == y2) return y2;


    double c = (double)(x-x1)/(x2 - x1);

    double dy = (y2 - y1) * c;
    return y1 + dy;
}

bool above(int i, int j) {
    int left = max(X[i].first, X[j].first);
    int right = min(X[i].second, X[j].second);


    if (left > right) return false;

    double mxi = max(calc(i, left), calc(i, right));
    double mxj = max(calc(j, left), calc(j, right));
    return mxi > mxj;
}

void dfs(int node) {
    seen[node] = 1;
    for (auto &nxt: adj[node]) {
        assert(seen[nxt] != 1);
        if (seen[nxt] == 0) dfs(nxt);
    }
    seen[node] = 2;
    order.push_back(node);
}

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> X[i].first >> Y[i].first;
        cin >> X[i].second >> Y[i].second;


        if (X[i].first > X[i].second) {
            swap(X[i].first, X[i].second);
            swap(Y[i].first, Y[i].second);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (i != j) {
            if (above(i, j)) {
                adj[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++) if (seen[i] == 0) {
        dfs(i);
    }

    for (int &i: order) {
        cout << i + 1 << " ";
    }
    cout << endl;
    
}