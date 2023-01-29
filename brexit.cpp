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
    int C, P, X, L;
    // countries, number of edges, home country, first to leave;
    cin >> C >> P >> X >> L;
    vector<vector<int>> adj(C + 1);
    vector<int> p_count(C + 1);
    int a, b;
    while (P--) {
        cin >> a >> b;
        p_count[a]++;
        p_count[b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // Calc how many partners need to leave before country leaves
    for (int i = 1; i <= C; i++) {
        p_count[i] += p_count[i] % 2;
        p_count[i] /= 2;
    }
    queue<int> leaving;
    leaving.push(L);
    p_count[L] = -1;
    while (!leaving.empty()) {
        int node = leaving.front();
        if (node == X) {
            cout << "leave" << endl;
            return 0;
        }
        leaving.pop();
        for (int &partner: adj[node]) {
                if (--p_count[partner] == 0) {
                    leaving.push(partner);
                }
        }
    }
    cout << "stay" << endl;
    return 0;
}