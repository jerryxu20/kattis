#include <bits/stdc++.h>
using namespace std;


const int B = 676;
vector<int> dp(1, 0);
vector<vector<int>> nxt(1, vector<int>(B));
int N = 0;

int main() {
    int n; cin >> n;

    vector<string> arr(n);
    for (auto &s: arr) cin >> s;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        string &s = arr[i];
        int node = 0;
        int cur = 0;
        int m = s.size();
        for (int j = 0; j < m; j++) {
            int a = s[j] - 'A';
            int b = s[m - 1 - j] - 'A';

            int idx = a + 26 * b;
            if (nxt[node][idx] == 0) {
                nxt.push_back(vector<int>(B));
                nxt[node][idx] = ++N;

                dp.push_back(0);
            }
            node = nxt[node][idx];
            cur = max(cur, dp[node]);
        }

        dp[node] = cur + 1;
        ans = max(ans, dp[node]);
    }
    
    cout << ans << endl;

}