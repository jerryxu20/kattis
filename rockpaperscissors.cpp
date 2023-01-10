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
    map<char, char> rps;
    rps['r'] = 's';
    rps['s'] = 'p';
    rps['p'] = 'r';
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        int k;
        cin >> k;
        int games = k * n * (n - 1) / 2;
        vector<pair<int, int>> ans(n + 1);
        for (int i = 0; i < games; i++) {
            int a, b;
            string s1, s2;
            cin >> a >> s1 >> b >> s2;
            char one = s1[0];
            char two = s2[0];
            if (one == two) continue;
            if (rps[one] == two) {
                ans[a].first++;
                ans[b].second++;
            } else {
                ans[b].first++;
                ans[a].second++;
            }
        }
        for (int i = 1; i <= n; i++) {
            int bot = ans[i].first + ans[i].second;
            if (bot == 0) {
                printf("-\n");
                continue;
            }
            double w = ans[i].first / double(bot);
            w = round(w * 1000.0) / 1000.0;
            // double rounded = (int) (w * 1000.0) / 1000.0;
            printf("%.3f\n", w);
            // cout << w << endl;
        }
        printf("\n");
    }
    return 0;
}