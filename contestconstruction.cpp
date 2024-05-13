#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)

typedef long long ll;


const int MAXN = 55;

ll dp[MAXN][MAXN][MAXN][MAXN];
ll arr[MAXN];
int n, k;

// second prev, prev
ll f(int i, int cnt, int j, int k) {
    if (cnt == 0) return 1;
    if (i == n) return 0;

    if (k == -1) return f(i + 1, cnt - 1, k, i) + f(i + 1, cnt, j, k);
    if (j == -1) return f(i + 1, cnt - 1, k, i) + f(i + 1, cnt, j, k);

    ll sm = arr[j] + arr[k];

    ll &ans = dp[i][cnt][j][k];
    if (ans != -1) return ans;

    ans = f(i + 1, cnt, j, k);
    if (arr[i] <= sm) {
        ans += f(i + 1, cnt - 1, k, i);
    }
    return ans;
}

int main() {
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    rep(i, 0, n) cin >> arr[i];
    sort(arr, arr + n);

    cout << f(0, k, -1, -1) << endl;
}