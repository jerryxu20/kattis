#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;

const int MAXM = 4100;
const int MAXN = 4100;
bitset<MAXM> st[4][MAXN];

int id(char &c) {
    return (c >> 1) & 3;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        for (int j = 0; j < m; j++) {
            int bits = id(s[j]);
            st[bits][i][j] = 1;
        }
    }

    bitset<MAXM> even_mask;
    for (int i = 0; i < MAXM; i += 2) even_mask[i] = 1;
    vector<int> pos(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = (st[0][i] & st[0][j]).count() + (st[1][i] & st[1][j]).count() + (st[2][i] & st[2][j]).count() + (st[3][i] & st[3][j]).count();
            if ((m - cnt) != k) {
                pos[i] = 0;
                pos[j] = 0;
            }
        }

        if (pos[i]) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}