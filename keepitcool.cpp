#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, s, d;
    cin >> n >> m >> s >> d;


    vector<int> space(s);
    for (int &x: space) {
        cin >> x;
        x = d - x;
    }

    
    vector<int> idx(s);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (auto &a, auto &b) {
        return space[a] > space[b];
    });

    vector<int> ans(s);
    for (int i: idx) {
        int cap = min(space[i], n);
        ans[i] = cap;
        n -= cap;
    }

    int cold = 0;

    for (int i = 0; i < s; i++) {
        if (ans[i]) continue;
        cold += d - space[i];
    }

    if (cold < m) {
        cout << "impossible\n";
    } else {
        for (int &x: ans) {
            cout << x << " ";
        }
        cout << "\n";
    }

}