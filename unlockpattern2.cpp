#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
int x[] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
int y[] = {2, 2, 2, 1, 1, 1, 0, 0, 0};

ll dp[1 << 9][9][9];
int at[][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
string s;

pi id(int num) {
    return {num/3, num % 3};
}

vector<pi> delta = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, 
                    {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
                    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

int cross(const pi& a, const pi& b) {
    return a.first * b.second - b.first * a.second;
}

pi skinny(const pi& a) {
    if (a.first == 0) return {0, a.second/abs(a.second)};
    if (a.second == 0) return {a.first/abs(a.first), 0};
    if (abs(a.first) == 2 && abs(a.second) == 2) {
        return {a.first/2, a.second/2};
    }
    return a;
}

// from a to b to c
char turn(int a, int b, int c) {
    pi ab = skinny({x[b] - x[a], y[b] - y[a]});
    pi bc = skinny({x[c] - x[b], y[c] - y[b]});

    if (ab == bc) return 'S';
    if (ab == pi(-bc.first, -bc.second)) return 'A';

    // i cross j is positive and left hand turn
    // ab cross bc
    int res = cross(ab, bc);
    assert(res != 0);

    if (res > 0) return 'L';
    return 'R';
}

vector<int> find(int num, int mask) {
    auto [i, j] = id(num);
    vector<int> ans;
    for (auto &[a, b]: delta) {
        int ii = i;
        int jj = j;
        while(true) {
            ii += a;
            jj += b;
            if (ii < 0 || jj < 0 || ii >= 3 || jj >= 3) break;

            int nxt = at[ii][jj];
            if (mask & (1 << nxt)) {
                ans.push_back(nxt);
                break;
            }
        }
       
    }
    return ans;
}

ll f(int mask, int cur, int last, int idx) {
    if (mask == 0) return 1;

    ll &ans = dp[mask][cur][last];
    if (ans != -1) return ans;

    ans = 0;
    vector<int> opt = find(cur, mask);
    char need = s[idx];
    for (int nxt: opt) {
        char c = turn(last, cur, nxt);
        if (need == '?' || need == c) {
            int nmask = mask ^ (1 << nxt);
            ans += f(nmask, nxt, cur, idx + 1);
        }
    }
    return ans;
}


int main() {
    cin >> s;
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    int all = (1 << 9) - 1;
    for (int i = 0; i < 9; i++) {
        vector<int> nxt = find(i, all);
        for (int j: nxt) {
            int mask = all ^ ((1 << i) | (1 << j));
            ans += f(mask, j, i, 0);
        }
    }
    cout << ans << endl;
}
